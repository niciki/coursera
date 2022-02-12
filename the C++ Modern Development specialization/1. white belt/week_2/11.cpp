#include <iostream>
#include <map>

using namespace std;

map<char, int> get_map(string s){
    map<char, int> m;
    for(auto& i: s){
        ++m[i];
    }
    return m;
}

int main(){
    int n;
    cin >> n;
    string s1, s2;
    while(n--){
        cin >> s1 >> s2;
        if(get_map(s1) == get_map(s2)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}