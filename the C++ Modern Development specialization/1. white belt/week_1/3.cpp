#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    if(((a == 0) + (b == 0) + (c == 0)) == 2){
        return 0;
    } else if(!a){
        cout << - c / b << "\n";
    } else {
        double d;
        if (b * b - 4 * a * c >= 0) {  
            d = sqrt(b * b - 4 * a * c);
        } else {
            return 0;
        }
        if (!d){
            cout << - b / (2 * a) << "\n";
        } else {
            cout << (- b - d) / (2 * a) << " " << (- b + d) / (2 * a) << "\n";
        }
    }
}