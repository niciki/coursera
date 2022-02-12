#include <iostream>

using namespace std;

class Incognizable{
    public:
        Incognizable() = default;
        Incognizable(int a): a(a) {};
        Incognizable(int a, int b): a(a), b(b) {};
    private:
        int a, b;
};

using namespace std;

/*
int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
*/