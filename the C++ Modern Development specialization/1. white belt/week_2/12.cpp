#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, string> data;
    string s, country, capital, new_country;
    while(n--){
        cin >> s;
        if(s == "CHANGE_CAPITAL"){
            cin >> country >> capital;
            if(data.count(country) == 0){
                cout << "Introduce new country " << country << " with capital " << capital << "\n";
                data[country] = capital; 
            } else if(data[country] == capital){
                cout << "Country " << country << " hasn't changed its capital\n";
            } else {
                cout << "Country " << country << " has changed its capital from " << data[country] << " to " << capital << "\n";
                data[country] = capital;
            }
        } else if(s == "RENAME"){
            cin >> country >> new_country;
            if(new_country == country || data.count(new_country) || !data.count(country)){
                cout << "Incorrect rename, skip\n";
            } else {
                capital = data[country];
                data.erase(country);
                data[new_country] = capital;
                cout << "Country " << country << " with capital " << capital << " has been renamed to " << new_country << "\n";
            }
        } else if(s == "ABOUT"){
            cin >> country;
            if(!data.count(country)){
                cout << "Country " << country << " doesn't exist\n";
            } else {
                cout << "Country " << country << " has capital " << data[country] << "\n";
            }
        } else if(s == "DUMP"){
            if(!data.size()){
                cout << "There are no countries in the world\n";
            } else {
                for(const auto& i: data){
                    cout << i.first << "/" << i.second << "\n";
                }
            }
        }
    }
}