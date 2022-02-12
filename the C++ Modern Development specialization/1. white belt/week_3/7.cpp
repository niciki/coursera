#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
    public:
        Person(string name_, string surname_, int year_){ 
            name[year_] = name_;
            surname[year_] = surname_;
            birth = year_;
        }
        void ChangeFirstName(int year, const string& first_name) {
            if(year < birth){
                return;
            }
            name[year] = first_name; 
        }
        void ChangeLastName(int year, const string& last_name) {
            if(year < birth){
                return;
            }
            surname[year] = last_name; 
        }
        string GetFullName(int year) const {
            if(year < birth){
                return "No person";
            }
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
        string GetFullNameWithHistory(int year) const {
            if(year < birth){
                return "No person";
            }
            string n, s;
            int YEAR_NAME, YEAR_SURNAME;
            for(auto i: name){
                if(i.first <= year) {
                    n = i.second;
                    YEAR_NAME = i.first;
                }
            }
            for(auto i: surname){
                if(i.first <= year) {
                    s = i.second;
                    YEAR_SURNAME = i.first;
                }
            }
            if(n == "" && s == ""){
                return "Incognito";
            } else if(s == ""){
                vector<string> names;
                for(const auto& i: name){
                    if(i.first < year && i.first != YEAR_SURNAME){
                        if(!names.size()){
                            names.push_back(i.second);
                        } else if(names.back() != i.second){
                            names.push_back(i.second);
                        }
                    }
                }
                reverse(names.begin(), names.end());
                string last_names;
                for(int i = 0; i < names.size(); i++){
                    if(i == 1 && names[i] != n){    
                        last_names += (names[i] + ", ");
                    } else if(names[i - 1] != names[i]){
                        if(last_names.size() == 0){
                            if(names[i] != n){
                                last_names += (names[i] + ", ");
                            }
                        } else {
                            if(names[i] != "")
                                last_names += (names[i] + ", ");
                        }
                    }
                }
                if(last_names.length()){
                    last_names.erase(last_names.end() - 2, last_names.end());
                }
                if(last_names.length()){
                    return n + " ("+ last_names + ")" +  " with unknown last name";
                } else {
                    return n + " with unknown last name";
                }
            } else if (n == ""){
                vector<string> surnames;
                for(const auto& i: surname){
                    if(i.first < year && i.first != YEAR_SURNAME){
                        if(!surnames.size()){
                            surnames.push_back(i.second);
                        } else if(surnames.back() != i.second){
                            surnames.push_back(i.second);
                        }
                    }
                }
                reverse(surnames.begin(), surnames.end());
                string last_surnames;
                for(int i = 0; i < surnames.size(); i++){
                    if(i == 0 && surnames[i] != s){    
                        last_surnames += (surnames[i] + ", ");
                    } else if(surnames[i - 1] != surnames[i]){
                        if(last_surnames.length() == 0){
                            if(surnames[i] != s){
                                last_surnames += (surnames[i] + ", ");
                            }
                        } else {
                            if(surnames[i] != "")
                                last_surnames += (surnames[i] + ", ");
                        }
                    }
                }
                if(last_surnames.length()){
                    last_surnames.erase(last_surnames.end() - 2, last_surnames.end());
                }
                if(last_surnames.length()){
                    return s + " (" + last_surnames + ")" + " with unknown first name";
                } else {
                    return s + " with unknown first name";
                }
            } else {
                vector<string> names;
                for(const auto& i: name){
                    if(i.first < year && i.first != YEAR_NAME){
                        if(!names.size()){
                            names.push_back(i.second);
                        } else if(names.back() != i.second){
                            names.push_back(i.second);
                        }
                    }
                }
                reverse(names.begin(), names.end());
                string last_names;
                int cnt_ = 0, curr_ = 0;
                for(auto i : names){
                    if (i == n){
                        cnt_++;
                    }
                }
                for(int i = 0; i < names.size(); i++){
                    if(i == 0){
                        if(names[0] != n){
                            last_names += (names[0] + ", ");
                        }
                    } else if(i > 0 && names[i - 1] != names[i]){
                        if(last_names.length() == 0){
                            if(names[i] != n){
                                last_names += (names[i] + ", ");
                            }
                        } else {
                            last_names += (names[i] + ", ");
                        }
                    }
                }
                if(last_names.length()){
                    last_names.erase(last_names.end() - 2, last_names.end());
                }
                vector<string> surnames;
                for(const auto& i: surname){
                    if(i.first < year && i.first != YEAR_SURNAME){
                        if(!surnames.size()){
                            surnames.push_back(i.second);
                        } else if(surnames.back() != i.second){
                            surnames.push_back(i.second);
                        }
                    }
                }
                reverse(surnames.begin(), surnames.end());
                string last_surnames;
                int cnt = 0, curr = 0;
                for(auto i : surnames){
                    if (i == s){
                        cnt++;
                    }
                }
                for(int i = 0; i < surnames.size(); i++){
                    if(i == 0){
                        if(surnames[0] != s){
                            last_surnames += (surnames[0] + ", ");
                        }
                    } else if(i > 0 && surnames[i - 1] != surnames[i]){
                        if(last_surnames.length() == 0){
                            if(surnames[i] != s){
                                last_surnames += (surnames[i] + ", ");
                            }
                        } else {
                            last_surnames += (surnames[i] + ", ");
                        }
                    }
                }
                if(last_surnames.length()){
                    last_surnames.erase(last_surnames.end() - 2, last_surnames.end());
                }
                if(last_surnames.length() && last_names.length()){
                    return  n + " ("+ last_names + ")" + " " + s + " (" + last_surnames + ")";
                } else if (last_names.length()){
                    return  n + " ("+ last_names + ")" + " " + s;
                } else if (last_surnames.length()){
                    return  n + " " + s + " (" + last_surnames + ")";
                } else {
                    return n + " " + s;
                }
            }
        }
    private:
        map<int, string> name;
        map<int, string> surname;
        int birth;
};

/*
int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
*/