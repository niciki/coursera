#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end)
        : first(begin)
        , last(end)
    {
    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }

private:
    Iterator first, last;
};

template <typename Collection>
auto Head(Collection& v, size_t top) {
    return IteratorRange{v.begin(), next(v.begin(), min(top, v.size()))};
}

struct Person {
    string name;
    int age, income;
    bool is_male;
};

vector<Person> ReadPeople(istream& input) {
    int count;
    input >> count;

    vector<Person> result(count);
    for (Person& p : result) {
        char gender;
        input >> p.name >> p.age >> p.income >> gender;
        p.is_male = gender == 'M';
    }

    return result;
}

void Age(vector<Person>& people) {
    int adult_age;
    cin >> adult_age;
    auto adult_begin = lower_bound(
        begin(people), end(people), adult_age, [](const Person& lhs, int age) {
            return lhs.age < age;
        }
    );

    cout << "There are " << std::distance(adult_begin, end(people))
        << " adult people for maturity age " << adult_age << '\n';
}

string Popular_name(vector<Person>& people, char gender) {
    stringstream ss;
    IteratorRange range{
        begin(people),
        partition(begin(people), end(people), [gender](Person& p) {
            return p.is_male == (gender == 'M');
        })
    };

    if (range.begin() == range.end()) {
        ss << "No people of gender " << gender << '\n';
    } else {
        sort(range.begin(), range.end(), [](const Person& lhs, const Person& rhs) {
            return lhs.name < rhs.name;
        });
        const string* most_popular_name = &range.begin()->name;
        int count = 1;
        for (auto i = range.begin(); i != range.end(); ) {
            auto same_name_end = find_if_not(i, range.end(), [i](const Person& p) {
                return p.name == i->name;
            });
            auto cur_name_count = std::distance(i, same_name_end);
            if (cur_name_count > count) {
                count = cur_name_count;
                most_popular_name = &i->name;
            }
            i = same_name_end;
        }
        ss << "Most popular name among people of gender " << gender << " is "
            << *most_popular_name << '\n';
    }
    return ss.str();
}

int main() {
    vector<Person> people = ReadPeople(cin);
    string men_str = Popular_name(people, 'M');
    string women_str = Popular_name(people, 'W');
    vector<long long int> prefix_sum(people.size(), 0);
    sort(people.begin(), people.end(), [](const Person& lhs, const Person& rhs){
        return lhs.income > rhs.income;
    });
    if (prefix_sum.size()) {
        prefix_sum[0] = people[0].income;
    }
    for (int i = 1; i < prefix_sum.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + people[i].income;
    }
    sort(people.begin(), people.end(), [](Person& lhs, Person& rhs){
        return lhs.age < rhs.age;
    });
    for (string command; cin >> command; ) {
        if (command == "AGE") {
            Age(people);
        } else if (command == "WEALTHY") {
            int count;
            cin >> count;
            cout << "Top-" << count << " people have total income " << prefix_sum[count - 1] << '\n';
        } else if (command == "POPULAR_NAME") {
            char gender;
            cin >> gender;
            if (gender == 'M') {
                cout << men_str;
            } else {
                cout << women_str;
            }
        }
    }
}
