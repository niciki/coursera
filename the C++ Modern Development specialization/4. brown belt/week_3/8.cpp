#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


struct Email {
    string from;
    string to;
    string body;
};


class Worker {
public:
    virtual ~Worker() = default;
    virtual void Process(unique_ptr<Email> email) = 0;
    virtual void Run() {
        // только первому worker-у в пайплайне нужно это имплементировать
        throw logic_error("Unimplemented");
    }

protected:
    // реализации должны вызывать PassOn, чтобы передать объект дальше
    // по цепочке обработчиков
    void PassOn(unique_ptr<Email> email) const {
        if (next_worker != nullptr) {
            next_worker->Process(move(email));
        }
    }

public:
    void SetNext(unique_ptr<Worker> next) {
        next_worker = move(next);
    }
private:
    unique_ptr<Worker> next_worker;
};


class Reader : public Worker {
public:
    explicit Reader(istream& i): is(i) {}
    void Process(unique_ptr<Email> email) override {}
    void Run() override {
        while (1) {
            auto email = make_unique<Email>();
            getline(is, email->from);
            getline(is, email->to);
            getline(is, email->body);
            if (!is) {
                break;
            }
            PassOn(move(email));
        }
    }
private:
    istream& is;
};


class Filter : public Worker {
public:
    using Function = function<bool(const Email&)>;
    explicit Filter(Function func): f(move(func)) {}
    void Process(unique_ptr<Email> email) override {
        if (f(*email)) {
            PassOn(move(email));
        }
    }
private:
    Function f;
};


class Copier : public Worker {
public:
    explicit Copier(string s): recipient(move(s)) {}
    void Process(unique_ptr<Email> email) override {
        if (recipient != email->to) {
            Email tmp = *email;
            tmp.to = recipient;
            unique_ptr<Email> tmp_ = make_unique<Email>(tmp);
            PassOn(move(email));
            PassOn(move(tmp_));
        } else {
            PassOn(move(email));
        }
    }
private:
    string recipient;
};


class Sender : public Worker {
public:
    explicit Sender(ostream& o): os(o) {}
    void Process(unique_ptr<Email> email) override {
        os << email->from << "\n" << email->to << "\n" << email->body << "\n";
        PassOn(move(email));
    }
private:
    ostream& os;
};


// реализуйте класс
class PipelineBuilder {
public:
    // добавляет в качестве первого обработчика Reader
    explicit PipelineBuilder(istream& in) {
        papeline.push_back(make_unique<Reader>(in));
    }

    // добавляет новый обработчик Filter
    PipelineBuilder& FilterBy(Filter::Function filter) {
        papeline.push_back(make_unique<Filter>(move(filter)));
        return *this;
    }

    // добавляет новый обработчик Copier
    PipelineBuilder& CopyTo(string recipient) {
        papeline.push_back(make_unique<Copier>(move(recipient)));
        return *this;
    }

    // добавляет новый обработчик Sender
    PipelineBuilder& Send(ostream& out) {
        papeline.push_back(make_unique<Sender>(out));
        return *this;
    }

    // возвращает готовую цепочку обработчиков
    unique_ptr<Worker> Build() {
        for (auto i = prev(papeline.end()); i != papeline.begin(); i = prev(i)) {
            prev(i)->get()->SetNext(move(*i));
        }
        return move(papeline.front());
    }
private:
    vector<unique_ptr<Worker>> papeline;
};


void TestSanity() {
    string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "erich@example.com\n"
        "I do not make mistakes of that kind\n"
    );
    istringstream inStream(input);
    ostringstream outStream;

    PipelineBuilder builder(inStream);
    builder.FilterBy([](const Email& email) {
        return email.from == "erich@example.com";
    });
    builder.CopyTo("richard@example.com");
    builder.Send(outStream);
    auto pipeline = builder.Build();

    pipeline->Run();

    string expectedOutput = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "erich@example.com\n"
        "richard@example.com\n"
        "Are you sure you pressed the right button?\n"
    );

    ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSanity);
    return 0;
}
