#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    if (numbers.count(border)) {
        return find(numbers.begin(), numbers.end(), border);
    }
    auto it = equal_range(numbers.begin(), numbers.end(), border);
    if (*it.first == border) {
        return it.first;
    } else {
        if (it.first != numbers.end() && it.second != numbers.end()) {
            if (it.first != numbers.begin()) {
                if (abs(*prev(it.first) - border) > abs(*it.second - border)) {
                    return it.second;
                } else {
                    return prev(it.first);
                }
            } else {
                return it.first;
            }
        }
        else {
            if (numbers.begin() == numbers.end()) {
                return it.first;
            }
            return prev(it.first);
        }
    }
}

int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}