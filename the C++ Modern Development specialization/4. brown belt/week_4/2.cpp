#include "Common.h"
#include <map>
#include <unordered_map>
#include <list>
#include <mutex>
#include <iostream>

using namespace std;

class LruCache : public ICache {
public:
    LruCache(
        shared_ptr<IBooksUnpacker> books_unpacker,
        const Settings& settings
    ): books_unpacker_(books_unpacker), max_size(settings.max_memory) {}

    BookPtr GetBook(const string& book_name) override {
        lock_guard<mutex> lg(m);
        if (data.count(book_name)) {
            auto book = data[book_name];
            book->second = ++cur_max;
            return book->first;
        } else {
            BookPtr book = books_unpacker_->UnpackBook(book_name);
            auto size_of_new_book = book->GetContent().size();
            if (size_of_new_book > max_size) {
                data.clear();
                cache_rating.clear();
                cur_max = 0;
                cur_size = 0;
                return book;
            } else if (size_of_new_book + cur_size > max_size) {
                while (size_of_new_book + cur_size > max_size) {
                    int min_rate = data.begin()->second->second;
                    auto it = data.begin();
                    for (auto i = data.begin(); i != data.end(); ++i) {
                        if (i->second->second < min_rate) {
                            it = i;
                            min_rate = i->second->second;
                        }
                    }
                    cur_size -= it->second->first->GetContent().size();
                    cache_rating.erase(it->second);
                    data.erase(it->first);
                }
                cur_size += book->GetContent().size();
                cache_rating.push_back({book, ++cur_max});
                auto it = prev(cache_rating.end());
                data.insert({book_name, it});
                return book;
            } else {
                cache_rating.push_back({book, ++cur_max});
                auto it = prev(cache_rating.end());
                cur_size += book->GetContent().size();
                data.insert({book_name, it});
                return book;
            }
        }
    }
    ~LruCache() {}
private:
    list<pair<shared_ptr<const IBook>, int>> cache_rating;
    unordered_map<string, list<pair<shared_ptr<const IBook>, int>>::iterator> data;
    shared_ptr<IBooksUnpacker> books_unpacker_;
    int cur_max = 0;
    int cur_size = 0;
    int max_size;
    mutex m;
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
) {
    return make_unique<LruCache>(books_unpacker, settings);
}
