/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
*/
#include <algorithm>

bool IsPalindrom(const string& s){
    string p(s);
    reverse(p.begin(), p.end());
    return (p == s ? 1 : 0);
}

vector<string> PalindromFilter(vector<string>& words, int& minLength){
    vector<string> v;
    for(auto i : words){
        if(i.length() >= minLength && IsPalindrom(i)){
            v.push_back(i);
        }
    }
    return v;
}
/*
int main(){
    int num;
    cin >> num;
    vector<string> v(num);
    int n;
    for(auto& i: v){
        cin >> i;
    }
    cin >> n;
    vector<string> res = PalindromFilter(v, n);
    for(auto& i: res){
        cout << i << " ";
    }
}*/
