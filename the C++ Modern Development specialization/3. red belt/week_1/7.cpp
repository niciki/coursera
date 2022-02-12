// #include "test_runner.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

/*
template <typename T>
class Table {
 private:
  vector<vector<T>> data;

 public:
  Table(size_t rows, size_t columns) {
    Resize(rows, columns);
  }

  const vector<T>& operator [] (size_t idx) const {
    return data[idx];
  }

  vector<T>& operator [] (size_t idx) {
    return data[idx];
  }

  void Resize(size_t rows, size_t columns) {
    data.resize(rows);
    for (auto& item : data) {
      item.resize(columns);
    }
  }

  pair<size_t, size_t> Size() const {
    if (!data.empty() && !data[0].empty()) {
      return {data.size(), data[0].size()};
    }

    return  {0, 0};
  }

};*/

/*
// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
public:
    Table (size_t strings_num_, size_t rows_num_) {
        Resize(strings_num_, rows_num_);
    }
    void Resize (size_t new_strings_num, size_t new_rows_num) {
        data.resize(new_strings_num);
        for (auto& i : data) {
            i.resize(new_rows_num);
        }
    }
    vector<T>& operator[](int index) {
        return data[index];
    }
    const vector<T>& operator[](int index) const {
        return data[index];
    }

    pair<size_t, size_t> Size() const {
        return {(data.empty() || data[0].empty() ? 0 : data.size()), (data.empty() || data[0].empty() ? 0 : data[0].size())};
    }

    pair<size_t, size_t> Size() const {
    if (!data.empty() && !data[0].empty()) {
      return {data.size(), data[0].size()};
    }

    return {0, 0};
  }
private:
    vector<vector<T>> data;
};
*/


// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
public:
    Table (size_t strings_num_, size_t columns_num_) {
        if (strings_num_ && columns_num_) {
            data = vector<vector<T>> ();
            this->Resize(strings_num_, columns_num_);
        } else {
            strings_num = 0;
            columns_num = 0;
            data = vector<vector<T>> ();
        }
    }
    void Resize (size_t new_strings_num, size_t new_columns_num) {
        data.resize(new_strings_num);
        for (auto& i : data) {
            i.resize(new_columns_num);
        }
        strings_num = new_strings_num;
        columns_num = new_columns_num;
    }
    vector<T>& operator[](int index) {
        return data[index];
    }
    const vector<T>& operator[](int index) const {
        return data[index];
    }
    pair<size_t, size_t> Size() const {
        return {strings_num, columns_num};
    }
private:
    size_t strings_num, columns_num;
    vector<vector<T>> data;
};

/*
void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
*/