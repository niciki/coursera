#include <iostream>
#include <map>

using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            name[year] = first_name; 
        }
        void ChangeLastName(int year, const string& last_name) {
            surname[year] = last_name; 
        }
        string GetFullName(int year) {
            string n, s;
            for(auto i: name){
                if(i.first <= year) {
                    n = i.second;
                }
            }
            for(auto i: surname){
                if(i.first <= year) {
                    s = i.second;
                }
            }
            if(n == "" && s == ""){
                return "Incognito";
            } else if(s == ""){
                return n + " with unknown last name";
            } else if (n == ""){
                return s + " with unknown first name";
            } else {
                return n + " " + s;
            }
        }
    private:
        map<int, string> name;
        map<int, string> surname;
};

/*
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
*/