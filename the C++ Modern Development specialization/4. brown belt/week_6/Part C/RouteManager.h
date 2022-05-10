#ifndef ROUTE_MANAGER_H
#define ROUTE_MANAGER_H

#include <unordered_map>
#include <set>
#include <list>
#include <string>

struct Coordinates {
    long double latitude;
    long double longitude;
};

struct RouteStatistic {
    size_t number_of_stops;
    size_t number_of_unique_stops;
    bool is_round_route;
    std::list<std::string> route;
};

struct Station {
    std::string station_name;
    bool is_round_route;
    bool is_end;
};

class RouteManager {
public:
    void AddStop();
    void AddBus();
    void SearchBus() const;
    void SearchStop() const;
    void Print() const;
    long double GetLengthCurvature(const RouteStatistic& rs) const;
    long long int GetLength(const RouteStatistic& rs) const;
private:
    std::unordered_map<std::string, Coordinates> stop_coordinates;
    // map stop_name -> map stop_names and distances to them
    std::unordered_map<std::string, std::unordered_map<std::string, int>> stop_distances;
    std::unordered_map<std::string, std::set<std::string>> stop_buses;
    std::unordered_map<std::string, RouteStatistic> route_statistics;
};

#endif