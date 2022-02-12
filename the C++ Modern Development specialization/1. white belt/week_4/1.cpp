#include <iostream>
#include <string>
using namespace std;

struct Specialization{
    explicit Specialization(string s): value(s) {}
    string value;
};

struct Course{
    explicit Course(string s): value(s) {}
    string value;
};

struct Week {
    explicit Week(string s): value(s) {}
    string value;
};

struct LectureTitle {
    LectureTitle() = default;
    LectureTitle(Specialization s1, Course s2, Week s3): specialization(s1.value), course(s2.value), week(s3.value) {}
    string specialization;
    string course;
    string week;
};

/*
int main(){
    LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
}
*/