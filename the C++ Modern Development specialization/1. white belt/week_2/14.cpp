#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int qurr = 1;
    map<vector<string>, int> m;
    while(n--){
        int num;
        cin >> num;
        vector<string> v(num);
        for(auto& i: v){
            cin >> i;
        }
        if(m.count(v)){
            cout << "Already exists for " << m[v] << "\n";
        } else {
            cout << "New bus " << qurr << "\n";
            m[v] = qurr++;
        }
    }
}