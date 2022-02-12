/*
#include <iostream>
#include <vector>

using namespace std;
*/

int Factorial(const int& n){
    if(n <= 1){
        return 1;
    }
    int a = 1;
    for(int i = 2; i <= n; i++){
        a *= i;
    }
    return a;
}
/*
int main(){
    int n;
    cin >> n;
    cout << Factorial(n) << "\n";
}
*/