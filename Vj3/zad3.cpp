#include <iostream>
using namespace std;

auto parnost = [](int a){ return a % 2 == 0; };
auto udvostruci = [](int a){ return a * 2; };
auto prepolovi = [](int a){ return a / 2; };

void obradiNiz(int niz[], int velicina) {
    for(int i = 0; i < velicina; i++) {
        if(parnost(niz[i])) {
            niz[i] = prepolovi(niz[i]);
        } else {
            niz[i] = udvostruci(niz[i]);
        }
    }
}

void sumaIProdukt(int niz[], int velicina, int &suma, int &produkt) {
    auto dodavanje = [&](int a){ return suma += a; };
    auto dodavanje2 = [&](int a){ return produkt *= a; };
    for(int i = 0; i < velicina; i++) {
        dodavanje(niz[i]);
        dodavanje2(niz[i]);
    }
}

void sumaVecihOdPraga(int niz[], int velicina, int prag, int &suma) {
    auto dodavanje3 = [prag, &suma](int a){
        if(a > prag) suma += a;
    };
    for(int i = 0; i < velicina; i++) {
        dodavanje3(niz[i]);
    }
}

int main() {
    int niz[6] = {1,2,3,4,5,6};
    int suma = 0;
    int produkt = 1;
    int prag = 13;

    obradiNiz(niz, 6);
    sumaIProdukt(niz, 6, suma, produkt);
    sumaVecihOdPraga(niz, 6, prag, suma);

    cout << "Niz nakon obrade: ";
    for(int i = 0; i < 6; i++) cout << niz[i] << " ";
    cout << endl;
    cout << "Suma svih elemenata: " << suma << endl;
    cout << "Produkt svih elemenata: " << produkt << endl;

    return 0;
}
