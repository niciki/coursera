#include "search_server.h"
#include "parse.h"
#include "test_runner.h"
// #include "profile.h"

#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <thread>
using namespace std;

void TestFunctionality(const vector<string>& docs, const vector<string>& queries, const vector<string>& expected) {
    istringstream docs_input(Join('\n', docs));
    istringstream queries_input(Join('\n', queries));

    SearchServer srv;
    {
        // LOG_DURATION("UPDATE DOC");
        srv.UpdateDocumentBase(docs_input);
    }
    ostringstream queries_output;
    {
        // LOG_DURATION("ADD QUERIES STREAM");
        srv.AddQueriesStream(queries_input, queries_output);
    }


    const string result = queries_output.str();
    const auto lines = SplitBy(Strip(result), '\n');
    ASSERT_EQUAL(lines.size(), expected.size());
    for (size_t i = 0; i < lines.size(); ++i) {
        ASSERT_EQUAL(lines[i], expected[i]);
    }
}

void TestSerpFormat() {
    const vector<string> docs = {
        "london is the capital of great britain",
        "i am travelling down the river"
    };
    const vector<string> queries = {"london", "the"};
    const vector<string> expected = {
        "london: {docid: 0, hitcount: 1}",
        Join(' ', vector{
        "the:",
        "{docid: 0, hitcount: 1}",
        "{docid: 1, hitcount: 1}"
        })
    };

    TestFunctionality(docs, queries, expected);
}

void TestTop5() {
    const vector<string> docs = {
        "milk a",
        "milk b",
        "milk c",
        "milk d",
        "milk e",
        "milk f",
        "milk g",
        "water a",
        "water b",
        "fire and earth"
    };

    const vector<string> queries = {"milk", "water", "rock"};
    const vector<string> expected = {
        Join(' ', vector{
        "milk:",
        "{docid: 0, hitcount: 1}",
        "{docid: 1, hitcount: 1}",
        "{docid: 2, hitcount: 1}",
        "{docid: 3, hitcount: 1}",
        "{docid: 4, hitcount: 1}"
        }),
        Join(' ', vector{
        "water:",
        "{docid: 7, hitcount: 1}",
        "{docid: 8, hitcount: 1}",
        }),
        "rock:",
    };
    TestFunctionality(docs, queries, expected);
}

void TestHitcount() {
    const vector<string> docs = {
        "the river goes through the entire city there is a house near it",
        "the wall",
        "walle",
        "is is is is",
    };
    const vector<string> queries = {"the", "wall", "all", "is", "the is"};
    const vector<string> expected = {
        Join(' ', vector{
        "the:",
        "{docid: 0, hitcount: 2}",
        "{docid: 1, hitcount: 1}",
        }),
        "wall: {docid: 1, hitcount: 1}",
        "all:",
        Join(' ', vector{
        "is:",
        "{docid: 3, hitcount: 4}",
        "{docid: 0, hitcount: 1}",
        }),
        Join(' ', vector{
        "the is:",
        "{docid: 3, hitcount: 4}",
        "{docid: 0, hitcount: 3}",
        "{docid: 1, hitcount: 1}",
        }),
    };
    TestFunctionality(docs, queries, expected);
}

void TestRanking() {
    const vector<string> docs = {
        "london is the capital of great britain",
        "paris is the capital of france",
        "berlin is the capital of germany",
        "rome is the capital of italy",
        "madrid is the capital of spain",
        "lisboa is the capital of portugal",
        "bern is the capital of switzerland",
        "moscow is the capital of russia",
        "kiev is the capital of ukraine",
        "minsk is the capital of belarus",
        "astana is the capital of kazakhstan",
        "beijing is the capital of china",
        "tokyo is the capital of japan",
        "bangkok is the capital of thailand",
        "welcome to moscow the capital of russia the third rome",
        "amsterdam is the capital of netherlands",
        "helsinki is the capital of finland",
        "oslo is the capital of norway",
        "stockgolm is the capital of sweden",
        "riga is the capital of latvia",
        "tallin is the capital of estonia",
        "warsaw is the capital of poland",
    };

    const vector<string> queries = {"moscow is the capital of russia"};
    const vector<string> expected = {
        Join(' ', vector{
        "moscow is the capital of russia:",
        "{docid: 7, hitcount: 6}",
        "{docid: 14, hitcount: 6}",
        "{docid: 0, hitcount: 4}",
        "{docid: 1, hitcount: 4}",
        "{docid: 2, hitcount: 4}",
        })
    };
    TestFunctionality(docs, queries, expected);
}

