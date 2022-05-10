#include "RouteManager.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

namespace Utils {

// version for inpur stations
string GetNameInput() {
    string answ, tmp;
    while (answ.back() != ':' && cin >> tmp) {
        answ += (answ == "" ? tmp : " " + tmp);
        if (cin.peek() == '\n') {
            return answ;
        }
    }
    answ.erase(answ.size() - 1);
    return answ;
}

long double GetDistance(Coordinates c1, Coordinates c2) {
    long double c1_lat = c1.latitude * 3.1415926535 / 180;
    long double c1_lon = c1.longitude * 3.1415926535 / 180;
    long double c2_lat = c2.latitude * 3.1415926535 / 180;
    long double c2_lon = c2.longitude * 3.1415926535 / 180;
    return acos(sin(c1_lat) * sin(c2_lat) + cos(c1_lat) * cos(c2_lat) * cos(abs(c1_lon - c2_lon))) * 6371000;
}

// version for routes
Station GetStationName() {
    string station_name = "", new_str;
    bool is_end = true;
    while (cin.peek() != '\n' && cin >> new_str) {
        if (new_str == "-" || new_str == ">") {
            break;
        }
        is_end = false;
        if (station_name == "") {
            station_name += new_str;
        } else {
            station_name += (" " + new_str);
        }
    }
    return {move(station_name), (new_str == ">" ? true : false), is_end};
}

}

long double RouteManager::GetLength(const RouteStatistic& rs) const {
    long double length = 0;
    for (auto it = next(rs.route.cbegin()); it != rs.route.cend(); it = next(it)) {
        length += Utils::GetDistance(stop_coordinates.at(*prev(it)), stop_coordinates.at(*it));
    }
    return rs.is_round_route ? length : 2 * length;
}

void RouteManager::AddStop() {
    string stop_name = Utils::GetNameInput();
    char comma;
    Coordinates crd;
    cin >> crd.latitude >> comma >> crd.longitude;
    stop_coordinates[move(stop_name)] = move(crd);
}

void RouteManager::AddBus() {
    RouteStatistic rs;
    string bus_number = GetNameInput();
    unordered_set<string> stations;
    size_t count_of_all_stations = 0;
    bool is_round_route;
    string prev_station = "";
    long double distance = 0;
    list<string> stations_list;
    while (1) {
        Station s = GetStationName();
        if (s.is_end) {
            break;
        }
        if (!stations.size()) {
            // determine the type of route by the first stop
            is_round_route = s.is_round_route;
        }
        ++count_of_all_stations;
        if (!stations.count(s.station_name)) {
            stations.insert(s.station_name);
        }
        stop_buses[s.station_name].insert(bus_number);
        stations_list.emplace_back(move(s.station_name));
    }
    if (is_round_route) {
        rs = {count_of_all_stations, stations.size(), is_round_route, move(stations_list)};
    } else {
        rs = {2 * count_of_all_stations - 1, stations.size(), is_round_route, move(stations_list)};
    }
    route_statistics[move(bus_number)] = move(rs);
}

void RouteManager::SearchBus() const {
    string number = GetNameInput();
    auto it = route_statistics.find(number);
    if (it == route_statistics.end()) {
        cout << "Bus " << number << ": not found\n";
    } else {
        cout << "Bus " << number << ": " << it->second.number_of_stops
         << " stops on route, " << it->second.number_of_unique_stops
         << " unique stops, " << GetLength(it->second) << " route length\n";
    }
}

void RouteManager::SearchStop() const {
    string stop_name = GetNameInput();
    if (!stop_coordinates.count(stop_name)) {
        cout << "Stop " << stop_name <<": not found\n";
        return;
    } else if (!stop_buses.count(stop_name)) {
        cout << "Stop " << stop_name <<": no buses\n";
        return;
    }
    cout << "Stop " << stop_name <<": buses ";
    for (auto it = stop_buses.at(stop_name).begin(); it != stop_buses.at(stop_name).end(); ++it) {
        if (it != prev(stop_buses.at(stop_name).end())) {
            cout << *it << " ";
        } else {
            cout << *it << "\n";
        }
    }
}

void RouteManager::Print() const {
    for (auto& [i, j]: stop_coordinates) {
        cout << i << " " << j.latitude << " " << j.longitude << "\n";
    }
    for (auto& [i, j]: route_statistics) {
        cout << i << "* ";
        for (auto it = j.route.begin() ; it != j.route.end(); it = next(it)) {
            cout << *it << ", ";
        }
        cout << endl;
    }
}