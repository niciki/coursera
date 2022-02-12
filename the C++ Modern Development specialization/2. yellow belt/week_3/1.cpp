#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    string res = s;
    reverse(res.begin(), res.end());
    return res;
}

void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}