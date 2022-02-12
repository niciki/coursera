#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;


int gcd(int a, int b){
    int tmp_1 = min(a, b);
    int tmp_2 = max(a, b);
    a = tmp_2;
    b = tmp_1;
    while(a % b){
        a -= b;
        tmp_1 = min(a, b);
        tmp_2 = max(a, b);
        a = tmp_2;
        b = tmp_1;
    }
    return b;
}

class Rational {
public:
    Rational(): numerator(0), denominator(1) {}
    Rational(int numerator, int denominator){
        if(numerator == 0){
            this->numerator = 0;
            this->denominator = 1;
            return;
        }
        if(numerator < 0 && denominator < 0){
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        if(gcd(abs(numerator), abs(denominator)) != 1){
            while(gcd(abs(numerator), abs(denominator)) != 1){
                int div = gcd(abs(numerator), abs(denominator));
                numerator /= div;
                denominator /= div;
            }
        }
        if(numerator < 0 || denominator < 0){
            this->numerator = -abs(numerator);
            this->denominator = abs(denominator);
            return;
        } else {
            this->numerator = numerator;
            this->denominator = denominator;
        }
    }
    void SetNumerator(int a){
        numerator = a;
    }
    void SetDenominator(int a){
        denominator = a;
    }
    int Numerator() const {
        return numerator;
    }
    int Denominator() const {
        return denominator;
    }
private:
    int numerator; // 
    int denominator;
};

bool operator==(const Rational& l, const Rational& r){
    return l.Denominator() == r.Denominator() && l.Numerator() == r.Numerator();
}

Rational operator+(const Rational& l, const Rational& r){
    int lcm = l.Denominator() * r.Denominator() / gcd(l.Denominator(), r.Denominator());
    return Rational(l.Numerator() * lcm / l.Denominator() + r.Numerator() * lcm / r.Denominator(), lcm);
}

Rational operator-(const Rational& l, const Rational& r){
    int lcm = l.Denominator() * r.Denominator() / gcd(l.Denominator(), r.Denominator());
    return Rational(l.Numerator() * lcm / l.Denominator() - r.Numerator() * lcm / r.Denominator(), lcm);
}

Rational operator*(const Rational& l, const Rational& r){
    return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/(const Rational& l, const Rational& r){
    return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

istream& operator>> (istream& is, Rational& r){
    int num, den;
    char c;
    if(!(is >> num)){
        return is;
    };
    is >> c;
    if(c != '/'){
        return is;
    } 
    if(!(is >> den)){
        return is;
    }
    is.ignore(1);
    Rational a(num, den);
    r.SetNumerator(a.Numerator());
    r.SetDenominator(a.Denominator());
    return is;
}

ostream& operator<< (ostream& os, const Rational& r){
    os << r.Numerator() << '/' << r.Denominator();
    return os;
}

bool operator< (const Rational& l, const Rational& r){
    return l.Numerator() * r.Denominator() < r.Numerator() * l.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
