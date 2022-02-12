#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Deque {
public:
    Deque() {
        front_vector = vector<T>();
        back_vector = vector<T>();
    }
    bool Empty() const {
        return front_vector.size() + back_vector.size() == 0;
    }
    int Size() const {
        return front_vector.size() + back_vector.size();
    }
    T& operator[] (size_t index) {
        if (index + 1 > front_vector.size()) {
            return back_vector[index - front_vector.size()];
        } else {
            return front_vector[front_vector.size() - index - 1];
        }
    }
    const T& operator[] (size_t index) const {
        if (index + 1 > front_vector.size()) {
            return back_vector[index - front_vector.size()];
        } else {
            return front_vector[front_vector.size() - index - 1];
        }
    }
    T& At (size_t index) {
        if (index + 1 > front_vector.size() + back_vector.size()) {
            throw std::out_of_range("At catch");
        } else {
            return this->operator[](index);
        }
    }
    const T& At (size_t index) const {
        if (index + 1 > front_vector.size() + back_vector.size()) {
            throw std::out_of_range("At catch");
        } else {
            return this->operator[](index);
        }
    }
    T& Front() {
        return (front_vector.size() ? front_vector.back() : back_vector.front());
    }
    const T& Front() const {
        return (front_vector.size() ? front_vector.back() : back_vector.front());
    }
    T& Back() {
        return (back_vector.size() ? back_vector.back() : front_vector.front());
    }
    const T& Back() const {
        return (back_vector.size() ? back_vector.back() : front_vector.front());
    }
    void PushFront(const T& t) {
        front_vector.push_back(t);
    }
    void PushBack(const T& t) {
        back_vector.push_back(t);
    }
private:
    vector<T> front_vector;
    vector<T> back_vector;
};

/*
int main() {
    Deque<int> t;
    int n;
    cin >> n;
    while (n--) {
        int i;
        cin >> i;
        t.PushBack(i);
        cin >> i;
        t.PushFront(i);
    }
    cout << t[0] << " " << t[1] << "\n";
    for (int i = 0; i < t.Size(); ++i) {
        cout << t[i] << " ";
    }
    cout << "\n";
    cout << t.Front() << " " << t.Back() << "\n";
    try {
        t.At(100);
    } catch (...) {
        cout << "True!\n";
    }
}*/
