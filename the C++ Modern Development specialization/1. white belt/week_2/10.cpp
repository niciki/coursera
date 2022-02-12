#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> month(31, vector<string>());
    int n, m_curr = 0, i;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "ADD"){
            cin >> i;
            cin >> s;
            month[--i].push_back(s);
        } else if (s == "DUMP"){
            cin >> i;
            --i;
            cout << month[i].size() << " ";
            for(auto j: month[i]){
                cout << j << " ";
            }
            cout << "\n";
        } else if(s == "NEXT"){
            if(days[m_curr] > days[(m_curr + 1) % 12]){
                vector<vector<string>> tmp = month;
                month.erase(month.begin() + days[(m_curr + 1) % 12] - 1, month.end());
                month.resize(days[(m_curr + 1) % 12]);
                for(int i = days[(m_curr + 1) % 12] - 1; i <= days[m_curr] - 1; ++i){
                    month[month.size() - 1].insert(month[month.size() - 1].end(), tmp[i].begin(), tmp[i].end());
                }
            } else if(days[m_curr] < days[(m_curr + 1) % 12]){
                month.resize(days[(m_curr + 1) % 12]);
            }
            m_curr = (m_curr + 1) % 12;
        }
    }
}