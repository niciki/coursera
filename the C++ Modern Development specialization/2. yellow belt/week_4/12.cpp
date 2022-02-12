#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string compute(map<int, string>& m, int year) {
    auto i = m.upper_bound(year);
    if (i != m.begin()) {
        return (--i)->second;
    }
    return "";
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        surnames[year] = last_name;
    }
    string GetFullName(int year) {
        string name, surname;
        name = compute(names, year);
        surname = compute(surnames, year);
        if (surname == "" && name == "") {
            return "Incognito";
        } else if (surname == "") {
            return name + " with unknown last name";
        } else if(name == "") {
            return surname + " with unknown first name";
        } else {
            return name + " " + surname;
        }
    }
private:
    map<int, string> names;
    map<int, string> surnames;
};

int main() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}