#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    long long int n, q, sum = 0;
    cin >> n;
    for(long long int i = 0; i < n; ++i){
        cin >> q;
        sum += q;
        v.push_back(q);
    }
    long long int avg = sum / n;
    vector<long long int> v2;
    for(long long int i = 0; i < n; ++i){
        if(v[i] > avg){
            v2.push_back(i);
        }
    }
    cout << v2.size() << "\n";
    for(const auto& i : v2){
        cout << i << " ";
    }
    cout << "\n";
}