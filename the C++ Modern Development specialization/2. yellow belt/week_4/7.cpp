// merge sort by division 2 parts

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (distance(range_begin, range_end) < 2) {
        return;
    }
    vector<typename RandomIt::value_type> v1(range_begin, range_begin + distance(range_begin, range_end) / 2);
    vector<typename RandomIt::value_type> v2(range_begin + distance(range_begin, range_end) / 2, range_end);
    MergeSort(v1.begin(), v1.end());
    MergeSort(v2.begin(), v2.end());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), range_begin);
    return;
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}