void TestBasicSearch() {
    vector<string> docs_;
    { //LOG_DURATION("TMP");
    docs_ = {
        "we are ready to go",
        "come on everybody shake you hands",
        "i love this game",
        "just like exception safety is not about writing try catch everywhere in your code move semantics are not about typing double ampersand everywhere in your code",
        "daddy daddy daddy dad dad dad",
        "tell me the meaning of being lonely",
        "just keep track of it",
        "how hard could it be",
        "it is going to be legen wait for it dary legendary",
        "we dont need no education"
        "london is the capital of great britain",
        "paris is the capital of france",
        "berlin is the capital of germany",
        "rome is the capital of italy",
        "madrid is the capital of spain",
        "lisboa is the capital of portugal",
        "bern is the capital of switzerland",
        "moscow is the capital of russia",
        "kiev is the capital of ukraine",
        "minsk is the capital of belarus",
        "astana is the capital of kazakhstan",
        "beijing is the capital of china",
        "tokyo is the capital of japan",
        "bangkok is the capital of thailand",
        "welcome to moscow the capital of russia the third rome",
        "amsterdam is the capital of netherlands",
        "helsinki is the capital of finland",
        "oslo is the capital of norway",
        "stockgolm is the capital of sweden",
        "riga is the capital of latvia",
        "tallin is the capital of estonia",
        "warsaw is the capital of poland",
        "1we 1are 1ready 1to 1go",
        "1come 1on e1verybody sha1ke y1ou h1ands",
        "1i love1 thi1s g1ame",
        "ju1st l1ike e1xception saf1ety i1s n1t ab1out 1riting tr1y catc1h ev1rywhere i1n y1ur cod1e mov1e sema1ntics a1re n1ot abo1ut typ1ing do1uble amp1ersand ev1erywhere 1in you1r co1de",
        "da1ddy 1daddy da1ddy da1d dad1 1dad",
        "te1ll m1e th1e meani1ng 1of bei1g lon1ely",
        "jus1t 1eep tr1ack1 o1f it1",
        "ho1w ha1rd co1uld i1t b1e",
        "i1t is1 go1ing 1to b1e lege1n wa1it fo1r i1t da1ry lege1ndary",
        "w1e do1nt ne1ed n1o edu1cation"
        "lond1on i1s t1he cap1ital o1f g1reat b1ritain",
        "par1s is1 th1e ca1pital of1 fran1ce"
    };
    for (int i = 0; i < 16000; ++i) {
        docs_.push_back(to_string(i));
    }
    }

    const vector<string> docs(docs_);

    const vector<string> queries = {
        "we need some help",
        "it",
        "i love this game",
        "tell me why",
        "dislike",
        "about"
    };

    const vector<string> expected = {
        Join(' ', vector{
        "we need some help:",
        "{docid: 9, hitcount: 2}",
        "{docid: 0, hitcount: 1}"
        }),
        Join(' ', vector{
        "it:",
        "{docid: 8, hitcount: 2}",
        "{docid: 6, hitcount: 1}",
        "{docid: 7, hitcount: 1}",
        }),
        "i love this game: {docid: 2, hitcount: 4}",
        "tell me why: {docid: 5, hitcount: 2}",
        "dislike:",
        "about: {docid: 3, hitcount: 2}",
    };
    TestFunctionality(docs, queries, expected);
}

int main() {
    TestRunner tr;
    {
        // LOG_DURATION("f");
        RUN_TEST(tr, TestSerpFormat);
    }
    {
        // LOG_DURATION("s");
        RUN_TEST(tr, TestTop5);
    }
    {
        // LOG_DURATION("3");
        RUN_TEST(tr, TestHitcount);
    }
    {
        // LOG_DURATION("4");
        RUN_TEST(tr, TestRanking);
    }
    {
        // LOG_DURATION("5");
        RUN_TEST(tr, TestBasicSearch);
    }
}
