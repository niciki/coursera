#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
T Sqr(T x);

template <typename T>
vector<T> Sqr(vector<T> v);

template <typename key, typename value>
map<key, value> Sqr(map<key, value> m);

template <typename first, typename second>
pair<first, second> Sqr(pair<first, second> p);

template <typename T>
T Sqr(T x){
    return x * x;
}

template <typename T>
vector<T> Sqr(vector<T> v){
    vector<T> tmp;
    for(const auto& i : v){
        tmp.push_back(Sqr(i));
    }
    return tmp;
}

template <typename key, typename value>
map<key, value> Sqr(map<key, value> m){
    map<key, value> tmp;
    for(const auto& i : m){
        tmp[i.first] = Sqr(i.second);
    }
    return tmp;
}

template <typename first, typename second>
pair<first, second> Sqr(pair<first, second> p){
    return make_pair(Sqr(p.first), Sqr(p.second));
}

/*
int main(){
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;
    map<int, pair<int, int>> map_of_pairs = {{4, {2, 2}}, {7, {4, 3}}};
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}
*/