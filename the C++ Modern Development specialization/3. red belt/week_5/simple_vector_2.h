#include <cstdint>
#include <utility>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size): size_(move(size)), capacity(size_) {
        data = new T[size_];
    }
    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return *(data + move(index));
    }

    T* begin() {
        return data;
    }
    T* end() {
        return data + size_;
    }
    const T* begin() const {
        return data;
    }
    const T* end() const {
        return data + size_;
    }

    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(T value) {
        if (size_ + 1 <= capacity) {
            *(data + size_) = move(value);
            ++size_;
        } else {
            T* new_data;
            if (!size_) {
                new_data = new T[1];
                capacity = 1;
            } else {
                new_data = new T[2 * capacity];
                capacity *= 2;
            }
            for (int i = 0; i < size_; ++i) {
                *(new_data + i) = move(*(data + i));
            }
            delete[] data;
            data = move(new_data);
            *(new_data + size_++) = move(value);
        }
    }
    // При необходимости перегрузите
    // существующие публичные методы

private:
    T* data = nullptr;
    size_t size_ = 0;
    size_t capacity = 0;
};