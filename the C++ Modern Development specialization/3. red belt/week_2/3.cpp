#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

// #include "profile.h"

using namespace std;

class RouteManager {
public:
    void AddRoute(int start, int finish) {
        // LOG_DURATION("add");
        reachable_lists_[start].insert(finish);
        reachable_lists_[finish].insert(start);
    }
    int FindNearestFinish(int start, int finish) const {
        //LOG_DURATION("pap");
        int result = abs(start - finish);
        if (!reachable_lists_.count(start)) {
            return result;
        }
        const set<int>& reachable_stations = reachable_lists_.at(start);
        auto t = reachable_stations.lower_bound(finish);
        if (t == reachable_stations.end()) {
                return min(result, abs(finish - *prev(t)));
        } else if (t == reachable_stations.begin()) {
            return min(result, abs(finish - *t));
        } else {
            if (reachable_stations.size() > 1) {
                return min(result, min(abs(finish - *prev(t)), abs(finish - *t)));
            } else {
                return min(result, abs(finish - *t));
            }
        }
        return result;
    }
private:
    map<int, set<int>> reachable_lists_;
};


int main() {
    // LOG_DURATION("main");
    RouteManager routes;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }

    return 0;
}
