#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto& i: v){
        cin >> i;
    }
    sort(v.begin(), v.end(), [](string s1, string s2){
        for(int i = 0; i < min(s1.length(), s2.length()); ++i){
            if(s1[i] >= 65 && s1[i] <= 90){
                s1[i] = char(int(s1[i]) + 32);
            }
            if(s2[i] >= 65 && s2[i] <= 90){
                s2[i] = char(int(s2[i]) + 32);
            }
            if(s1[i] != s2[i]){
                return s1[i] < s2[i];
            }
        }
        return false;
    });
    for(const auto& i: v){
        cout << i << " ";
    }
    cout << "\n";
}