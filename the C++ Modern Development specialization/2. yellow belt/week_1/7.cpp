#include <iostream>
#include <map>

using namespace std;

template <typename key, typename value>
value& GetRefStrict(map<key, value>& m, key k){
    try {
        return m.at(k);
    } catch(...) {
        throw(runtime_error(""));
    }
}

/*
int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0); 
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
}
*/