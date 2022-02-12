#include "airline_ticket.h"
#include "test_runner.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool operator< (const Time& t1, const Time& t2) {
    return t1.hours * 60 + t1.minutes < t2.hours * 60 + t2.minutes;
}

bool operator== (const Time& t1, const Time& t2) {
    return t1.hours * 60 + t1.minutes == t2.hours * 60 + t2.minutes;
}

ostream& operator<< (ostream& os, const Time& t) {
    os << "{" << t.hours << ": " << t.minutes << "}";
    return os;
}

ostream& operator<< (ostream& os, const Date& d) {
    os << "{" << d.day << "." << d.month << "." << d.day << "}";
    return os;
}

bool operator== (const Date& d1, const Date& d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator< (const Date& d1, const Date& d2) {
    tuple<int, int, int> d_1 = make_tuple(d1.year, d1.month, d1.day);
    tuple<int, int, int> d_2 = make_tuple(d2.year, d2.month, d2.day);
    return d_1 < d_2;
}

istream& operator>> (istream& is, Date& d) {
    string year;
    getline(is, year, '-');
    d.year = stoi(year);
    string month;
    getline(is, month, '-');
    d.month = stoi(month);
    string day;
    getline(is, day);
    d.day = stoi(day);
    return is;
}

istream& operator>> (istream& is, Time& t) {
    string hour;
    getline(is, hour, ':');
    t.hours = stoi(hour);
    string minutes;
    getline(is, minutes);
    t.minutes = stoi(minutes);
    return is;
}

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time

#define UPDATE_FIELD(ticket, field, values)             \
    if (values.find(#field) != values.end()) {          \
        istringstream is(values.find(#field)->second);  \
        is >> ticket.field;                             \
    }

/*
void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
*/