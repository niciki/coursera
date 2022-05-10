#include "RouteManager.h"
#include "JsonInputParser.h"

#include <unordered_set>
#include <iostream>
#include <sstream>


using namespace std;

Requests GetInfo(std::istream& input) {
    return {Json::ParseInput(input), Json::ParseInput(input)};
}

void JsonData::SetData(const vector<string>& add_requests) {
    for (auto& i: add_requests) {
        stringstream is(i);
        auto document = Json::Load(is);
        const auto& request = document.GetRoot().AsMap();
        if (request.at("type").AsString() == "Bus") {
            string bus_name = request.at("name").AsString();
            bool is_round_route = request.at("is_roundtrip").AsBool();
            size_t count_of_all_stations = 0;
            RouteStatistic rs;
            unordered_set<string> stations;
            list<string> stations_list;
            for (const auto& station: request.at("stops").AsArray()) {
                ++count_of_all_stations;
                if (!stations.count(station.AsString())) {
                    stations.insert(station.AsString());
                }
                rm.GetStopBuses()[station.AsString()].insert(bus_name);
                stations_list.emplace_back(station.AsString());
            }
            if (is_round_route) {
                rs = {count_of_all_stations, stations.size(), is_round_route, move(stations_list)};
            } else {
                rs = {2 * count_of_all_stations - 1, stations.size(), is_round_route, move(stations_list)};
            }
            rm.GetRouteStatistics()[move(bus_name)] = move(rs);
        } else {
            auto stop_name = request.at("name").AsString();
            rm.GetStopCoordinates()[stop_name] = {request.at("latitude").AsDouble(), request.at("longitude").AsDouble()};
            for (const auto& [station_to, distance] : request.at("road_distances").AsMap()) {
                rm.GetStopDistances()[stop_name][station_to] = distance.AsDouble();
                if (!rm.GetStopDistances()[station_to].count(stop_name)) {
                    rm.GetStopDistances()[station_to][stop_name] = distance.AsDouble();
                }
            }
        }
    }
}

void JsonData::PrintStat(const std::vector<std::string>& stat_requests) const {
    cout << "[\n";
    for (auto it = stat_requests.begin(); it != stat_requests.end(); ++it) {
        stringstream is(*it);
        auto document = Json::Load(is);
        const auto& request = document.GetRoot().AsMap();
        cout << "\t{\n";
        if (request.at("type").AsString() == "Bus") {
            auto it = rm.GetRouteStatistics().find(request.at("name").AsString());
            if (it == rm.GetRouteStatistics().end()) {
                cout << "\t\t\"request_id\": " << request.at("id").AsInt() << ",\n";
                cout << "\t\t\"error_message\": \"not found\"\n";
            } else {
                cout << "\t\t\"route_length\": " << rm.GetLength(it->second) << ",\n";
                cout << "\t\t\"request_id\": " << request.at("id").AsInt() << ",\n";
                cout << "\t\t\"curvature\": " << rm.GetLength(it->second)/rm.GetLengthCurvature(it->second) << ",\n";
                cout << "\t\t\"stop_count\": " << it->second.number_of_stops << ",\n";
                cout << "\t\t\"unique_stop_count\": " << it->second.number_of_unique_stops << "\n";
            }
        } else {
            if (!rm.GetStopCoordinates().count(request.at("name").AsString())) {
                cout << "\t\t\"request_id\": " << request.at("id").AsInt() << ",\n";
                cout << "\t\t\"error_message\": \"not found\"\n";
            } else {
                cout << "\t\t\"buses\": [";
                if (!rm.GetStopBuses().count(request.at("name").AsString())) {
                    cout << "],\n";
                } else {
                    for(auto it = rm.GetStopBuses().at(request.at("name").AsString()).begin(); it != rm.GetStopBuses().at(request.at("name").AsString()).end(); ++it) {
                        cout << "\n\t\t\t\"" << *it << "\"";
                        if (it != prev(rm.GetStopBuses().at(request.at("name").AsString()).end())) {
                            cout << ",";
                        } else {
                            cout << "\n\t\t";
                        }
                    }
                    cout << "],\n";
                }
                cout << "\t\t\"request_id\": " << request.at("id").AsInt() << "\n";
            }
        }
        cout << "\t}";
        if (it != prev(stat_requests.end())) {
            cout << ",\n";
        } else {
            cout << "\n";
        }
    }
    cout << "]";
}