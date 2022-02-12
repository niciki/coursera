#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include "date.h"

class Database {
public:
    void Add(const Date& d, const std::string& s);
    void Print(std::ostream& os) const;

    template<typename T>
    int RemoveIf(const T& predicate);

    template<typename T>
    std::vector<std::pair<Date, std::string>> FindIf(const T& predicate) const;

    std::string Last(const Date& d) const;
    std::map<Date, std::vector<std::string>> data_;
    std::map<Date, std::set<std::string>> data_set;
};

template<typename T>
int Database::RemoveIf(const T& predicate) {
    int cnt = 0;
    for (auto i = data_.begin(); i != data_.end();) {
        auto it = std::stable_partition(i->second.begin(), i->second.end(), [&](const auto& event){
            if (predicate(i->first, event) /*&& !res_.count({i->first, event})*/) {
                ++cnt;
                return false;
            }
            return true;
        });
        i->second.erase(it, i->second.end());
        if (!i->second.size()) {
            i = data_.erase(data_.find(i->first));
        } else {
            ++i;
        }
    }
    for (auto i = data_set.begin(); i != data_set.end();) {
        /*auto it = std::stable_partition(i->second.begin(), i->second.end(), [&](const auto& event){
            if (predicate(i->first, event) && !res_.count({i->first, event})) {
                return false;
            }
            return true;
        });*/
        std::set<std::string> true_;
        std::set<std::string> false_;
        auto it = std::partition_copy(i->second.begin(), i->second.end(), std::inserter(true_, true_.begin()), std::inserter(false_, false_.begin()), [&](const auto& event){
            if (predicate(i->first, event) /*&& !res_.count({i->first, event})*/) {
                return false;
            }
            return true;
        });
        i->second = true_;
        // std::cout << i->second.size();
        ++i;
        /*for (const auto& q: i->second) {
            std::cout << q << " ";
        }*/
    }
    return cnt;
}

template<typename T>
std::vector<std::pair<Date, std::string>> Database::FindIf(const T& predicate) const {
    std::vector<std::pair<Date, std::string>> res;
    for (const auto& i: data_) {
        auto it = std::find_if(i.second.begin(), i.second.end(), [&](const auto& event) {
            if (predicate(i.first, event)) {
                res.push_back({i.first, event});
            }
            return false;
        });
    }
    return res;
}

#endif
