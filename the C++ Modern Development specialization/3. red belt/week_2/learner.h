#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Learner {
 private:
  set<string> unique_words;

 public:
    int Learn(const vector<string>& words) {
        int newWords = unique_words.size();
        for (const auto& word : words) {
            if (!unique_words.count(word)) {
                unique_words.insert(word);
            }
        }
        return unique_words.size() -newWords;
    }

    vector<string> KnownWords() {
        return {unique_words.begin(), unique_words.end()};
    }
};
