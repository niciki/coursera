#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

struct Record {
    int64_t time;
    string hotel_name;
    int client_id;
    int rooms_count;
};

ostream& operator<<(ostream& os, Record& r) {
    os << r.time << " " << r.hotel_name << " " << r.client_id << " " << r.rooms_count;
    return os;
}

istream& operator>>(istream& is, Record& r) {
    is >> r.time >> r.hotel_name >> r.client_id >> r.rooms_count;
    return is;
}

class HotelManager {
public:

    void Add(Record&& r) {
        hotel_rooms_ordered[r.hotel_name] += r.rooms_count;
        client_rooms_ordered[r.hotel_name][r.client_id] += r.rooms_count;
        data.push(move(r));
        Update();
    }
    int GetClients(string hotel_name) {
        if (!data.size()) {
            return 0;
        }
        return client_rooms_ordered[hotel_name].size();
    }
    int GetRooms(string hotel_name) {
        if (!data.size()) {
            return 0;
        }
        return hotel_rooms_ordered[hotel_name];
    }
private:
    queue<Record> data;
    map<string, int> hotel_rooms_ordered;
    map<string, map<int, int>> client_rooms_ordered;
    void Update() {
        int64_t current_time = data.back().time;
        int n = 0;
        Record tmp;
        while(data.size() && data.front().time + 86399 < current_time) {
            tmp = data.front();
            client_rooms_ordered[tmp.hotel_name][tmp.client_id] -= tmp.rooms_count;
            if (!client_rooms_ordered[tmp.hotel_name][tmp.client_id]) {
                client_rooms_ordered[tmp.hotel_name].erase(tmp.client_id);
            }
            hotel_rooms_ordered[tmp.hotel_name] -= tmp.rooms_count;
            if (!hotel_rooms_ordered[tmp.hotel_name]) {
                hotel_rooms_ordered.erase(tmp.hotel_name);
            }
            data.pop();
        }
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    HotelManager hm;
    int n;
    cin >> n;
    string command;
    Record new_;
    while (n--) {
        cin >> command;
        if (command == "BOOK") {
            cin >> new_;
            hm.Add(move(new_));
        } else if (command == "CLIENTS") {
            string hotel_name;
            cin >> hotel_name;
            cout << hm.GetClients(move(hotel_name)) << "\n";
        } else if (command == "ROOMS") {
            string hotel_name;
            cin >> hotel_name;
            cout << hm.GetRooms(move(hotel_name)) << "\n";
        }
    }
}
