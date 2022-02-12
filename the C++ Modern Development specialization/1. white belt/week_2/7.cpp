/*
#include <iostream>
#include <vector>
using namespace std;
*/

#include <algorithm>

vector<int> Reversed(const vector<int>& v){
    vector<int> z(v);
    reverse(z.begin(), z.end());
    return z;
}

/*
int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> numbers = q;
    q = Reversed(numbers);
    for(auto i : q){
        cout << i << " ";
    }
    cout << "\n";
}
*/