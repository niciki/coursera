#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <cstdint>
#include <queue>

#include "test_runner.h"

using namespace std;

struct Record {
    int64_t time;
    string hotel_name;
    int client_id;
    int room_count;
};

class Hotels {
public:
    void Book(const int64_t& time, const string& hotel_name, const int& client_id, const int& room_count) {
        data.push({time, hotel_name, client_id, room_count});
        clients[hotel_name][client_id] += room_count;
        rooms[hotel_name] += room_count;
        Update(time);
    }
    int Clients(const string& hotel_name) const {
        try {
            return clients.at(hotel_name).size();
        } catch (...) {
            return 0;
        }
    }
    int Rooms(const string& hotel_name) const {
        try {
            return rooms.at(hotel_name);
        } catch (...) {
            return 0;
        }
    }
private:
    void Update(const int64_t& time) {
        while (data.size() && data.front().time + 86399 < time) {
            clients[data.front().hotel_name][data.front().client_id] -= data.front().room_count;
            if (!clients[data.front().hotel_name][data.front().client_id]) {
                clients[data.front().hotel_name].erase(data.front().client_id);
            }
            rooms[data.front().hotel_name] -= data.front().room_count;
            data.pop();
        }
    }
    map<string, map<int, int>> clients; // hotel_name -> <client_id, room_count>
    map<string, int> rooms; // hotel_name -> number of booked rooms
    queue<Record> data;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    Hotels h;
    int n;
    cin >> n;
    string command;
    int64_t time;
    int client_id, room_count;
    string hotel_name;
    while (n--) {
        cin >> command;
        if (command == "BOOK") {
            cin >> time >> hotel_name >> client_id >> room_count;
            h.Book(time, hotel_name, client_id, room_count);
        } else if (command == "CLIENTS") {
            cin >> hotel_name;
            cout << h.Clients(hotel_name) << "\n";
        } else if (command == "ROOMS") {
            cin >> hotel_name;
            cout << h.Rooms(hotel_name) << "\n";
        }
    }
}

// Correct submission if time can dicrease, but TL

/*
class Hotels {
public:
    void book(const int64_t& time, const string& hotel_name, const int& client_id, const int& room_count) {
        bool b = 0;
        if (data.count(time)) {
            if (data[time].count(hotel_name)) {
                if (data[time][hotel_name].count(client_id)) {
                    data[time][hotel_name][client_id] += room_count;
                    b = 1;
                }
            }
        }
        if (!b) {
            data[time][hotel_name][client_id] = room_count;
        }
        cur_time = time;
    }
    int clients(const string& hotel_name) const {
        auto it = data.lower_bound(cur_time - 86399);
        auto it_last = data.upper_bound(cur_time);
        set<int> clients;
        for (auto i = it; i != it_last; ++i) {
            if (i->second.count(hotel_name)) {
                for (const auto& j: i->second.at(hotel_name)) {
                    clients.insert(j.first);
                }
            }
        }
        return clients.size();
    }
    int rooms(const string& hotel_name) const {
        auto it = data.lower_bound(cur_time - 86399);
        auto it_last = data.upper_bound(cur_time);
        int n = 0;
        for (auto i = it; i != it_last; ++i) {
            if (i->second.count(hotel_name)) {
                for (const auto& j: i->second.at(hotel_name)) {
                    n += j.second;
                }
            }
        }
        return n;
    }
private:
    int64_t cur_time;
    map<int64_t, map<string, map<int, int>>> data;
};
*/