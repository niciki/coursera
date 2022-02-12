#include <iostream>
#include <exception>
#include <string>
using namespace std;

/*
string AskTimeServer() {
    throw system_error();
}
*/

class TimeServer {
    public:
        string GetCurrentTime() {
            try {
                string s = AskTimeServer();
                last_fetched_time = s;
                return s;
            } catch (system_error&){
                return last_fetched_time;
            } catch(...){
                throw;
            }
        }
    private:
        string last_fetched_time = "00:00:00";
};


int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
