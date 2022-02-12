#ifndef TEST_H
#define TEST_H
#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>

template <typename I, typename J>
void Assert(const I& first, const J& second, const std::string& comment) {
    if (first != second) {
        std::ostringstream os;
        os << "Assert fail " << first << " != " << second << ". Comment: " << comment << "\n";
        throw std::runtime_error(os.str());
    }
}

class Tests {
public:
    template <typename TestFunctionName>
    void Run_test(TestFunctionName f, const std::string& name) {
        ++all_tests;
        try {
            f();
            std::cerr << name << " OK\n";
        } catch (std::runtime_error& error) {
            ++test_failed;
            std::cerr << name << " failed. " << error.what();
        }
    }
    ~Tests() {
        if (test_failed) {
            std::cerr << test_failed << " of " << all_tests << " unit test/s are failed. Program terminated.\n";
        }
    }
private:
    int test_failed = 0;
    int all_tests = 0;
};

template <typename I, typename J>
std::ostream& operator << (std::ostream& os, const std::map<I, J>& m) {
    os << "[";
    bool f = true;
    for (const auto& i : m) {
        if (!f) {
            os << ", ";
        }
        f = false;
        os << i.first << ": {" << i.second << "}";
    }
    os << "]";
    return os;
}

template <typename I>
std::ostream& operator << (std::ostream& os, const std::set<I>& s) {
    os << "[";
    bool f = true;
    for (const auto& i : s) {
        if (!f) {
            os << ", ";
        }
        f = false;
        os << i;
    }
    os << "]";
    return os;
}

template <typename I>
std::ostream& operator << (std::ostream& os, const std::vector<I>& v) {
    os << "[";
    bool f = true;
    for (const auto& i : v) {
        if (!f) {
            os << ", ";
        }
        f = false;
        os << i;
    }
    os << "]";
    return os;
}

template <typename I>
std::ostream& operator << (std::ostream& os, const std::queue<I>& q) {
    os << "[";
    bool f = true;
    for (const auto& i : q) {
        if (!f) {
            os << ", ";
        }
        f = false;
        os << i;
    }
    os << "]";
    return os;
}

template <typename I>
std::ostream& operator << (std::ostream& os, const std::deque<I>& d) {
    os << "[";
    bool f = true;
    for (const auto& i : d) {
        if (!f) {
            os << ", ";
        }
        f = false;
        os << i;
    }
    os << "]";
    return os;
}

#endif