#pragma once

#ifndef DATE_H
#define DATE_H

#include <sstream>

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int year_, int month_, int day_): year(year_), month(month_), day(day_) {}
    // Date ParseDate(istringstream is);
    std::string get_date() const;
    Date& operator=(const Date& d);
    int year, month, day;
};

Date ParseDate(std::istream& is);
bool operator> (const Date& d1, const Date& d2);
bool operator< (const Date& d1, const Date& d2);
bool operator<= (const Date& d1, const Date& d2);
bool operator>= (const Date& d1, const Date& d2);
bool operator== (const Date& d1, const Date& d2);
bool operator!= (const Date& d1, const Date& d2);
std::ostream& operator<< (std::ostream& os, const Date& d);
std::ostream& operator<< (std::ostream& os, const std::pair<Date, std::string>& pair);


#endif