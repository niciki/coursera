#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    string tmp;
    cin >> n;
    set<string> s;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << "\n";
}