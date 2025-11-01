#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
//Napišite funckiju koja za jedan znak i za rečenicu vraća vektor svih pozicija znaka u
//rečenici.
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void funkcija(string& s) {
    vector<int> novi;
    char a = 'k';
    auto it = s.begin();

    while (it != s.end()) {
        it = find_if(it, s.end(), [a](char c) {
            return c == a;
        });
                //zasto dva puta moram provjeravat je li it!=s.end()
        if (it != s.end()) {
            auto indeks = distance(s.begin(), it);
            novi.push_back(indeks);
            it++;
        }
    }

    for (int i : novi) {
        cout << i << " ";
    }
}

int main() {
    string s = "kuca je skakutala";
    funkcija(s);
    return 0;
}
