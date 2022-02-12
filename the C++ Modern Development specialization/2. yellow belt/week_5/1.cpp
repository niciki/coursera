#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код
    Animal (const string& s): Name(s) {};
    const string Name;
};


class Dog : public Animal {
public:
    Dog (const string& s): Animal(s) {};

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

/*
    Класс Dog должен являться наследником класса Animal.
    Конструктор класса Dog должен принимать параметр типа string и инициализировать им поле Name в классе Animal.


int main() {
    Dog p("aa");
    p.Bark();
}
*/