#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    map<string, set<string>> m;
    int n;
    cin >> n;
    string s1, s2, tmp;
    while(n--){
        cin >> tmp;
        if(tmp == "ADD"){
            cin >> s1 >> s2;
            m[s1].insert(s2);
            m[s2].insert(s1);
        } else if(tmp == "COUNT"){
            cin >> s1;
            cout << m[s1].size() << "\n";
        } else if (tmp == "CHECK"){
            cin >> s1 >> s2;
            if(!m[s1].count(s2)){
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}