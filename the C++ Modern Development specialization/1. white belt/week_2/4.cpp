/*
#include <iostream>

using namespace std;
*/

void UpdateIfGreater(int x, int& y){
    y = (x > y ? x : y);
}

/*
int main(){
    int x = 1;
    UpdateIfGreater(5, x);
    std::cout << x << "\n";
    return 0;
}
*/