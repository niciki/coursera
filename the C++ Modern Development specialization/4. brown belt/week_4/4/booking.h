//#pragma once

//#include "new_booking_providers.h"

//#include <iostream>

namespace RAII {
template<typename T>
    class Booking {
    public:
        Booking(T* prov, int& cnt): provider(prov), counter(cnt) {}
        Booking(Booking& b) = delete;
        Booking(Booking&& b): provider(b.provider), counter(b.counter) {
            b.provider = nullptr;
            b.~Booking();
        }
        ~Booking() {
            if (provider != nullptr) {
                provider->CancelOrComplete(*this);
            }
        }
        Booking& operator=(const Booking& b) = delete;
        Booking& operator=(Booking&& b) {
            provider = b.provider;
            counter = b.counter;
            b.provider = nullptr;
            b.~Booking();
            return *this;
        }
    private:
        T* provider;
        int& counter;
    };
};
