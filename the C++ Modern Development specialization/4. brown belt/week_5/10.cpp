#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Date {
    Date(const string& s) {
        int year = stoi(s.substr(0, 4));
        int month = stoi(s.substr(5, 2));
        int day = stoi(s.substr(8, 2));
        std::tm t;
        t.tm_sec = 0;
		t.tm_min = 0;
		t.tm_hour = 0;
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year = year - 1900;
		t.tm_isdst = 0;
        time_ = mktime(&t);
    }
    time_t time_;
};

int ComputeDay(const Date& d, const Date& beg) {
    return static_cast<int64_t>(d.time_ - beg.time_) / (24 * 60 * 60);
}

struct MoneyRecord {
    MoneyRecord(): gain(0.0), spend(0.0) {}
    long double gain;
    long double spend;
};

class BudgetManager {
public:
    void ComputeIncome(const Date& from, const Date& to) const {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        auto it_begin = data.lower_bound(day_begin);
        auto it_end = data.upper_bound(day_end);
        long double income = 0;
        for (auto it = it_begin; it != it_end; ++it) {
            income += it->second.gain - it->second.spend;
            // cout << income << ' ';
        }
        cout << std::setprecision(25) << /*std::fixed << */income << "\n";
    }
    void Earn(const Date& from, const Date& to, int value) {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        long double value_to_add = static_cast<long double>(value) / ((static_cast<int64_t>(to.time_ - from.time_)/ (24 * 60 * 60)) + 1);
        for (int i = day_begin; i <= day_end; ++i) {
            data[i].gain += value_to_add;
        }
    }
    void Spend(const Date& from, const Date& to, int spend) {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        long double value_to_spend = static_cast<long double>(spend) / ((static_cast<int64_t>(to.time_ - from.time_)/ (24 * 60 * 60)) + 1);
        for (int i = day_begin; i <= day_end; ++i) {
            data[i].spend += value_to_spend;
        }
    }
    void PayTax(const Date& from, const Date& to, int percent) {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        auto it_begin = data.lower_bound(day_begin);
        auto it_end = data.upper_bound(day_end);
        for (auto it = it_begin; it != it_end; ++it) {
            it->second.gain *= (1.0 - static_cast<long double>(percent) / 100);
        }
    }
    void Print() const {
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << it->first << " " << it->second.gain << " " << it->second.spend << endl;
        }
    }
private:
    map<int, MoneyRecord> data;
    Date beg = Date("2000-01-00");
};

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(nullptr);*/
    BudgetManager bm;
    int n;
    cin >> n;
    string command, from, to;
    int value, percent;
    while (n--) {
        cin >> command >> from >> to;
        if (command == "ComputeIncome") {
            bm.ComputeIncome(from, to);
        } else if (command == "Earn") {
            cin >> value;
            bm.Earn(from, to, value);
        } else if (command == "Print") {
            bm.Print();
        } else if (command == "Spend") {
            cin >> value;
            bm.Spend(from, to, value);
        } else {
            cin >> percent;
            bm.PayTax(from, to, percent);
        }
    }
}