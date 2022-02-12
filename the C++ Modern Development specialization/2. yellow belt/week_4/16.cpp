#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count_high_order_operations(vector<char> & v) {
    bool f = 0;
    int tmp_res = 0;
    for (int i = 0; i < v.size(); ++i) {
        if ((v[i] == '/') || (v[i] == '*') && !f) {
            f = 1;
        } else if ((v[i] == '/') || (v[i] == '*') && f) {
            ;
        } else {
            if ((i != v.size()) && (v[i + 1] == '/' || v[i + 1] == '*')){
               tmp_res++;
                f = 0;
            } else {
                f = 0;
            }
        }
    }
    return tmp_res;
}

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
    int num_oper = count_high_order_operations(operations);
    if (numbers.size()) {
        res += string(num_oper, '(');
        res += to_string(numbers[0]) + ' ';
        if (num_oper) {
            for (int i = 0; i < operations.size(); ++i) {
                if (i != operations.size() - 1) {
                    if ((operations[i] == '+' || operations[i] == '-') && (operations[i + 1] == '*' || operations[i + 1] == '/')) {
                        res += string(1, operations[i]) + " " + to_string(numbers[i + 1]) + ") ";
                    } else {
                        res += string(1, operations[i]) + " " + to_string(numbers[i + 1]) + " ";
                    }
                } else {
                    res += string(1, operations[i]) + " " + to_string(numbers[i + 1]);
                }
            }
            cout << res << "\n";
        } else {
            for (int i = 0; i < operations.size(); ++i) {
                if (i != operations.size() - 1) {
                    res += string(1, operations[i]) + " " + to_string(numbers[i + 1]) + " ";
                } else {
                    res += string(1, operations[i]) + " " + to_string(numbers[i + 1]);
                }
            }
            cout << res << "\n";
        }
    } else {
        cout << to_string(numbers.front()) << "\n";
    }
}