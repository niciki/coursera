#ifndef ROUTE_MANAGER_H
#define ROUTE_MANAGER_H

#include <unordered_map>
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

class RouteManager{
public:
    void AddStop();
    void AddBus();
    void SearchBus() const;
    void Print() const;
    long double GetLength(const RouteStatistic& rs) const;
private:
    std::unordered_map<std::string, Coordinates> stop_coordinates;
    std::unordered_map<std::string, RouteStatistic> route_statistics;
};

#endif