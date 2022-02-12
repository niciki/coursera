
#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};
*/

bool operator<(const Region& a, const Region& b){
    return tie(a.std_name, a.parent_std_name, a.names, a.population) < tie(b.std_name, b.parent_std_name, b.names, b.population);
}

/*
bool operator==(const Region& a, const Region& b){
    bool f = true;
    if(a.std_name != b.std_name){
        f = false;
    } else if (a.parent_std_name != b.parent_std_name){
        f = false;
    } else if (a.population != b.population){
        f = false;
    } else {
        for(auto i : a.names){
            if(static_cast<string>(b.names[0]) == static_cast<int>(i.first) && b.names[i.first].second != i.second){
                f = false;
            }
        }
    }
    return f;
}*/


int FindMaxRepetitionCount(const vector<Region>& regions){
    map<Region, int> m;
    int p = 0;
    for(const auto& i : regions){
        ++p;
        if(!m.count(i)){
            m[i] = 1;
        } else {
            m[i]++;
        }
        // cout << m[i];
        // cout << "\n";
        // cout << m.size() << "\n";
    }
    if(!regions.size()){
        return 0;
    }
    int q = 1;
    for(const auto& i : m){
        q = (i.second > q) ? i.second : q;
    }
    return q;
}

/*
int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;
  
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;
  
  return 0;
}
*/