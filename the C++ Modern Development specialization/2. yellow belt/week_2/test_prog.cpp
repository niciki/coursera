#include <bits/stdc++.h>
#include "unit_framework.h"
#include <vector>
#include <queue>
#include <set>

using namespace std;

void Test_smth_int() {
    Assert(1, 0, "int comparison");
}

void Test_smth_vector() {
    vector<int> v = {1, 2, 3, 4};
    vector<int> v_2 = {1, 2, 3, 5};
    Assert(v, v_2, "vector comparison");
}

void Test_smth_deque_of_sets() {
    deque<set<int>> q = {{1, 2}, {3, 4}, {5, 6, 7}};
    deque<set<int>> q_2 = {{1, 2}, {3, 4,}, {5, 5, 7}};
    Assert(q, q_2, "deque of sets comparison");
}

void Testing() {
    Tests t;
    t.Run_test(Test_smth_int, "Test_smth_int");
    t.Run_test(Test_smth_vector, "Test_smth_vector");
    t.Run_test(Test_smth_deque_of_sets, "Test_smth_deque_of_sets");
}

int main() {
    Testing();
}