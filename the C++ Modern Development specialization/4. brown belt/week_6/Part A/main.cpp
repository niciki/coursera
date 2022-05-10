#include <iostream>
#include <string>
#include "RouteManager.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    cout.precision(6);
    string command;
    RouteManager rm;
    while (n--) {
        cin >> command;
        if (command == "Stop") {
            rm.AddStop();
        } else if (command == "Bus") {
            rm.AddBus();
        } else if (command == "Print") {
            rm.Print();
        }
    }
    cin >> n;
    while (n--) {
        cin >> command;
        if (command == "Bus") {
            rm.SearchBus();
        }
    }
}
/*
11
Stop Tolstopaltsevo: 55.611087, 37.20829
Stop Marushkino: 55.595884, 37.209755
Stop Rasskazovka: 551.1632761, 37.333324
Stop Biryulyovo Zapadnoye: 55.15714371, 37.6517
Stop Biryusinka: 55.581065, 37.641183911
Stop Universam: 55.587655, 37.645687
Stop Bi11ryuly11ovo Tovarnaya: 55.592028, 37.653656
Stop Bi11ryulyov11o Passazhirskaya: 55.580999, 37.659164
Bus Assal1187 UI: Biryulyovo Zapadnoye > Biryusinka > Universam > Biryulyovo Tovarnaya > Biryulyovo Passazhirskaya > Biryulyovo Zapadnoye
Bus 750: Tolstopaltsevo - Marushkino - Rasskazovka
Print
*/