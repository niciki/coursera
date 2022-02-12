#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> bus;
    map<string, vector<string>> data;
    map<string, vector<string>> stop_buses;
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "NEW_BUS"){
            string bus_name, station;
            int num;
            cin >> bus_name >> num;
            bus.push_back(bus_name);
            while(num--){
                cin >> station;
                data[bus_name].push_back(station);
                stop_buses[station].push_back(bus_name);
            }
        } else if(s == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            int t = 0;
            for(const auto& i: bus){
                if(count(data[i].begin(), data[i].end(), stop)){
                    cout << i << " ";
                    ++t;
                }
            }
            if(!t){
                cout << "No stop";
            }
            cout << "\n";
        } else if(s == "STOPS_FOR_BUS"){
            string b;
            cin >> b;
            if(!data.count(b)){
                cout << "No bus\n";
            } else {
                for(const auto& i: data[b]){
                    cout << "Stop " << i << ": ";
                    if(!(stop_buses[i].size() - 1)){
                        cout << "no interchange\n";
                    } else {
                        for(const auto& j: stop_buses[i]){
                            if(j != b){
                                cout << j << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }
        } else if(s == "ALL_BUSES"){
            if(!bus.size()){
                cout << "No buses\n";
            } else {
                for(const auto& i: data){
                    cout << "Bus " << i.first << ": ";
                    for(const auto& j: data[i.first]){
                        cout << j << " ";
                    }
                    cout << "\n";
                }
            }
        }
    } 
}