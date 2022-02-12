#include <iostream>
#include <vector>

using namespace std;

struct Student{
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main(){
    int n;
    cin >> n;
    vector<Student> v(n);
    for(auto& i : v){
        cin >> i.name >> i.surname >> i.day >> i.month >> i.year;
    } 
    cin >> n;
    ++n;
    string s;
    int ind;
    while(--n){
        cin >> s >> ind;
        --ind;
        if(!(s == "name" || s == "date") || ind < 0 || ind >= v.size()){
            cout << "bad request\n";
        } else {
            if(s == "name"){
                cout << v[ind].name << " " << v[ind].surname << '\n';
            } else if(s == "date"){
                cout << v[ind].day << "." << v[ind].month << "." << v[ind].year << '\n';
            }
        }
    }
}