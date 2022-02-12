#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*int sum_ascii(string s) {
    // cout << s << " ";
    int res = 0;
    for (auto i : s) {
        res += i - 'a';
    }
    // cout << res << "\n";
    return res;
}*/

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, string prefix) {
    int size = prefix.size();
    return equal_range(range_begin, range_end, prefix, [&size](const string& prefix, const string& i){
        return string{prefix.begin(), prefix.begin() + size} < string{i.begin(), i.begin() + size};
    });
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
        (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
        (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}