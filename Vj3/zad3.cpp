#include <iostream>
#include <algorithm>
#include <cstddef>
using namespace std;
int funkcija(int niz){
    int parni[50]=[];
    int neparni[50]=[];
    for(int i =0;i<strlen;)
    
}

int main() {
    int suma = 15;
    int produkt = 5;
    int prag = 13;
    int niz[]={1,2,3,4,5,6};

    auto parnost = [](int a) {
        if (a % 2 == 0) return true;
        return false;
    };

    auto udvostruci = [](int a) {
        return a * 2;
    };

    auto prepolovi = [](int a) {
        return a / 2;
    };

    auto dodavanje = [&](int a) {
        return suma += a;
    };

    auto dodavanje2 = [&](int a) {
        return produkt *= a;
    };

    auto dodavanje3 = [prag, &suma](int a) {
        if (a > prag) {
            suma += a;
        } else {
            cout << "Broj nije veci od praga" << endl;
        }
    };


    cout << "Paran? " << parnost(6) << endl;
    cout << "Udvostruceni: " << udvostruci(3) << endl;
    cout << "Prepolovljeni: " << prepolovi(6) << endl;
    cout << "Dodavanje: " << dodavanje(3) << endl;
    cout << "Dodavanje na produkt: " << dodavanje2(3) << endl;
    
    dodavanje3(14);
    cout << "Nova suma nakon dodavanja3: " << suma << endl;

    return 0;
}
