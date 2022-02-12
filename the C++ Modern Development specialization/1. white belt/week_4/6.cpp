#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    fstream f("input.txt");
    if(f){
        int n, m;
        f >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                f >> a[i][j];
                f.ignore(1);
            }
        }
        cout << setw(10);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j != m - 1){
                    cout << setw(10) << a[i][j] << " ";
                } else if(i != n - 1){
                    cout << setw(10) << a[i][j] << "\n";
                } else {
                    cout << setw(10) << a[i][j];
                }
            }
        }
    }
}