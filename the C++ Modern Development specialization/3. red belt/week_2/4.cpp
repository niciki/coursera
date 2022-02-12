#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include "profile.h"

using namespace std;

class ReadingManager {
public:
    void Read(int user_id, int page_count) {
        page_rating[page_count].insert(user_id);
        if (user_page.count(user_id)) {
            page_rating[user_page[user_id]].erase(user_id);
            user_page[user_id] = page_count;
        }
        user_page[user_id] = page_count;
    }
    double Cheer(int user_id) const {
        if (!user_page.count(user_id)) {
            return 0;
        }
        int user_count = user_page.size();
        if (user_count == 1) {
            return 1;
        }
        if (user_count > 1) {
            int position = 0;
            auto it = page_rating.lower_bound(user_page.at(user_id));
            if (it != page_rating.end()) {
                for (auto i = it; i != page_rating.end(); ++i) {
                    position += i->second.size();
                }
                return (user_count - position * 1.0) / (user_count - 1);
            }
        }
        return 0;
    }
private:
    map<int, set<int>> page_rating; // page -> set of users ids
    map<int, int> user_page; // user_id -> number of pages
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ReadingManager manager;
    int query_count;
    cin >> query_count;
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;
        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }
    return 0;
}