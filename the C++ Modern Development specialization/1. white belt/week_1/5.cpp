#include <iostream>

using namespace std;

int main(){
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    cout << (n <= a ? n : (n > b ? n * (100 - y)/100 : n * (100 - x)/100)) << "\n";
    return 0;
}