#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        T* tmp;
        if (ready_to_use.size()) {
            tmp = ready_to_use.front();
            ready_to_use.pop();
        } else {
            tmp = new T;
        }
        in_use.insert(tmp);
        return tmp;
    }
    T* TryAllocate() {
        T* tmp;
        if (ready_to_use.size()) {
            tmp = ready_to_use.front();
            ready_to_use.pop();
            in_use.insert(tmp);
        } else {
            tmp = nullptr;
        }
        return tmp;
    }

    void Deallocate(T* object) {
        if (in_use.count(object)) {
            in_use.erase(object);
            ready_to_use.push(object);
        } else {
            throw invalid_argument("there isn't such element");
        }
    }

    ~ObjectPool() {
        for (auto& i: in_use) {
            delete i;
        }
        while (ready_to_use.size()) {
            delete ready_to_use.front();
            ready_to_use.pop();
        }
    }

private:
    set<T*> in_use;
    queue<T*> ready_to_use;
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
