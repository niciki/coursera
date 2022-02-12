// #pragma once

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) {
        if (a_size > N) {
            throw (invalid_argument(""));
        }
        size = a_size;
    }
    T& operator[](size_t index) {
        return data[index];
    }
    const T& operator[](size_t index) const {
        return data[index];
    }
    typename array<int, N>::iterator begin() {
        return size ? data.begin() : data.end();
    }
    typename array<int, N>::iterator end() {
        return data.end();
    }
    typename array<int, N>::const_iterator begin() const {
        return size ? data.cbegin() : data.cend();
    }
    typename array<int, N>::const_iterator end() const {
        return data.cend();
    }
    size_t Size() const {
        return size;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(const T& value) {
        if (size < capacity) {
            data[size] = value;
            ++size;
        } else {
            throw (overflow_error(""));
        }
    }
    T PopBack() {
        if (size) {
            --size;
            return data[size];
        } else {
            throw (underflow_error(""));
        }
    }
private:
    array<int, N> data;
    size_t capacity = N;
    size_t size;
};
