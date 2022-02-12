#include "test_runner.h"

#include <vector>

using namespace std;

// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = vector<Token>;

// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
    vector<Sentence<Token>> res;
    Sentence<Token> tmp;
    for (auto& i: tokens) {
        if (!i.IsEndSentencePunctuation()) {
            if (tmp.size() && tmp.back().IsEndSentencePunctuation()) {
                res.push_back(move(tmp));
            }
        }
        tmp.push_back(move(i));
    }
    if (tmp.size()) {
        res.push_back(move(tmp));
    }
    return res;
    // Напишите реализацию функции, не копируя объекты типа Token
}

/*
// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
    vector<Sentence<Token>> res;
    Sentence<Token> tmp;
    for (auto& i: tokens) {
        if (i.IsEndSentencePunctuation()) {
            tmp.push_back({move(i)});
        } else {
            if (tmp.size() && tmp.back().IsEndSentencePunctuation()) {
                res.push_back(move(tmp));
            }
            tmp.push_back(move(i));
        }
    }
    if (tmp.size()) {
        res.push_back(move(tmp));
    }
    return res;
    // Напишите реализацию функции, не копируя объекты типа Token
}
*/

struct TestToken {
    string data;
    bool is_end_sentence_punctuation = false;

    bool IsEndSentencePunctuation() const {
        return is_end_sentence_punctuation;
    }
    bool operator==(const TestToken& other) const {
        return data == other.data && is_end_sentence_punctuation == other.is_end_sentence_punctuation;
    }
};

ostream& operator<<(ostream& stream, const TestToken& token) {
    return stream << token.data;
}

// Тест содержит копирования объектов класса TestToken.
// Для проверки отсутствия копирований в функции SplitIntoSentences
// необходимо написать отдельный тест.
void TestSplitting() {
    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!"}})),
        vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!"}}
        })
    );

    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}})),
        vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!", true}}
        })
    );

    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {".", true}})),
        vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}},
            {{"Without"}, {"copies"}, {".", true}},
        })
    );
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSplitting);
    return 0;
}
