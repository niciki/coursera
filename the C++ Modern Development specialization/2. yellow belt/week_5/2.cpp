/*
#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}
*/
class INotifier {
public:
    INotifier(const string& s): adr(s) {};
    virtual void Notify(const string& message) const = 0;
    const string adr;
};

class SmsNotifier: public INotifier {
public:
    SmsNotifier(const string& adr): INotifier(adr) {};
    void Notify (const string& message) const override {
        SendSms(adr, message);
    }
};

class EmailNotifier: public INotifier {
public:
    EmailNotifier(const string& adr): INotifier(adr) {};
    void Notify (const string& message) const override {
        SendEmail(adr, message);
    }
};

/*
void Notify(INotifier& notifier, const string& message) {
    notifier.Notify(message);
}


int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
    return 0;
}*/