#include <iostream>
#include <algorithm>
using namespace std;
// Napišite funkciju koja za string koji predstavlja ime i prezime vraća string u kojem su
//inicijali.
//"John Johnny Depp"-> "J.J.D."
string funkcija(const string& s) {
    string inicijali;

    for (char c : s) {
        if (isupper(c)) {
            inicijali.push_back(c);
            inicijali.push_back('.'); 
        }
    }

    return inicijali;
}
//mogu li po velikom slovu ili moram po razmaku???
int main() {
    string s = "Laura Lagator";
    cout<<"inicijali su"<<funkcija(s);
    return 0;
}
