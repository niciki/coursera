#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(b){
        cout << a / b << "\n";
    } else {
        cout << "Impossible\n";
    }
}