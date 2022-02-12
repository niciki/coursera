
#include <string>
#include <vector>
using namespace std;

// Реализуйте этот макрос так, чтобы функция main компилировалась
#define value__(x, y) (x##y)
#define UNIQ_NUM(x, y) value__(x, y)
#define UNIQ_ID UNIQ_NUM(__FILE_, __LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}