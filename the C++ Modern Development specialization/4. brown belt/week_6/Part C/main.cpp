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
        } else if (command == "Stop") {
            rm.SearchStop();
        }
    }
}