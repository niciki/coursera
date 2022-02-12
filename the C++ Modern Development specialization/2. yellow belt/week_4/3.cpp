#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> v;
    auto i = s.begin();
    while (i < s.end()) {
        auto q = find_if(i, s.end(), [](char p) {
                                                    return p == ' ';
                                                });
        v.push_back({i, q});
        i = ++q;
    }
    return v;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
