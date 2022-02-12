#include <iostream>

using namespace std;

class ReversibleString {
    public:
        ReversibleString(string s_): s(s_){};
        ReversibleString() = default;
        string ToString() const {
            return s;
        }
        void Reverse(){
            for(int i = 0; i < s.length() / 2; i++){
                char tmp = s[i];
                s[i] = s[s.length() - i - 1];
                s[s.length() - i - 1] = tmp;
            }
        }
    private:
        string s;
};

/*
int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
*/