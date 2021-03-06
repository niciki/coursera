#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

class ReadingManager {
public:
  ReadingManager()
      : user_page_counts_(MAX_USER_COUNT_ + 1, 0),
        page_rating(vector<int>(1001, 0)), users_num(0) {}

  void Read(int user_id, int page_count) {
        if (users_ids.count(user_id)) {
            --page_rating[user_page_counts_[user_id]];
            user_page_counts_[user_id] = page_count;
            ++page_rating[user_page_counts_[user_id]];
        } else {
            users_ids.insert(user_id);
            ++users_num;
            user_page_counts_[user_id] = page_count;
            ++page_rating[user_page_counts_[user_id]];
        }
  }

  double Cheer(int user_id) const {
        if (user_page_counts_[user_id] == 0) {
            return 0;
        }
        const int user_count = GetUserCount();
        if (user_count == 1) {
            return 1;
        }
        int position = 0;
        for (int i = user_page_counts_[user_id]; i < 1001; ++i) {
            position += page_rating[i];
        }
        // По умолчанию деление целочисленное, поэтому
        // нужно привести числитель к типу double.
        // Простой способ сделать это — умножить его на 1.0.
        return (user_count - position) * 1.0 / (user_count - 1);
  }

private:
    // Статическое поле не принадлежит какому-то конкретному
    // объекту класса. По сути это глобальная переменная,
    // в данном случае константная.
    // Будь она публичной, к ней можно было бы обратиться снаружи
    // следующим образом: ReadingManager::MAX_USER_COUNT.
    static const int MAX_USER_COUNT_ = 100'000;

    vector<int> user_page_counts_;
    set<int> users_ids;
    int users_num;
    vector<int> page_rating;

    int GetUserCount() const {
        return users_num;
    }
};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}