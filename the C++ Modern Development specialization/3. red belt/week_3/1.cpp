#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

#include "test_runner.h"

using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        if (allocation_blocs_free.size()) {
            T* new_ = allocation_blocs_free.front();
            allocation_blocs_free.pop();
            active_blocs.insert(new_);
            return new_;
        } else {
            T* new_ = new T;
            active_blocs.insert(new_);
            return new_;
        }
    }
    T* TryAllocate() {
        if (allocation_blocs_free.size()) {
            T* new_ = allocation_blocs_free.front();
            allocation_blocs_free.pop();
            active_blocs.insert(new_);
            return new_;
        } else {
            return nullptr;
        }
    }
    void Deallocate(T* object) {
        if (active_blocs.count(object)) {
            active_blocs.erase(object);
            allocation_blocs_free.push(object);
        } else {
            throw (std::invalid_argument(""));
        }
    }
    ~ObjectPool() {
        for (auto& i: active_blocs) {
            delete i;
        }
        while (allocation_blocs_free.size()) {
            delete allocation_blocs_free.front();
            allocation_blocs_free.pop();
        }
    }

private:
    queue <T*> allocation_blocs_free;
    set<T*> active_blocs;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
    }

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}