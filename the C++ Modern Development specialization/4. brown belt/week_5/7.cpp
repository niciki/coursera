#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

bool IsSubdomain_bad(string& subdomain, string& domain) {
    auto i = 0;
    auto j = 0;
    while (i < subdomain.size() && j < domain.size()) {
        if (subdomain[i++] != domain[j++]) {
            return false;
        }
    }
    if (subdomain.size() != domain.size()) {
        return (i >= subdomain.size() && j < domain.size() && domain[j] == '.')
            || (j >= domain.size() && i < subdomain.size() && subdomain[i] == '.');
    } else {
        return true;
    }
}

bool IsSubdomain(string& subdomain, string& domain) {
    auto i = subdomain.size() - 1;
    auto j = domain.size() - 1;
    while (i >= 0 && j >= 0) {
        cout << subdomain[i] << " " << domain[j] << "\n";
        if (subdomain[i--] != domain[j--]) {
            return false;
        }
    }
    return (i < 0 && domain[j] == '.')
        || (j < 0 && subdomain[i] == '.');
}

vector<string> ReadDomains() {
    size_t count;
    cin >> count;
    vector<string> domains;
    for (size_t i = 0; i < count; ++i) {
        string domain;
        cin >> domain;
        domains.push_back(domain);
    }
    return domains;
}

int main() {
    vector<string> banned_domains = ReadDomains();
    vector<string> domains_to_check = ReadDomains();

    for (string& domain : banned_domains) {
        reverse(begin(domain), end(domain));
    }
    for (string& domain : domains_to_check) {
        reverse(begin(domain), end(domain));
    }
    sort(begin(banned_domains), end(banned_domains));
    size_t insert_pos = 0;
    for (string& domain : banned_domains) {
        if (insert_pos == 0 || !IsSubdomain_bad(domain, banned_domains[insert_pos - 1])) {
            swap(banned_domains[insert_pos++], domain);
        }
    }
    banned_domains.resize(insert_pos);
    for (string& domain : domains_to_check) {
        if (const auto it = upper_bound(begin(banned_domains), end(banned_domains), domain);
            it != banned_domains.begin() && IsSubdomain_bad(domain, *prev(it))) {
            cout << "Bad" << endl;
        } else {
            const auto i = upper_bound(begin(banned_domains), end(banned_domains), domain);
            cout << "Good" << endl;
        }
    }
    return 0;
}
/*
4
ya.ru
maps.me
m.ya.ru
com
7
ya.ru
ya.com
m.maps.me
moscow.m.ya.ru
maps.com
maps.ru
ya.ya
*/
/*
#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

bool IsSubdomain(vector<string>& banned_domains, string domain) {
    for (auto& i: banned_domains) {
        int d_size = domain.size() - 1;
        int bad_d_size = i.size() - 1;
        //cout << "sizes: " << d_size << " " << bad_d_size << "\n";
        while (d_size >= 0 && bad_d_size >= 0) {
            //cout << i[bad_d_size] << " " << domain[d_size] << "\n";
            if (i[bad_d_size--] != domain[d_size--]) {
                break;
            }
            //cout << "sizes: " << d_size << " " << bad_d_size << "\n";
        }
        if (bad_d_size == -1) {
            return false;
        }
    }
    return true;
}

vector<string> ReadDomains() {
    size_t count;
    cin >> count;
    vector<string> domains;
    for (size_t i = 0; i < count; ++i) {
        string domain;
        cin >> domain;
        domains.push_back(domain);
    }
    return domains;
}

int main() {
    vector<string> banned_domains = ReadDomains();
    vector<string> domains_to_check = ReadDomains();
    for (auto& i: domains_to_check) {
        cout << (IsSubdomain(banned_domains, i) ? "Good\n" : "Bad\n");
    }
    return 0;
}


4
ya.ru
maps.me
m.ya.ru
com
3
ya.com
m.maps.me
maps.com

*/