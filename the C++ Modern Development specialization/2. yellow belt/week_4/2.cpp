#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    set<T> r;
    vector<T> v;
    for (auto i = elements.begin(); i != elements.end(); ++i) {
        if (*i > border) {
            r.insert(*i);
        }
    }
    for (const auto& i : r) {
        v.push_back(i);
    }
    return v;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
