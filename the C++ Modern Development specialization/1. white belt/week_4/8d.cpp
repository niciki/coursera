#include <iostream>
#include <sstream>
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
    int num = r.Numerator(), den = r.Denominator();
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
    /*while(is.peek() != '\n' || is.peek() != ' ' || is.peek() != EOF){
        is.ignore(1);
    }*/
    Rational a(num, den);
    r.SetNumerator(a.Numerator());
    r.SetDenominator(a.Denominator());
    return is;
}
/*
istream& operator>> (istream& is, Rational& r){
    int num = r.Numerator(), den = r.Denominator();
    char c;
    is >> num;
    is.ignore(1);
    is >> den;
    Rational a(num, den);
    r.SetNumerator(a.Numerator());
    r.SetDenominator(a.Denominator());
    return is;
}*/

ostream& operator<< (ostream& os, const Rational& r){
    os << r.Numerator() << '/' << r.Denominator();
    return os;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }
    {
        Rational r;
        while(cin >> r){
            cout << r << "\n";
        }
    }
    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);

        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
