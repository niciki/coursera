#include <iostream>

using namespace std;

int main(){
    int f = -2;
    string s;
    cin >> s;
    int q = 0;
    for (auto i : s){
        if (i == 'f'){
            if (f == -2){
                f = -1;
            } else if(f == -1){
                f = q;
                break;
            }
        }
        ++q;
    }
    cout << f << "\n";
    return 0;
}