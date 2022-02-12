#pragma once

#include <cstdlib>
// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() {
        data = nullptr;
    }
    explicit SimpleVector(size_t size) {
        data = new T[size];
        this->capacity = size;
        this->size = size;
    }
    ~SimpleVector() {
        delete[] data;
    }
    T& operator[](size_t index) {
        return *(data + index);
    }
    T& At(size_t index) const {
        return *(data + index);
    }
    T* begin() {
        return data;
    }
    T* end() {
        return data + size;
    }
    const T* begin() const {
        return data;
    }
    const T* end() const {
        return data + size;
    }
    size_t Size() const {
        return size;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(const T& value) {
        if (!capacity) {
            data = new T[1];
            *data = value;
            size = 1;
            capacity = 1;
        } else if (size < capacity) {
            *(data + size++) = value;
        } else {
            T* new_ = new T[2 * capacity];
            for (int i = 0; i < size; ++i) {
                *(new_ + i) = *(data + i);
            }
            *(new_ + size++) = value;
            capacity *= 2;
            delete[] data;
            data = new_;
        }
    }
    void operator=(const SimpleVector& v) {
        delete[] data;
        data = new T[v.Capacity()];
        size = v.Size();
        capacity = v.Capacity();
        for (int i = 0; i < size; ++i) {
            data[i] = v.At(i);
        }
    }
private:
    T* data;
    size_t size = 0;
    size_t capacity = 0;
};
