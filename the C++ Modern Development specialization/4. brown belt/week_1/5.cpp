#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Record {
    string id;
    string title;
    string user;
    int timestamp;
    int karma;
};

// Реализуйте этот класс
class Database {
public:
    bool Put(const Record& record);
    const Record* GetById(const string& id) const;
    bool Erase(const string& id);

    template <typename Callback>
    void RangeByTimestamp(int low, int high, Callback callback) const;

    template <typename Callback>
    void RangeByKarma(int low, int high, Callback callback) const;

    template <typename Callback>
    void AllByUser(const string& user, Callback callback) const;

private:
    struct Date {
        Record record;
        multimap<int, Record*>::iterator data_sort_timestamp_iter;
        multimap<int, Record*>::iterator data_sort_karma_iter;
        multimap<string, Record*>::iterator data_sort_user_iter;
    };
    unordered_map<string, Date> data_sort_id;
    multimap<int, Record*> data_sort_timestamp;
    multimap<int, Record*> data_sort_karma;
    multimap<string, Record*> data_sort_user;
};

bool Database::Put(const Record& record) {
    const auto& [place_iterator, data_insert_bool] = data_sort_id.insert({record.id, {record, {}, {}, {}}});
    if (data_insert_bool) {
        place_iterator->second.data_sort_timestamp_iter = data_sort_timestamp.insert({record.timestamp, &place_iterator->second.record});
        place_iterator->second.data_sort_user_iter = data_sort_user.insert({record.user, &place_iterator->second.record});
        place_iterator->second.data_sort_karma_iter = data_sort_karma.insert({record.karma, &place_iterator->second.record});
        return true;
    } else {
        return false;
    }
}

const Record* Database::GetById(const string& id) const {
    auto i = data_sort_id.find(id);
    if (i == data_sort_id.end()) {
        return nullptr;
    } else {
        return &i->second.record;
    }
}

bool Database::Erase(const string& id) {
    auto i = data_sort_id.find(id);
    if (i != data_sort_id.end()) {
        data_sort_timestamp.erase(i->second.data_sort_timestamp_iter);
        data_sort_karma.erase(i->second.data_sort_karma_iter);
        data_sort_user.erase(i->second.data_sort_user_iter);
        data_sort_id.erase(i);
        return true;
    } else {
        return false;
    }
}

template <typename Callback>
void Database::RangeByTimestamp(int low, int high, Callback callback) const{
    auto first = data_sort_timestamp.lower_bound(low);
    auto second = data_sort_timestamp.upper_bound(high);
    for (auto i = first; i != second; ++i) {
        if (!callback(*i->second)) {
            break;
        }
    }
}
template <typename Callback>
void Database::RangeByKarma(int low, int high, Callback callback) const {
    auto first = data_sort_karma.lower_bound(low);
    auto second = data_sort_karma.upper_bound(high);
    for (auto i = first; i != second; ++i) {
        if (!callback(*i->second)) {
            break;
        }
    }
}

template <typename Callback>
void Database::AllByUser(const string& user, Callback callback) const {
    auto first = data_sort_user.lower_bound(user);
    auto second = data_sort_user.upper_bound(user);
    for (auto i = first; i != second; ++i) {
        if (!callback(*i->second)) {
            break;
        }
    }
}

void TestRangeBoundaries() {
    const int good_karma = 1000;
    const int bad_karma = -10;

    Database db;
    db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
    db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

    int count = 0;
    db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
        ++count;
        return true;
    });

    ASSERT_EQUAL(2, count);
}

void TestSameUser() {
    Database db;
    db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
    db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

    int count = 0;
    db.AllByUser("master", [&count](const Record&) {
        ++count;
        return true;
    });

    ASSERT_EQUAL(2, count);
}

void TestReplacement() {
    const string final_body = "Feeling sad";

    Database db;
    db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
    db.Erase("id");
    db.Put({"id", final_body, "not-master", 1536107260, -10});

    auto record = db.GetById("id");
    ASSERT(record != nullptr);
    ASSERT_EQUAL(final_body, record->title);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestRangeBoundaries);
    RUN_TEST(tr, TestSameUser);
    RUN_TEST(tr, TestReplacement);
    return 0;
}

// too slow

/*

struct Record {
    string id;
    string title;
    string user;
    int timestamp;
    int karma;
};

bool operator<(const Record& r1, const Record& r2) {
    return tie(r1.id, r1.title, r1.user, r1.timestamp, r1.karma) < tie(r2.id, r2.title, r2.user, r2.timestamp, r2.karma);
}

bool operator==(const Record& r1, const Record& r2) {
    return tie(r1.id, r1.title, r1.user, r1.timestamp, r1.karma) == tie(r2.id, r2.title, r2.user, r2.timestamp, r2.karma);
}

// Реализуйте этот класс
class Database {
public:
    bool Put(const Record& record);
    const Record* GetById(const string& id) const;
    bool Erase(const string& id);

    template <typename Callback>
    void RangeByTimestamp(int low, int high, Callback callback) const;

    template <typename Callback>
    void RangeByKarma(int low, int high, Callback callback) const;

    template <typename Callback>
    void AllByUser(const string& user, Callback callback) const;

private:
    set<Record> data;
    multimap<string, set<Record>::iterator> data_sort_id;
    multimap<int, set<Record>::iterator> data_sort_timestamp;
    multimap<int, set<Record>::iterator> data_sort_karma;
    multimap<string, set<Record>::iterator> data_sort_user;
};

bool Database::Put(const Record& record) {
    if (data.find(record) == data.end()) {
        auto& [place_iterator, data_insert_bool] = data.insert(record);
        if (data_insert_bool) {
            data_sort_id.insert({record.id, *place_iterator});
            data_sort_timestamp.insert({record.timestamp, *place_iterator});
            data_sort_user.insert({record.user, *place_iterator});
            data_sort_karma.insert({record.karma, *place_iterator});
            return true;
        }
        return false;
    } else {
        return false;
    }
}

const Record* Database::GetById(const string& id) const {
    auto i = data_sort_id.find(id);
    if (i == data_sort_id.end()) {
        return nullptr;
    } else {
        return &(*i->second);
    }
}

bool Database::Erase(const string& id) {
    auto i = data_sort_id.find(id);
    if (i != data_sort_id.end()) {
        const Record& to_del = *i->second;
        data_sort_id.erase(to_del.id);
        data_sort_timestamp.erase(to_del.timestamp);
        data_sort_karma.erase(to_del.karma);
        data_sort_user.erase(to_del.user);
        data.erase(to_del);
        return true;
    } else {
        return false;
    }
}

template <typename Callback>
void Database::RangeByTimestamp(int low, int high, Callback callback) const{
    auto first = data_sort_timestamp.lower_bound(low);
    auto second = data_sort_timestamp.upper_bound(high);
    for (auto i = first; i != second; ++i) {
        if (!callback(*(i->second))) {
            break;
        }
    }
}
template <typename Callback>
void Database::RangeByKarma(int low, int high, Callback callback) const {
    auto first = data_sort_karma.lower_bound(low);
    auto second = data_sort_karma.upper_bound(high);
    for (auto i = first; i != second; ++i) {
        if (!callback(*(i->second))) {
            break;
        }
    }
}

template <typename Callback>
void Database::AllByUser(const string& user, Callback callback) const {
    auto first = data_sort_user.lower_bound(user);
    auto second = data_sort_user.upper_bound(user);
    for (auto i = first; i != second; ++i) {
        if (!callback(*(i->second))) {
            break;
        }
    }
}
*/
