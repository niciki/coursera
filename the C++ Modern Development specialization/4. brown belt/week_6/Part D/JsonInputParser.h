#ifndef JSON_INPUT_PARSER_H
#define JSON_INPUT_PARSER_H

#include "json.h"
#include "RouteManager.h"
#include <string>
#include <vector>


struct Requests {
    std::vector<std::string> add_requests;
    std::vector<std::string> stat_requests;
};

class JsonData {
public:
    JsonData() = default;
    JsonData(RouteManager& rm_): rm(rm_) {};
    void SetData(const std::vector<std::string>& add_requests);
    void PrintStat(const std::vector<std::string>& stat_requests) const;
private:
    RouteManager& rm;
};
Requests GetInfo(std::istream& input);

#endif