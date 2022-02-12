#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v;
    while(n > 0){
        v.push_back(n % 2);
        n /= 2;
    }
    for(auto i = --v.end(); i >= v.begin(); --i){
        cout << *i;
    }
    cout << "\n";
    return 0;
}