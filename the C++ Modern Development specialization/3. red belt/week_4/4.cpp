#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor() {
        id = data.end();
    }

    void Left() {
        if (data.size()) {
            if (id != data.begin()) {
                id = prev(id);
            }
        }
    }
    void Right() {
        if (data.size()) {
            if (id != data.end()) {
                id = next(id);
            }
        }
    }
    void Insert(char token) {
        data.insert(id, token);
    }
    void Cut(size_t tokens = 1) {
        buf.clear();
        if (tokens) {
            if (distance(id, data.end()) < tokens) {
                for (auto i = id; i != data.end(); i = next(i)) {
                    buf.push_back(*i);
                }
                id = data.erase(id, data.end());
            } else {
                for (auto i = id; i != next(id, tokens); i = next(i)) {
                    buf.push_back(*i);
                }
                id = data.erase(id, next(id, tokens));
            }
        }
    }
    void Copy(size_t tokens = 1) {
        buf.clear();
        if (tokens) {
            if (distance(data.end(), id) < tokens) {
                for (auto i = id; i != data.end(); i = next(i)) {
                    buf.push_back(*i);
                }
            } else {
                for (auto i = id; i != next(data.begin(), tokens); i = next(i)) {
                    buf.push_back(*i);
                }
            }
        }
    }
    void Paste() {
       data.insert(id, buf.begin(), buf.end());
       //id = next(id, buf.size());
    }
    string GetText() const {
        //cout << distance(data.begin(), id) << "\n";
        return {data.begin(), data.end()};
    }
private:
    list<char> data;
    list<char> buf;
    list<char>::iterator id;
};

void TypeText(Editor& editor, const string& text) {
    for(char c : text) {
        editor.Insert(c);
    }
}

void TestEditing() {
    {
        Editor editor;

        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        for(size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }
        editor.Cut(first_part_len);
        for(size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }
        TypeText(editor, ", ");
        editor.Paste();
        editor.Left();
        editor.Left();
        editor.Cut(3);

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");
        editor.Left();
        editor.Left();
        editor.Left();
        editor.Cut(1);
        editor.Right();
        editor.Paste();

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for(char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
    Editor editor;

    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestEditing);
    RUN_TEST(tr, TestReverse);
    RUN_TEST(tr, TestNoText);
    RUN_TEST(tr, TestEmptyBuffer);
    return 0;
}

/* right decision with strings but TL
class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor() {}
    void Left() {
        if (left != "") {
            right.insert(right.begin(), left.back());
            left.erase(left.end() - 1);
            --id;
        }
    }
    void Right() {
        if (right != "") {
            left += right.front();
            ++id;
            right = string(right.begin() + 1, right.end());
        }
    }
    void Insert(char token) {
        left += token;
        ++id;
    }
    void Cut(size_t tokens = 1) {
        if (right.size() < tokens) {
            buf = string(right.begin(), right.end());
            right.erase(right.begin(), right.end());
        } else {
            buf = string(right.begin(), right.begin() + tokens);
            right.erase(right.begin(), right.begin() + tokens);
        }
    }
    void Copy(size_t tokens = 1) {
        buf = string(right.begin(), right.begin() + tokens);
    }
    void Paste() {
       left += buf;
       id += buf.size();
    }
    string GetText() const {
        return left + right;
    }
private:
    string left = "";
    string right = "";
    string buf= "";
    int id = 0;
};

*/