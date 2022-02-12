#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
public:
    Person(const string& name): Name(name) {}
    virtual void Walk(const string& destination) const;
    const string Name;
};

void Walk_(const string& type, const string& destination, const string& Name) {
    cout << type << ": " << Name << " walks to: " << destination << endl;
}

void sing(const string& Name, const string& FavouriteSong){
    cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
}

class Student: public Person {
public:
    Student(const string& name, const string& favouriteSong): Person(name), FavouriteSong(favouriteSong) {}
    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }
    void Walk(const string& destination) const override {
        Walk_("Student", destination, Name);
        sing(Name, FavouriteSong);
    }
    void SingSong() {
        sing(Name, FavouriteSong);
    }
    const string FavouriteSong;
};

class Teacher: public Person {
public:
    Teacher(const string& name, const string& subject): Person(name), Subject(subject) {}
    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }
    void Walk(const string& destination) const override{
        Walk_("Student", destination, Name);
    }
    const string Subject;
};

class Policeman: public Person {
public:
    Policeman(const string& name): Person(name) {};
    void Check(const Person& t) {
        cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << t.Name << endl;
    }
    void Walk(const string& destination) const override {
        Walk_("Student", destination, Name);
    }
};

void VisitPlaces(const Person& t, const vector<string>& places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}