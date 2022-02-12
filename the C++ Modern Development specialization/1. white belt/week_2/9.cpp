#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, j;
    string s;
    vector<int> v;
    vector<int> worry;
    cin >> n;
    while(n--){
        cin >> s;
        if (s == "WORRY"){
            cin >> j;
            worry[j] = 1;
        } else if(s == "COME"){
            cin >> j;
            v.resize(v.size() + j);
            worry.resize(worry.size() + j, 0);
        } else if(s == "WORRY_COUNT"){
            int num = 0;
            for(auto &i: worry){
                if(i == 1){
                    ++num;
                }
            }
            cout << num << "\n";
        } else if(s == "QUIET"){
            cin >> j;
            worry[j] = 0;
        }
    }
}