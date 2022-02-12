#include "date.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

Date ParseDate(std::istream& is) {
    Date a;
    std::string year_, month_, day_;
    std::getline(is, year_, '-');
    a.year = atoi(year_.c_str());
    std::getline(is, month_, '-');
    a.month = atoi(month_.c_str());
    std::getline(is, day_, ' ');
    a.day = atoi(day_.c_str());
    //std::cout << a << "\n";
    return a;
}

std::string Date::get_date() const {
    std::ostringstream s;
    s << std::setw(4) << std::setfill('0') << year << "-" << std::setw(2) << std::setfill('0') << month << "-"
    << std::setw(2) << std::setfill('0') << day;
    return s.str();
}

Date& Date::operator=(const Date& d) {
    year = d.year;
    month = d.month;
    day = d.day;
    return *this;
}

std::ostream& operator<< (std::ostream& os, const Date& d) {
    os << std::setw(4) << std::setfill('0') << d.year << "-" << std::setw(2) << std::setfill('0') << d.month << "-"
    << std::setw(2) << std::setfill('0') << d.day;
    return os;
}

bool operator>(const Date& d1, const Date& d2) {
    if (d1.year != d2.year) {
        return d1.year > d2.year;
    } else if (d1.month != d2.month) {
        return d2.month < d1.month;
    } else {
        return d2.day < d1.day;
    }
}

bool operator<(const Date& d1, const Date& d2) {
    return d2 > d1;
}

bool operator>=(const Date& d1, const Date& d2) {
    if (d1.year != d2.year) {
        return d2.year < d1.year;
    } else if (d1.month != d2.month) {
        return d2.month < d1.month;
    } else {
        return d2.day <= d1.day;
    }
}

bool operator==(const Date& d1, const Date& d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator<=(const Date& d1, const Date& d2) {
    return d1 < d2 || d1 == d2;
}

bool operator!=(const Date& d1, const Date& d2) {
    return !(d1 == d2);
}

std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::string>& pair) {
    os << pair.first << " " << pair.second;
    return os;
}
