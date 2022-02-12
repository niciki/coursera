#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> v(3);
    for(auto& i: v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    cout << v[0] << "\n" << clock();
}