#include "database.h"

void Database::Add(const Date& d, const std::string& s){
    if (data_.count(d) && !data_set[d].count(s)) {
        data_[d].push_back(s);
        data_set[d].insert(s);
    } else if (!data_set[d].count(s)) {
        data_[d] = {s};
        data_set[d] = {s};
    }
}

void Database::Print(std::ostream& os) const {
    for (const auto& [i, j]: data_) {
        for (const auto& q: j) {
            os << i << " " << q << "\n";
        }
    }
}

/*
std::string Database::Last(const Date& d) {
    Date q;
    for (const auto& [i, j]: data) {
        if (q.year == 0 && q.month == 0 && q.year == 0) {
            q = i;
        } else if (i > q && d > i) {
            q = i;
        }
    }
    if (q.year == 0 && q.month == 0 && q.year == 0) {
        std::cout << "No entries\n";
    } else {
        int i = 0;
        for (const auto& j: data[q]) {
            ++i;
            if (i != data[q].size()) {
                std::cout << q << " " << j << "\n";
            } else {
                std::cout << q << " " << j;
            }
        }
    }
}*/

std::string Database::Last(const Date& d) const {
    auto i = data_.upper_bound(d);
    if (i == data_.begin()) {
        throw std::invalid_argument("There aren't elements");
    }
    return std::prev(i)->first.get_date() + " " + std::prev(i)->second.back();
    /*std::string s;
    Date d_;
    if (data_.size() && data_.begin()->first <= d) {
        for (const auto& i: data_) {
            std::set<std::string> res;
            for (const auto& j: i.second) {
                if (i.first <= d && !res.count(j)) {
                    res.insert(j);
                    d_ = i.first;
                    s = j;
                }
            }
        }
        if (d_ == Date()) {
            throw std::invalid_argument("error");
        } else {
            return d_.get_date() + " " + s;
        }
    } else {
        throw std::invalid_argument("error");
    }*/
}