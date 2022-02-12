#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> v(num);
    for(auto& i: v){
        cin >> i;
    }
    sort(v.begin(), v.end(), [](int x, int y){
                                        if(abs(x) == abs(y)){
                                            return x < y;
                                        }
                                        return abs(x) < abs(y);
                                    });
    for(const auto& i: v){
        cout << i << " ";
    }
    cout << "\n";
}