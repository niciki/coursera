#include "json.h"
#include <iostream>

using namespace std;
namespace Json {

    Document::Document(Node root) : root(move(root)) {
    }

    const Node& Document::GetRoot() const {
        return root;
    }

    Node LoadNode(istream& input);

    Node LoadArray(istream& input) {
        vector<Node> result;

        for (char c; input >> c && c != ']'; ) {
            if (c != ',') {
                input.putback(c);
            }
            result.push_back(LoadNode(input));
        }
        return Node(move(result));
    }
    Node LoadNumber(istream& input) {
        long double resultDouble = 0;
        input >> resultDouble;
        return Node(resultDouble);
    }
    Node LoadBool(istream& input) {
        string str;
        input >> str;
        bool value = false;
        if (str[0] == 't') {
            value = true;
        }

        return Node(value);
    }
    Node LoadString(istream& input) {
        string line;
        getline(input, line, '"');
        return Node(move(line));
    }
    Node LoadDict(istream& input) {
        map<string, Node> result;
        for (char c; input >> c && c != '}'; ) {
            if (c == ',') {
                input >> c;
            }

            string key = LoadString(input).AsString();
            input >> c;
            result.emplace(move(key), LoadNode(input));
        }
        return Node(move(result));
    }
    Node LoadNode(istream& input) {
        char c;
        input >> c;

        if (c == '[') {
            return LoadArray(input);
        } else if (c == '{') {
            return LoadDict(input);
        } else if (c == '"') {
            return LoadString(input);
        } else if (c == 't' || c == 'f') {
            input.putback(c);
            return LoadBool(input);
        } else {
            input.putback(c);
            return LoadNumber(input);
        }
    }
    Document Load(istream& input){
        return Document {LoadNode(input)};
    }
    vector<string> ParseInput(istream& input) {
        vector<string> answ;
        string buffer;
        getline(input, buffer, '[');
        buffer.clear();
        int bracket_counter = 0;
        while (1) {
            char c = input.get();
            if (c == '{') {
                ++bracket_counter;
            }
            if (bracket_counter > 0) {
                buffer += c;
            }
            if (c == '}') {
                --bracket_counter;
                if (!bracket_counter) {
                    answ.push_back(move(buffer));
                }
            }
            if (bracket_counter <= 0 && c == ']') {
                return answ;
            }
        }
    }
}