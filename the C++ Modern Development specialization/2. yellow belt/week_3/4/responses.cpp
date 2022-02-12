#include "responses.h"

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