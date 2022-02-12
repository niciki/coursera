#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(auto& i: v){
        cin >> i;
        sum += i;
    }
    int med_s = sum / n;
    vector<int> b;
    for(int i = 0; i < n; ++i){
        if(v[i] > med_s){
            b.push_back(i);
        }
    }
    cout << b.size() << "\n";
    for(auto& i: b){
        cout << i << " ";
    }
    cout << "\n";
}