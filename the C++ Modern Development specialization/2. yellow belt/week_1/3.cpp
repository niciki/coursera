/*
#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    set<set<int>> s;
    int w, h, d;
    for(int i = 0; i < n; ++i){
        set<int> tmp;
        cin >> w >> h >> d;
        tmp.insert(w);
        tmp.insert(h);
        tmp.insert(d);
        s.insert(tmp);
    }
    long long int v_, v = 0;
    for(const auto& i : s){
        long long int v_ = r;
        for(const auto& j : i){
            v_ *= j;
        }
        v += v_;
    }
    cout << v << "\n";
}*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector<uint64_t> tmp(3);
    uint64_t v_, v = 0;
    for(int i = 0; i < n; ++i){
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        uint64_t v_ = r * tmp[0] * tmp[1] * tmp[2];
        v += v_;
    }
    cout << v << "\n";
}