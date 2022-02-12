#include "test_runner.h"
#include "profile.h"

#include <algorithm>
#include <future>
#include <map>
#include <vector>
#include <string>
#include <mutex>
#include <random>
using namespace std;

template <typename K, typename V>
void operator+=(map<K, V>& f, map<K, V>& s) {
    for (auto& [i, j]: s) {
        f[i] = j;
    }
}

template <typename K, typename V>
class ConcurrentMap {
public:
    static_assert(is_integral_v<K>, "ConcurrentMap supports only integer keys");

    struct Item {
        mutex m;
        map<K, V> map_;
    };
    struct Access {
        Access(Item& cm, K key): ref_to_value(cm.map_[key]), m(cm.m) {
            m.lock();
        }
        ~Access() {
            m.unlock();
        }
        mutex& m;
        V& ref_to_value;
    };

    explicit ConcurrentMap(size_t bucket_count): data(bucket_count) {
        if (data.size()) {
            id = 0;
        }
    }

    Access operator[](const K& key) {
        /*id %= data.size();
        for (int i = 0; i < data.size(); ++i) {
            for (auto& [first, sec]: data[i].second) {
                if (first == (key > 0 ? key : - key)) {
                    return Access(data[i], (key > 0 ? key : - key));
                }
            }

        }
        return Access(data[0], (key > 0 ? key : - key));*/
        return Access(data[(key > 0 ? key : - key) % data.size()], key);
    }

    map<K, V> BuildOrdinaryMap() {
        map<K, V> tmp;
        for (auto& [i, j]: data) {
            i.lock();
            tmp += j;
        }
        return tmp;
    }
private:
    int id;
    vector<Item> data;
};

void RunConcurrentUpdates(ConcurrentMap<int, int>& cm, size_t thread_count, int key_count) {
    auto kernel = [&cm, key_count](int seed) {
        vector<int> updates(key_count);
        iota(begin(updates), end(updates), -key_count / 2);
        shuffle(begin(updates), end(updates), default_random_engine(seed));

        for (int i = 0; i < 2; ++i) {
            for (auto key : updates) {
                cm[key].ref_to_value++;
            }
        }
    };

    vector<future<void>> futures;
    for (size_t i = 0; i < thread_count; ++i) {
        futures.push_back(async(kernel, i));
    }
}

void TestConcurrentUpdate() {
    const size_t thread_count = 2;
    const size_t key_count = 50000;

    ConcurrentMap<int, int> cm(thread_count);
    RunConcurrentUpdates(cm, thread_count, key_count);

    const auto result = cm.BuildOrdinaryMap();
    ASSERT_EQUAL(result.size(), key_count);
    for (auto& [k, v] : result) {
        AssertEqual(v, 4, "Key = " + to_string(k));
    }
}

void TestReadAndWrite() {
    ConcurrentMap<size_t, string> cm(5);

    auto updater = [&cm] {
        for (size_t i = 0; i < 50000; ++i) {
            cm[i].ref_to_value += 'a';
        }
    };
    auto reader = [&cm] {
        vector<string> result(50000);
        for (size_t i = 0; i < result.size(); ++i) {
            result[i] = cm[i].ref_to_value;
        }
        return result;
    };

    auto u1 = async(updater);
    auto r1 = async(reader);
    auto u2 = async(updater);
    auto r2 = async(reader);

    u1.get();
    u2.get();

    for (auto f : {&r1, &r2}) {
        auto result = f->get();
        ASSERT(all_of(result.begin(), result.end(), [](const string& s) {
            return s.empty() || s == "a" || s == "aa";
        }));
    }
}

void TestSpeedup() {
    {
        ConcurrentMap<int, int> single_lock(1);

        LOG_DURATION("Single lock");
        RunConcurrentUpdates(single_lock, 4, 50000);
    }
    {
        ConcurrentMap<int, int> many_locks(100);

        LOG_DURATION("100 locks");
        RunConcurrentUpdates(many_locks, 4, 50000);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestConcurrentUpdate);
    RUN_TEST(tr, TestReadAndWrite);
    RUN_TEST(tr, TestSpeedup);
}
