#include "stats.h"

Stats::Stats() {
    for (auto& i : uris) {
            uri_count[i] = 0;
    }
    for (auto& i : methods) {
        method_count[i] = 0;
    }
}

void Stats::AddMethod(string_view method) {z
    string method_(method);
    set<string> set_ = {"GET", "PUT", "POST", "DELETE"};
    if (set_.count(method_)) {
        ++method_count[string_view(*methods.find(method_))];
    } else {
        ++method_count[string_view(*methods.find("UNKNOWN"))];
    }
}

void Stats::AddUri(string_view uri) {
    string uri_(uri);
    set<string> set_ = {"/", "/order", "/product", "/basket", "/help"};
    if (set_.count(uri_)) {
        ++uri_count[string_view(*uris.find(uri_))];
    } else {
        ++uri_count[string_view(*uris.find("unknown"))];
    }
}

const map<string_view, int>& Stats::GetMethodStats() const {
    return method_count;
}
const map<string_view, int>& Stats::GetUriStats() const {
    return uri_count;
}

HttpRequest ParseRequest(string_view line) {
    if (line.front() == ' ') {
        line = line.substr(line.find_first_not_of(' '));
    }
    HttpRequest hr;
    size_t first_space, second_space;
    first_space = line.find_first_of(" ");
    hr.method = line.substr(0, first_space);
    second_space = line.find_last_of(" ");
    hr.uri = line.substr(first_space + 1, second_space - first_space - 1);
    hr.protocol = line.substr(second_space + 1);
    return hr;
}