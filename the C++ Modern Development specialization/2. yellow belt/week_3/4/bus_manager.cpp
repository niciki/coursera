#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    stops_to_buses[bus] = stops;
    for (const auto& stop : stops) {
    buses_to_stops[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse bs;
    if (buses_to_stops.count(stop)) {
        bs.name = stop;
        bs.buses = buses_to_stops.at(stop);
    } else {
        bs.name = "";
        bs.buses = {};
    }
    return bs;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse sb;
    if (stops_to_buses.count(bus)) {
        sb.name = bus;
        sb.stops = stops_to_buses.at(bus);
        for (const auto& i : sb.stops) {
            if (buses_to_stops.count(i)) {
                for (const auto& j : buses_to_stops.at(i)) {
                    if (j != bus) {
                        sb.bus_for_stops[i].push_back(j);
                    }
                }
            }
            if (sb.bus_for_stops[i].size() == 0) {
                sb.bus_for_stops[i] = {"no interchange"};
            }
        }
    } else {
        sb.name = "";
        sb.stops = {};
        sb.bus_for_stops = {};
    }
    return sb;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse a;
    for (const auto& i : stops_to_buses) {
        a.bus.push_back(i.first);
        a.stops_for_bus[i.first] = i.second;
    }
    return a;
}