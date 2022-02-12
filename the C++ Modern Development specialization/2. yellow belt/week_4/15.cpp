#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string res = "";
    int tmp, n;
    cin >> tmp;
    char oper;
    vector<int> numbers;
    numbers.push_back(tmp);
    vector<char> operations;
    cin >> n;
    while (n--) {
        cin >> oper >> tmp;
        numbers.push_back(tmp);
        operations.push_back(oper);
    }
    if (operations.size()) {
        res += "(" + string(operations.size() - 1, '(');
        res += to_string(numbers[0]) + ") ";
        for (int i = 0; i < operations.size(); ++i) {
            if (i != operations.size() - 1) {
                res += string(1, operations[i]) + " " + to_string(numbers[i + 1]) + ") ";
            } else {
                res += string(1, operations[i]) + " " + to_string(numbers[i + 1]);
            }
        }
        cout << res << "\n";
    } else {
        cout << to_string(numbers.front()) + "\n";
    }
}