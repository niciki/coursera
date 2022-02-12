#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <ctime>
#include <algorithm>
#include <numeric>

using namespace std;

time_t make_time(string s) {
    tm time {};
    // tm time ;
    stringstream str(s);
    string tmp;
    getline(str, tmp, '-');
    time.tm_year = atoi(tmp.c_str()) - 1900;
    getline(str, tmp, '-');
    time.tm_mon = atoi(tmp.c_str()) - 1;
    getline(str, tmp, '-');
    time.tm_mday = atoi(tmp.c_str());
    // cout << time.tm_year  << " " << time.tm_mon << " " << time.tm_mday << "\n";
    time_t q = mktime(&time);
    return q;
}

int main() {
    int n1, n2, value;
    string d1, d2;
    cin >> n1;
    vector<pair<time_t, int>> data;
    for (int i = 0; i < n1; ++i) {
        cin >> d1 >> value;
        data.push_back({make_time(d1), value});
    }
    sort(data.begin(), data.end(), [](pair<time_t, int> p1, pair<time_t, int> p2){
        return p1.first < p2.first;
    });
    vector<int> res;
    res.push_back(data.front().second);
    for (int i = 1; i < data.size(); ++i) {
        res.push_back(res[i - 1] + data[i].second);
    }
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cin >> d1 >> d2;
        time_t t1 = make_time(d1);
        time_t t2 = make_time(d2);
        auto it_begin = find_if(data.begin(), data.end(), [t1](pair<time_t, int> p){
            return p.first <= t1;
        });
        auto it_end = find_if(data.begin(), data.end(), [t2](pair<time_t, int> p){
            return p.first >= t2;
        });
        /*for (auto i : res) {
            cout << i << " ";
        }*/
        if (it_end == data.end() && it_begin == data.end()) {
            if (t1 <= data.front().first && t2 >= data.back().first) {
                cout << res.back() << "\n";
            } else {
                cout << "0\n";
            }
        } else {
            if (it_end == data.end()) {
                if (it_begin - data.begin() - 1 < 0) {
                    cout << res.back() << "\n";
                } else {
                    cout << res.back() - res[it_begin - data.begin() - 1] << "\n";
                }
            } else if (it_begin == data.end()) {
                cout << res[it_end - data.begin()] << "\n";
            } else {
                // cout << it_end - data.begin() << " " << it_begin - data.begin() << "\n";
                if (it_begin - data.begin() - 1 < 0) {
                    if (it_end == data.end()) {
                        cout << res.back() << "\n";
                    } else {
                        cout << it_end - data.begin() << "\n";
                        cout << res[it_end - data.begin()] << "\n";
                    }
                } else {
                    if (it_end == data.end()) {
                        cout << res.back() - res[it_begin - data.begin() - 1] << "\n";
                    } else {
                        cout << res[it_end - data.begin()] - res[it_begin - data.begin() - 1] << "\n";
                    }
                }
            }
        }
    }
}