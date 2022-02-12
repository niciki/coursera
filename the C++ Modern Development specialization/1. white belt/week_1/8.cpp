#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
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
    cout << b << "\n";
    return 0;
}