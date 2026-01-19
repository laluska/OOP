#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;
void funkcija(vector<string>&v) {
    try {
        ifstream in("C:\\Users\\student\\Desktop\\podaci.txt");
        if (!in) {
            throw runtime_error("ne mogu ucitati datoteku");
        }
        string s;
        while (in >> s) {
            v.push_back(s);
        }
        in.close();
    }
    catch (const exception& e) {
        cout << "Greska: " << e.what() << endl;
    }
    
}
void funkcija1(vector<string>&v,string& s) {
    size_t pola = v.size() / 2;
    v.insert(v.begin() + pola, s);
    for (auto it : v) {
        cout << it << " ";
    }
}
void spremanje(vector<string>& v) {
    ofstream out("C:\\Users\\student\\Desktop\\podaci.txt");
    for (auto kl : v) {
        out << kl;
    }
    out.close();
}

int main() {
    vector<string>v;
    string s="krava";
    funkcija(v);
    for (auto &t : v) {
        cout << t<<" ";
    }
    funkcija1(v, s);
    spremanje(v);

    return 0;
}
