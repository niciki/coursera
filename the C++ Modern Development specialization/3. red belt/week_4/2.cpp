#include "test_runner.h"
#include <string>
#include <vector>
#include <string_view>

using namespace std;

class Translator {
public:
    void Add(string_view source, string_view target) {
        string_view source_ = Adding(source);
        string_view target_ = Adding(target);
        data_forward[source_] = target_;
        data_backward[target_] = source_;
    }
    string_view TranslateForward(string_view source) const {
        return Translation(data_forward, source);
    }
    string_view TranslateBackward(string_view target) const {
        return Translation(data_backward, target);
    }

private:
    map<string_view, string_view> data_forward;
    map<string_view, string_view> data_backward;
    string_view Adding(string_view s) {
        if (data.count(string(s))) {
            return *data.find(string(s));
        } else {
            return *(data.emplace(s).first);
        }
    }
    string_view Translation(const map<string_view, string_view>& map_, string_view word) const {
        if (const auto it = map_.find(word); it != map_.end()) {
            return it->second;
        } else {
            return {};
        }
    }
    set<string> data;
};

void TestSimple() {
    Translator translator;
    translator.Add(string("okno"), string("window"));
    translator.Add(string("stol"), string("table"));

    ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
    ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
    ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSimple);
    return 0;
}
