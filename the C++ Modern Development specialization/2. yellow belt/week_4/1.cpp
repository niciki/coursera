/*
#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

*/
#include <algorithm>

void PrintVectorPart(const vector<int>& numbers) {
    if (!numbers.size()) {
        return;
    }
    vector<int>::const_iterator q = find_if(numbers.begin(), numbers.end(), [](int a) {
                                                                                    return a < 0;
                                                                                });
    for (vector<int>::const_iterator i = --q; i >= numbers.begin(); --i) {
        cout << *i << " ";
    }
}

/*
int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;
    PrintVectorPart({});
    cout << endl;
    return 0;
}*/