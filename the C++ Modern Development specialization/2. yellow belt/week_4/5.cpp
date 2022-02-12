#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream& operator << (ostream& os, vector<int>& v) {
    for (const auto& i: v) {
        os << i << " ";
    }
    return os;
}

int main() {
    int n;
    cin >> n;
    vector<int> p;
    vector<vector<int>> v;
    for (int i = 1; i <= n; ++i) {
        p.push_back(i);
    }
    do {
        v.push_back(p);
    } while (next_permutation(p.begin(), p.end()));
    reverse(v.begin(), v.end());
    for (auto& i : v) {
        cout << i << "\n";
    }
}