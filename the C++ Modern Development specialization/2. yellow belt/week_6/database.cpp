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


std::string Database::Last(const Date& d) const {
    auto i = data_.upper_bound(d);
    if (i == data_.begin()) {
        throw std::invalid_argument("There aren't elements");
    }
    return std::prev(i)->first.get_date() + " " + std::prev(i)->second.back();
}