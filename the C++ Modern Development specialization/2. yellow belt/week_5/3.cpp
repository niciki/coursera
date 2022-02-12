#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect: public Figure {
public:
    Rect(istringstream& is) {
        is >> width >> height;
    }
    double Perimeter() const override {
        return 2 * (width + height);
    }
    string Name() const override {
        return "RECT";
    }
    double Area() const override {
        return width * height;
    }
private:
    double width, height;
};

class Triangle: public Figure {
public:
    Triangle(istringstream& is) {
        is >> a >> b >> c;
    }
    double Perimeter() const override {
        return a + b + c;
    }
    string Name() const override {
        return "TRIANGLE";
    }
    double Area() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
private:
    double a, b, c;
};

class Circle: public Figure {
public:
    Circle(istringstream& is) {
        is >> r;
    }
    double Perimeter() const override {
        return 2 * 3.14 * r;
    }
    string Name() const override {
        return "CIRCLE";
    }
    double Area() const override {
        return 3.14 * r * r;
    }
private:
    double r;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string name;
    is >> name;
    if (name == "RECT") {
        return make_shared<Rect>(is);
    } else if (name == "TRIANGLE") {
        return make_shared<Triangle>(is);
    } else {
        return make_shared<Circle>(is);
    }
}

/*
int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);
        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}

RECT 4.000 1.000
TRIANGLE 3.000 0.000
CIRCLE 6.280 3.140
RECT 4000.000 1000000.000
TRIANGLE 3000.000 433012.702
CIRCLE 6280.000 3140000.000

RECT 4.000 1.000
TRIANGLE 3.000 0.433
CIRCLE 6.280 3.140
RECT 4000.000 1000000.000
TRIANGLE 3000.000 433012.702
CIRCLE 6280.000 3140000.000
*/