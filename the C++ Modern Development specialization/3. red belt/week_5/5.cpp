#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <typename T>
class PriorityCollection {
public:
    using Id = size_t;/* тип, используемый для идентификаторов */;

    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object) {
        data.emplace_back(0, move(object));
        set_priority.insert({0, data.size() - 1});
        return data.size() - 1;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,
            IdOutputIt ids_begin) {
        for (auto i = range_begin; i != range_end; i = next(i)) {
            *ids_begin++ = Add(move(*i));
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const {
        return data[id].first >= 0;
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const {
        return data.at(id).second;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id) {
        pair<int, Id> tmp = {data[id].first, id};
        set_priority.erase(tmp);
        ++tmp.first;
        set_priority.insert(tmp);
        ++data[id].first;
    }
    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const {
        return {data.at(prev(set_priority.end())->second).second, data.at(prev(set_priority.end())->second).first};
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax() {
        auto tmp = move(data[prev(set_priority.end())->second]);
        //data.erase(next9data.begin() + prev(set_priority.end())->second);
        data[prev(set_priority.end())->second] = {-1, T()};
        set_priority.erase(prev(set_priority.end()));
        return {move(tmp.second), tmp.first};
    }

private:
    vector<pair<int, T>> data;
    set<pair<int, Id>> set_priority;
};


class StringNonCopyable : public string {
public:
    using string::string;  // Позволяет использовать конструкторы строки
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
    PriorityCollection<StringNonCopyable> strings;
    const auto white_id = strings.Add("white");
    const auto yellow_id = strings.Add("yellow");
    const auto red_id = strings.Add("red");

    strings.Promote(yellow_id);
    for (int i = 0; i < 2; ++i) {
        strings.Promote(red_id);
    }
    strings.Promote(yellow_id);
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "yellow");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "white");
        ASSERT_EQUAL(item.second, 0);
    }
    {
        vector<StringNonCopyable> s;
        s.push_back("a");
        s.push_back("b");
        s.push_back("c");
        PriorityCollection<StringNonCopyable> strings2;
        vector<PriorityCollection<StringNonCopyable>::Id> ids(s.size());
        strings2.Add(s.begin(), s.end(), ids.begin());

        const auto item = strings2.GetMax();
        ASSERT_EQUAL(item.first, "c");
        ASSERT_EQUAL(item.second, 0);
        auto item_ = strings2.PopMax();
        ASSERT_EQUAL(item_.first, "c");
        ASSERT_EQUAL(item_.second, 0);
        item_ = strings2.PopMax();
        ASSERT_EQUAL(item_.first, "b");
        ASSERT_EQUAL(item_.second, 0);
        item_ = strings2.PopMax();
        ASSERT_EQUAL(item_.first, "a");
        ASSERT_EQUAL(item_.second, 0);
    }
    {
        vector<StringNonCopyable> s;
        s.push_back("a");
        s.push_back("b");
        s.push_back("c");
        PriorityCollection<StringNonCopyable> strings2;
        vector<PriorityCollection<StringNonCopyable>::Id> ids(s.size());
        strings2.Add(s.begin(), s.end(), ids.begin());

        const auto item = strings2.GetMax();
        ASSERT_EQUAL(item.first, "c");
        ASSERT_EQUAL(item.second, 0);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestNoCopy);
    return 0;
}


// Ok with list, but TL
/*
template <typename T>
class PriorityCollection {
public:
    using Id = size_t; //тип, используемый для идентификаторов ;

    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object) {
        if (!data.size() || next(data.begin(), max)->second == 0) {
            data.push_back({move(object), 0});
            max = data.size() - 1;
        } else {
            data.push_back({move(object), 0});
        }
        return data.size() - 1;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,
            IdOutputIt ids_begin) {
        while (range_begin != range_end) {
            *ids_begin++ = Add(std::move(*range_begin++));
        }
        if (data.size()) {
            max = data.size() - 1;
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const {
        return (id >= 0) && (id < data.size());
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const {
        return next(data.begin(), id)->first;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id) {
        ++(next(data.begin(), id)->second);
        if ((next(data.begin(), id)->second == (next(data.begin(), max)->second)) && id > max) {
            max = id;
        } else if ((next(data.begin(), id)->second > (next(data.begin(), max)->second))) {
            max = id;
        }
    }
    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const {
        return *next(data.begin(), max);
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax() {
        pair<T, int> res{move(next(data.begin(), max)->first), next(data.begin(), max)->second};
        data.erase(next(data.begin(), max));
        Id tmp = 0;
        for (auto i = data.begin(); i != data.end(); i = next(i)) {
            if (next(data.begin(), tmp)->second <= i->second) {
                tmp = distance(data.begin(), i);
            }
        }
        max = tmp;
        return res;
    }

private:
    Id max;
    list<pair<T, int>> data;
};
*/