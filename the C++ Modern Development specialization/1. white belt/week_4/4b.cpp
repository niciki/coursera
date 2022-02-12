#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream f("input.txt");
    ofstream o("output.txt");
    string s;
    if(f.is_open()){
        while(getline(f, s)){
            o << s << '\n';
        }
    }
}