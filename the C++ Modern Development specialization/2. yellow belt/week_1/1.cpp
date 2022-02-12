#include <iostream>
#include <vector>

using namespace std;

class Matrix{
    public:
        Matrix(){
            strings = 0;
            rows = 0;
        }
        Matrix(int string, int row){
            if(string >= 0 && row >= 0){
                strings = string;
                rows = row;
                for(int i = 0; i < strings; ++i){
                    matrix.push_back(vector<int> ());
                    for(int j = 0; j < rows; ++j){
                        matrix[i].push_back(0);
                    }
                }
            } else {
                throw out_of_range("constructor");
            }
        }
        void Reset(int string, int row){
            /*for(int i = 0; i < string; ++i){
                cout << i;
                matrix[i].clear();
                //matrix[i].shrink_to_fit();
            }*/
            //cout << matrix[0].size();
            //vector<vector <int>> v;
            matrix.resize(0);
            if(row >= 0 && string >= 0){
                rows = row;
                strings = string;
                for(int i = 0; i < strings; ++i){
                    matrix.push_back(vector<int> ());
                    for(int j = 0; j < rows; ++j){
                        matrix[i].push_back(0);
                    }
                }
            } else {
                throw out_of_range("reset");
            }
        }
        int At(int string, int row) const {
            if(string < strings && string >= 0 && row >= 0 && row <= rows){
                return matrix[string][row];
            } else {
                throw out_of_range("at const");
            }
        }
        int& At(int string, int row){
            if(string < strings && string >= 0 && row >= 0 && row <= rows){
                return matrix[string][row];
            } else {
                throw out_of_range("at");
            }
        }
        int GetNumRows() const {
            return rows;
        } 
        int GetNumColumns() const {
            return strings;
        }
        friend istream& operator>>(istream& is, Matrix& m){
            //cout << 1;
            int a, b, q;
            is >> a >> b;
            //cout << 2;
            if(a >= 0 && b >= 0){
                m.Reset(a, b);
                for(int i = 0; i < m.Get_strings(); ++i){
                    for(int j = 0; j < m.Get_rows(); ++j){
                        is >> q;
                        m.Set_matrix()[i][j] = q;
                    }
                }
            } else {
                throw out_of_range(">> operator");
            }
            return is;
        }
        friend ostream& operator<<(ostream& os, const Matrix& a){
            os << a.Get_strings() << " " << a.Get_rows() << "\n";
            for(int i = 0; i < a.Get_strings(); ++i){
                for(int j = 0; j < a.Get_rows(); ++j){
                    if(j){
                        os << " ";
                    }
                    os << a.Get_matrix()[i][j];
                } 
                os << "\n";
            }
            return os;
        }
        bool operator==(const Matrix& b) const {
            if(b.Get_strings() != strings || b.Get_rows() != rows){
                return false;
            }
            for(int i = 0; i < strings; ++i){
                for(int j = 0; j < rows; ++j){
                    if(b.Get_matrix()[i][j] != matrix[i][j]){
                        return false;
                    }
                }
            }
            return true;

        }
        Matrix operator+(const Matrix& b) const {
            if(strings != b.Get_strings() || rows != b.Get_rows()){
                throw invalid_argument("+ operator");
            }
            Matrix q(strings, rows);
            for(int i = 0; i  < strings; ++i){
                for(int j = 0; j < rows; ++j){
                    q.matrix[i][j] = matrix[i][j] + b.Get_matrix()[i][j];
                }
                
            }
            return q;
        }
        int Get_strings() const{
            return strings;
        }
        int Get_rows() const {
            return rows;
        }
        vector<vector<int>> Get_matrix() const {
            return matrix;
        }
        void Set_strings(int string){
            strings = string;
            return;
        }
        void Set_rows(int row){
            rows = row;
            return;
        }
        vector<vector<int>>& Set_matrix(){
            return matrix;
        }
        private:
            int strings;
            int rows;
            vector<vector<int>> matrix;
};

int main() {
    Matrix one;
    Matrix two;
    cin >> one;
    cin >> two;
    cout << one + two << endl;
    Matrix m(1, 1);
    cout << m.At(0, 0) << endl;
    return 0;
}