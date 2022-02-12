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

void test () {
    Person q;
    AssertEqual(q.GetFullName(1921), "Incognito", "Incognito1");
    q.ChangeLastName(1922, "Shar");
    AssertEqual(q.GetFullName(1921), "Incognito", "Incognito2");
    AssertEqual(q.GetFullName(1922), "Shar with unknown first name", "Ln1");
    AssertEqual(q.GetFullName(1925), "Shar with unknown first name", "Ln2");
    AssertEqual(q.GetFullName(1921), "Incognito", "Incognito3");
    q.ChangeFirstName(1900, "Ann");
    AssertEqual(q.GetFullName(1899), "Incognito", "Incognito4");
    AssertEqual(q.GetFullName(1900), "Ann with unknown last name", "Fn1");
    AssertEqual(q.GetFullName(1905), "Ann with unknown last name", "Fn2");
    AssertEqual(q.GetFullName(1910), "Ann with unknown last name", "Fn3");
    AssertEqual(q.GetFullName(1922), "Ann Shar", "Fulln");
    q.ChangeFirstName(1899, "V");
    AssertEqual(q.GetFullName(1899), "V with unknown last name", "Fn4");
    AssertEqual(q.GetFullName(1900), "Ann with unknown last name", "Fn5");
    q.ChangeLastName(1897, "V");
    AssertEqual(q.GetFullName(1897), "V with unknown first name", "Ln3");
    AssertEqual(q.GetFullName(1900), "Ann V", "Ln4");
}

int main() {
    TestRunner runner;
    runner.RunTest(test, "test");
    return 0;
}
