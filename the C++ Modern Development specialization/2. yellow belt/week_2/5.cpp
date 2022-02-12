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
    AssertEqual(IsPalindrom(""), true, "empty string");
    AssertEqual(IsPalindrom("a"), true, "a");
    AssertEqual(IsPalindrom("   a   "), true, "   a   ");
    AssertEqual(IsPalindrom("   AZZA   "), true, "   AZZA   ");
    AssertEqual(IsPalindrom("a B a"), true, "a B a");
    AssertEqual(IsPalindrom("aba"), true, "aba");
    AssertEqual(IsPalindrom("aBa"), true, "aBa");
    AssertEqual(IsPalindrom("abba"), true, "abba");
    AssertEqual(IsPalindrom("abZba"), true, "abZba");
    AssertEqual(IsPalindrom("  aba"), false, "  aba");
    AssertEqual(IsPalindrom("aba  "), false, "aba  ");
    AssertEqual(IsPalindrom("  ABA"), false, "  ABA");
    AssertEqual(IsPalindrom("ABA  "), false, "ABA  ");
    AssertEqual(IsPalindrom("  ABBA"), false, "  ABBA");
    AssertEqual(IsPalindrom("ABBA  "), false, "ABBA  ");
    AssertEqual(IsPalindrom("  a b a  "), true, "  a b a  ");
    AssertEqual(IsPalindrom("  a b a  cv  a b a  "), false, "  a b a  cv  a b a  ");
    AssertEqual(IsPalindrom("  a b a  cc  a b a    a b a  cc  a b a  "), true, "  a b a  cc  a b a    a b a  cc  a b a  ");
    AssertEqual(IsPalindrom("  a b a cc  a b a    a b a  cc  a b a  "), false, "  a b a cc  a b a    a b a  cc  a b a  ");
    AssertEqual(IsPalindrom("  a b a  cc  a b a   a b a  cc  a b a  "), true, "  a b a  cc  a b a   a b a  cc  a b a  ");
    AssertEqual(IsPalindrom("  a b a  cc  a b a   a b a  cc  a b a c"), false, "  a b a  cc  a b a   a b a  cc  a b a c");
    AssertEqual(IsPalindrom("c  a b a  cc  a b a   a b a  cc  a b a  "), false, "c  a b a  cc  a b a   a b a  cc  a b a  ");
    AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "wasitacaroracatisaw");
    AssertEqual(IsPalindrom("wasitacaroracatisaa"), false, "wasitacaroracatisaa");
    AssertEqual(IsPalindrom("aasitacaroracatisaw"), false, "aasitacaroracatisaw");
    AssertEqual(IsPalindrom("sitacaroracatisawaa"), false, "sitacaroracatisawaa");
    AssertEqual(IsPalindrom("Aba"), false, "Aba");
    AssertEqual(IsPalindrom("Aaba"), false, "Aaba");
    AssertEqual(IsPalindrom("Aaaaa"), false, "Aaaaa");
    AssertEqual(IsPalindrom("aaaaA"), false, "aaaaA");
    AssertEqual(IsPalindrom("AabaB"), false, "AabaB");
    AssertEqual(IsPalindrom("AabzaB"), false, "AabzaB");
    AssertEqual(IsPalindrom("aXYa"), false, "aXYa");
    AssertEqual(IsPalindrom("was it a car or a cat i saw"), false, "was it a car or a cat i saw");
}

int main() {
    TestRunner runner;
    runner.RunTest(test, "test");
    return 0;
}