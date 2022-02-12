#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
#include <tuple>
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

#define SORT_BY(field)                                       \
    [](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
        return lhs.field < rhs.field;                        \
    }

/*
void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}
*/