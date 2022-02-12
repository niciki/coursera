#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <ctime>

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

double income(const time_t& t1, const time_t& t2, vector<tuple<time_t, time_t, double>>& data) {
    double res = 0;
    for (const auto& i : data) {
        /*// t1 is smaller, than first element in tuple in vector and t2 is bigger
         if (get<0>(i) < t1 && get<1>(i) > t2) {
            res += get<2>(i) / (difftime(get<1>(i), get<0>(i)) / 3600 / 24) * (difftime(t2, t1) / 3600 / 24);
        } else if ()
        // cout << "t2: " << t2 << "get ... : " << get<0>(i) << "\n";
        cout << difftime(t2, get<0>(i)) / 3600 / 24 << "\n";
        if (difftime(t2, get<0>(i)) >= 0 || difftime(get<1>(i), t1) >= 0) {
            cout << "Znach: " << get<2>(i) / (difftime(get<1>(i), get<0>(i)) / 3600 / 24 + 1) << " Len: " << (difftime(min(t2, get<1>(i)), max(t1, get<0>(i))) / 3600 / 24 + 1) << "\n";
            res += get<2>(i) / (difftime(get<1>(i), get<0>(i)) / 3600 / 24 + 1) * (difftime(min(t2, get<1>(i)), max(t1, get<0>(i))) / 3600 / 24 + 1);
        }*/
        // cout << difftime(t2, get<0>(i)) / 3600 / 24 << "\n";

    /*
        // t1 is smaller, than first element in tuple in vector and t2 is bigger
        if (t1 <= get<0>(i) && t2 >= get<1>(i)) {
            res += get<2>(i);
        } else if ((t1 <= get<0>(i) && t2 <= get<0>(i)) || (t1 >= get<1>(i) && t2 >= get<1>(i))) { //t1 is smaller, than first element in tuple in vector and t2 is smaller
            ;
        } else if (t1 <= get<0>(i) && t2 <= get<1>(i)) {
            res += get<2>(i) / (difftime(get<1>(i), get<0>(i)) / 3600 / 24 + 1) * (difftime(min(t2, get<1>(i)), max(t1, get<0>(i))) / 3600 / 24 + 1);
        }
    */
        if ((t1 <= get<0>(i) && t2 <= get<0>(i)) || (t1 >= get<1>(i) && t2 >= get<1>(i))) { //t1 is smaller, than first element in tuple in vector and t2 is smaller
            ;
        } else if (t2 >= get<0>(i) || get<1>(i) >= t1) {
            // cout << "Znach: " << get<2>(i) / (difftime(get<1>(i), get<0>(i)) / 3600 / 24 + 1) << " Len: " << (difftime(min(t2, get<1>(i)), max(t1, get<0>(i))) / 3600 / 24 + 1) << "\n";
            res += get<2>(i) / (difftime(get<1>(i), get<0>(i)) / 3600 / 24 + 1) * (difftime(min(t2, get<1>(i)), max(t1, get<0>(i))) / 3600 / 24 + 1);
        }
    }
    return res;
}

int main() {
    time_t t;
    cout.precision(25);
    int n;
    cin >> n;
    string command;
    vector<tuple<time_t, time_t, double>> data;
    //cout << difftime(make_time("2001-01-01"), make_time("2000-01-02")) / 3600 / 24 << "\n";
    while (n--) {
        cin >> command;
        if (command == "Earn") {
            string date1, date2;
            double value;
            cin >> date1 >> date2 >> value;
            data.push_back({make_time(date1), make_time(date2), value});
        } else if (command == "ComputeIncome") {
            string date1, date2;
            cin >> date1 >> date2;
            time_t t1 = make_time(date1);
            time_t t2 = make_time(date2);
            cout << std::fixed << income(t1, t2, data) << "\n";
        }
    }
}