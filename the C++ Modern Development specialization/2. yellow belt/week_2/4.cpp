#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
  }

  ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void test() {
    /*const Rational i;
    AssertEqual(i.Numerator(), 0, "default constructer const numerator");
    AssertEqual(i.Denominator(), 1, "default constructer const denomerator");*/
    Rational j;
    AssertEqual(j.Numerator(), 0, "default constructer numerator");
    AssertEqual(j.Denominator(), 1, "default constructer denomerator");
    Rational i2(2, 4);
    AssertEqual(i2.Numerator(), 1, "default constructer numerator reduction");
    AssertEqual(i2.Denominator(), 2, "default constructer denomerator reduction");
    Rational i3(-2, 4);
    AssertEqual(i3.Numerator(), -1, "default constructer numerator reduction neg numerator");
    AssertEqual(i3.Denominator(), 2, "default constructer denomerator reduction neg numerator");
    Rational i4(2, -4);
    AssertEqual(i4.Numerator(), -1, "default constructer numerator reduction neg denomerator");
    AssertEqual(i4.Denominator(), 2, "default constructer denomerator reduction neg denomerator");
    Rational i5(-2, -4);
    AssertEqual(i5.Numerator(), 1, "negative numerator and denominator");
    AssertEqual(i5.Denominator(), 2, "negative numerator and denominator");
    Rational i6(0, -4);
    AssertEqual(i6.Numerator(), 0, "numerator = 0");
    AssertEqual(i6.Denominator(), 1, "numerator = 0");
    Rational i7(5, 5);
    AssertEqual(i7.Numerator(), 1, "numerator = denominator");
    AssertEqual(i7.Denominator(), 1, "numerator = denominator");
    Rational i8(5, -5);
    AssertEqual(i8.Numerator(), -1, "numerator = -denominator");
    AssertEqual(i8.Denominator(), 1, "numerator = -denominator");
    Rational i9(-5, -5);
    AssertEqual(i9.Numerator(), 1, "numerator = denominator");
    AssertEqual(i9.Denominator(), 1, "numerator = denominator");
    Rational i10(-5, 5);
    AssertEqual(i10.Numerator(), -1, "-numerator = -denominator");
    AssertEqual(i10.Denominator(), 1, "-numerator = -denominator");
}

int main() {
    TestRunner runner;
    runner.RunTest(test, "test");
    return 0;
}