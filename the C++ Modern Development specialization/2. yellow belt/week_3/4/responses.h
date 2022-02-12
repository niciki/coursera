#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct BusesForStopResponse {
    string name;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string name;
    vector<string> stops;
    map<string, vector<string>> bus_for_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    vector<string> bus;
    map<string, vector<string>> stops_for_bus;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);