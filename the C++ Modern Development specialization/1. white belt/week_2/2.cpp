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

/*
int main(){
    string s;
    cin >> s;
    cout << IsPalindrom(s) << "\n";
}
*/