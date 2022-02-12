#include "test_runner.h"
#include "profile.h"

#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <future>
#include <functional>
using namespace std;

struct Stats {
    map<string, int> word_frequences;
    void operator += (const Stats& other) {
        for (const auto& [first, second]: other.word_frequences) {
            word_frequences[first] = (word_frequences.count(first) ? (word_frequences[first] + second) : second);
        }
    }
};

vector<string> ParseString(const string& s) {
    stringstream os;
    os << s;
    string tmp;
    vector<string> data;
    while (getline(os, tmp, ' ')) {
        data.push_back(move(tmp));
    }
    return data;
}

Stats GetStat(set<string> key_words, vector<string> s) {
    Stats tmp_stat;
    for (auto& j: s) {
        for (auto& i: ParseString(j)) {
            if (key_words.count(i)) {
                ++tmp_stat.word_frequences[i];
            }
        }
    }
    return tmp_stat;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
    Stats statistics;
    size_t max_buf_size = 100000;
    vector<string> buffer;
    buffer.reserve(max_buf_size);
    string s;
    vector<future<Stats>> tmp_statistics;
    while (getline(input, s)) {
        if (buffer.size() <= max_buf_size) {
            buffer.push_back(move(s));
        } else {
            tmp_statistics.push_back(async(GetStat, key_words, move(buffer)));
            buffer.reserve(max_buf_size);
        }
    }
    tmp_statistics.push_back(async(GetStat, key_words, move(buffer)));
    for (auto& i: tmp_statistics) {
        statistics += i.get();
    }
    return statistics;
}

void TestBasic() {
    const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

    stringstream ss;
    ss << "this new yangle service really rocks\n";
    ss << "It sucks when yangle isn't available\n";
    ss << "10 reasons why yangle is the best IT company\n";
    ss << "yangle rocks others suck\n";
    ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

    const auto stats = ExploreKeyWords(key_words, ss);
    const map<string, int> expected = {
        {"yangle", 6},
        {"rocks", 2},
        {"sucks", 1}
    };
    ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestBasic);
}
