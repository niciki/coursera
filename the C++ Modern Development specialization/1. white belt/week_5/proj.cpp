#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
    public:
        Date(int year_, int month_, int day_): year(year_), month(month_), day(day_) {}
        int year;
        int month;
        int day;
};

bool operator<(const Date& l, const Date& r){
    if(l.year != r.year){
        return l.year < r.year;
    } else if(l.month != r.month){
        return l.month < r.month;
    } else {
        return l.day < r.day;
    }
}

ostream& operator<<(ostream& os, const Date& d){
    os << setw(4) << setfill('0') << d.year << "-" << setw(2) << setfill('0') << d.month << "-" << 
                                                                setw(2) << setfill('0') << d.day;
    return os;
}

int main(){
    map<Date, set<string>> base;
    string command;
    while(cin >> command){
        if(command == "Add"){
            string date, event;
            cin >> date >> event;
            stringstream s(date);
            int year, month, day;
            bool f3 = false, f4 = false;
            char d1, d2;
            if(s >> year >> d1 >> month >> d2 >> day){
                if(s.peek() != EOF || d1 != '-' || d2 != '-'){
                    cout << "Wrong date format: " << date << "\n";
                    return 0;
                }
            } else {
                cout << "Wrong date format: " << date << "\n";
                return 0;
            }
            if(!(month >= 1 && month <= 12)){
                f3 = true;
            }
            if(!(day >= 1 && day <= 31)){
                f4 = true;
            }
            if(f3){
                cout << "Month value is invalid: " << month << "\n";
                return 0;
            } else if(f4){
                cout << "Day value is invalid: " << day << "\n";
                return 0;
            }
            base[Date(year, month, day)].insert(event);
        } else if(command == "Del"){
            string date;
            cin >> date;
            stringstream s(date);
            int year, month, day;
            bool f3 = false, f4 = false;
            char d1, d2;
            if(s >> year >> d1 >> month >> d2 >> day){
                if(s.peek() != EOF || d1 != '-' || d2 != '-'){
                    cout << "Wrong date format: " << date << "\n";
                    return 0;
                }
            } else {
                cout << "Wrong date format: " << date << "\n";
                return 0;
            }
            if(!(month >= 1 && month <= 12)){
                f3 = true;
            }
            if(!(day >= 1 && day <= 31)){
                f4 = true;
            }
            if(f3){
                cout << "Month value is invalid: " << month << "\n";
                return 0;
            } else if(f4){
                cout << "Day value is invalid: " << day << "\n";
                return 0;
            }
            if(!(month >= 1 && month <= 12)){
                f3 = true;
            }
            if(!(day >= 1 && day <= 31)){
                f4 = true;
            }
            if(f3){
                cout << "Month value is invalid: " << month << "\n";
                return 0;
            } else if(f4){
                cout << "Day value is invalid: " << day << "\n";
                return 0;
            }
            string event = "";
            if(cin.peek() == ' '){
                cin >> event;
            }
            if(event == ""){
                cout << "Deleted " <<base[Date(year, month, day)].size() << " events\n";
                base[Date(year, month, day)].erase(base[Date(year, month, day)].begin(), base[Date(year, month, day)].end());
            } else {
                if(base[Date(year, month, day)].count(event)){
                    base[Date(year, month, day)].erase(event);
                    cout << "Deleted successfully\n";
                } else {
                    cout << "Event not found\n";
                }
            }
        } else if(command == "Find"){
            string date;
            cin >> date;
            stringstream s(date);
            int year, month, day;
            bool f3 = false, f4 = false;
            char d1, d2;
            if(s >> year >> d1 >> month >> d2 >> day){
                if(s.peek() != EOF || d1 != '-' || d2 != '-'){
                    cout << "Wrong date format: " << date << "\n";
                    return 0;
                }
            } else {
                cout << "Wrong date format: " << date << "\n";
                return 0;
            }
            if(!(month >= 1 && month <= 12)){
                f3 = true;
            }
            if(!(day >= 1 && day <= 31)){
                f4 = true;
            }
            if(f3){
                cout << "Month value is invalid: " << month << "\n";
                return 0;
            } else if(f4){
                cout << "Day value is invalid: " << day << "\n";
                return 0;
            }
            if(f3){
                cout << "Month value is invalid: " << month << "\n";
                return 0;
            } else if(f4){
                cout << "Day value is invalid: " << day << "\n";
                return 0;
            }
            for(const auto& i: base[Date(year, month, day)]){
                cout << i << "\n";
            }
        } else if(command == "Print"){
            for(const auto& i: base){
                for(const auto& j: i.second){
                    cout << i.first << " " << j << "\n";
                }
            }
        } else {
            cout << "Unknown command: " << command << '\n'; 
            return 0;
        }
    }
}