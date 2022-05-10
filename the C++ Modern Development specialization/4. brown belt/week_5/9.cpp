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

class BudgetManager {
public:
    void ComputeIncome(const Date& from, const Date& to) {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        auto it_begin = data.lower_bound(day_begin);
        auto it_end = data.upper_bound(day_end);
        long double income = 0;
        for (auto it = it_begin; it != it_end; ++it) {
            income += it->second;
        }
        cout << std::setprecision(25) << /*std::fixed << */income << "\n";
    }
    void Earn(const Date& from, const Date& to, int value) {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        long double value_to_add = static_cast<long double>(value) / ((static_cast<int64_t>(to.time_ - from.time_)/ (24 * 60 * 60)) + 1);
        for (int i = day_begin; i <= day_end; ++i) {
            data[i] += value_to_add;
        }
    }
    void PayTax(const Date& from, const Date& to) {
        int day_begin = ComputeDay(from, beg);
        int day_end = ComputeDay(to, beg);
        auto it_begin = data.lower_bound(day_begin);
        auto it_end = data.upper_bound(day_end);
        for (auto it = it_begin; it != it_end; ++it) {
            it->second *= 0.87;
        }
    }
    void print() {
        for (auto& [i, j] : data) {
            cout << i << " " << j << "\n";
        }
    }
private:
    map<int, long double> data;
    Date beg = Date("2000-01-00");
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    BudgetManager bm;
    int n;
    cin >> n;
    string command, from, to;
    int value;
    while (n--) {
        cin >> command >> from >> to;
        if (command == "ComputeIncome") {
            bm.ComputeIncome(from, to);
        } else if (command == "Earn") {
            cin >> value;
            bm.Earn(from, to, value);
        } else if (command == "print") {
            bm.print();
        } else {
            bm.PayTax(from, to);
        }
    }
}