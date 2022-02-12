#include <iostream>
#include <list>
#include <map>

using namespace std;

class Sportsmens {
public:
    void Add (int cur, int nxt) {
        if (data.count(nxt)) {
            l.insert(data[nxt], cur);
            data[cur] = prev(data[nxt]);
        } else {
            l.push_back(cur);
            data[cur] = prev(l.end());
        }
    }
    friend ostream& operator<< (ostream& os, const list<int>& l);
    friend ostream& operator<< (ostream& os, const Sportsmens& l);
private:
    list<int> l;
    map<int, list<int>::iterator> data;
};

ostream& operator<< (ostream& os, const list<int>& l) {
    for (const auto& i: l) {
        os << i << "\n";
    }
    return os;
}

ostream& operator<< (ostream& os, const Sportsmens& l) {
    os << l.l;
    return os;
}

int main() {
    Sportsmens s;
    int n, cur, nxt;
    cin >> n;
    while (n--) {
        cin >> cur >> nxt;
        s.Add(cur, nxt);
    }
    cout << s;
}