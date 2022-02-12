/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class SortedStrings {
public:
    void AddString(const string& s) {
        v.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(v.begin(), v.end(), [](string s1, string s2){
            for(int i = 0; i < min(s1.length(), s2.length()); ++i){
            if(s1[i] >= 65 && s1[i] <= 90){
                s1[i] = char(int(s1[i]) + 32);
            }
            if(s2[i] >= 65 && s2[i] <= 90){
                s2[i] = char(int(s2[i]) + 32);
            }
            if(s1[i] != s2[i]){
                return s1[i] <= s2[i];
            }
        }
        return false;
        });
        return v;
    }
private:
    vector<string> v;
};
*/

#include <map>

class SortedStrings {
public:
    void AddString(const string& s) {
        m.insert(make_pair(s, m.size()));
    }
    vector<string> GetSortedStrings() {
        vector<string> v;
        for(const auto& i: m){
            v.push_back(i.first);
        }
        return v;
    }
private:
    multimap<string, int> m;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

/*
int main() {
    SortedStrings strings;
    
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    return 0;
}
*/