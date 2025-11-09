#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void funkcija(string& s, string& samog){
    auto it = s.begin();
    int i = 0;

    while (it != s.end() && i < samog.size()) {
        it = find(it, s.end(), '*');
        if (it != s.end()) {
            s.replace(distance(s.begin(), it), 1, 1, samog[i]);
            i++;
            it++;
        }
    }

    cout << s;
}

int main(){
    string s = "H*ll* w*rld";
    string samog = "eoo";
    funkcija(s, samog);
    return 0;
}
