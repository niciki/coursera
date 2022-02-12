#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <utility>
#include <iterator>


using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin <= 2) {
        return;
    }
    int step = (range_end - range_begin) / 3;
    vector<typename RandomIt::value_type> v(make_move_iterator(range_begin), make_move_iterator(range_end));
    MergeSort(v.begin(), v.begin() + step);
    MergeSort(next(v.begin(), step), next(v.begin(), 2 * step));
    MergeSort(next(v.begin(), 2 * step), v.end());
    vector<typename RandomIt::value_type> tmp;
    merge(make_move_iterator(v.begin()), make_move_iterator(next(v.begin(), step)),
            make_move_iterator(next(v.begin(), step)),
            make_move_iterator(next(v.begin(), 2 * step)),
            back_inserter(tmp));
    merge(make_move_iterator(tmp.begin()), make_move_iterator(tmp.end()),
            make_move_iterator(next(v.begin(), 2 * step)),
            make_move_iterator(v.end()), range_begin);
    // Напишите реализацию функции,
    // не копируя сортируемые элементы
}

void TestIntVector() {
    vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
    MergeSort(begin(numbers), end(numbers));
    ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestIntVector);
    return 0;
}