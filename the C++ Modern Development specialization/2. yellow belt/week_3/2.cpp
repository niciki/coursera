#include "phone_number.h"
#include <stdexcept>
#include <cctype>

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

PhoneNumber::PhoneNumber(const string &international_number) {
    country_code_ = "";
    city_code_ = "";
    local_number_ = "";
    int i = 0;
    if (international_number[i] != '+') {
        throw std::invalid_argument("+");
    }
    ++i;
    while (international_number[i] != '-') {
        if (isdigit(international_number[i])) {
            country_code_ += international_number[i];
        } else if (international_number[i] != '-') {
            throw std::invalid_argument("1-");
        }
        if (i >= international_number.length()) {
            throw std::invalid_argument("1-");
        }
        ++i;
    }
    ++i;
    while (international_number[i] != '-') {
        if (isdigit(international_number[i])) {
            city_code_ += international_number[i];
        } else if (international_number[i] != '-') {
            throw std::invalid_argument("2-");
        }
        if (i >= international_number.length()) {
            throw std::invalid_argument("2-");
        }
        ++i;
    }
    ++i;
    if (city_code_ == "" || country_code_ == "") {
        throw std::invalid_argument("empty strings");
    }
    while (i < international_number.length()) {
        local_number_ += international_number[i];
        ++i;
    }
}