#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    ifstream f("input.txt");
    double s;
    if(f.is_open()){
        cout << fixed << setprecision(3);
        while(f >> s){
            cout << s << "\n";
        }
    }
}