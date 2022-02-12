#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Stats {
public:
    Stats();
    void AddMethod(string_view method);
    void AddUri(string_view uri);
    const map<string_view, int>& GetMethodStats() const;
    const map<string_view, int>& GetUriStats() const;
private:
    map<string_view, int> uri_count;
    map<string_view, int> method_count;
    set<string> uris = {"/", "/order", "/product", "/basket", "/help", "unknown"};
    set<string> methods = {"GET", "PUT", "POST", "DELETE", "UNKNOWN"};
};

HttpRequest ParseRequest(string_view line);