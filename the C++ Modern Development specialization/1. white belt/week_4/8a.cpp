#include <iostream>
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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }
    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }
    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << r.Numerator() << '/' <<  r.Denominator() << endl;
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }
    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }
    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }
    {
        const Rational r(-2, -3);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(-2, -3) != 2/3" << endl;
            return 4;
        }
    }
    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }
    cout << "OK" << endl;
    return 0;
}
