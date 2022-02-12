#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    int n, qurr = 1, num;
    string str;
    cin >> n;
    map<set<string>, int> m;
    while(n--){
        cin >> num;
        set<string> s;
        while(num--){
            cin >> str;
            s.insert(str);
        }
        if(m.count(s)){
            cout << "Already exists for " << m[s] << "\n";
        } else {
            cout << "New bus " << qurr << "\n";
            m[s] = qurr++; 
        }
    }
}