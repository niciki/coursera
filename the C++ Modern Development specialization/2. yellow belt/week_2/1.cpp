#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string type;
    is >> type;
    if (type == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count = 0;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (auto& stop : q.stops) {
        is >> stop;
        }
    } else if (type == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (type == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (type == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    string name;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.name != "") {
        for (auto& i : r.buses) {
        os << i << " ";
        }
    } else {
        os << "No stop";
    }
    return os;
}

struct StopsForBusResponse {
    string name;
    vector<string> stops;
    map<string, vector<string>> bus_for_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.name != "") {
        for (const auto& i : r.stops) {
        os << "Stop " << i << ": ";
        for (const auto& j : r.bus_for_stops.at(i)) {
            os << j << " ";
        }
        os << "\n";
        }
    } else {
        os << "No bus";
    }
    return os;
}

struct AllBusesResponse {
    vector<string> bus;
    map<string, vector<string>> stops_for_bus;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.bus.size()) {
        for (const auto& i : r.bus) {
        os << "Bus " << i << ": ";
        for (const auto& j : r.stops_for_bus.at(i)) {
            os << j << " ";
        }
        os << "\n";
        }
    } else {
        os << "No buses";
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        stops_to_buses[bus] = stops;
        for (const auto& stop : stops) {
        buses_to_stops[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
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

    StopsForBusResponse GetStopsForBus(const string& bus) const {
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

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse a;
        for (const auto& i : stops_to_buses) {
            a.bus.push_back(i.first);
            a.stops_for_bus[i.first] = i.second;
        }
        return a;
    }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}

/*
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
*/