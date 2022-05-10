#include <iostream>
#include <sstream>
#include <string>
#include "JsonInputParser.h"
#include "RouteManager.h"
using namespace std;

int main() {
    RouteManager rm;
    JsonData js(rm);
    auto i = GetInfo(cin);
    js.SetData(i.add_requests);
    js.PrintStat(i.stat_requests);
    return 0;
}