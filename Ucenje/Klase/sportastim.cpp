#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sportas{
    string ime;
    int rezultat;
public:
    Sportas(string i, int z){
        ime=i;
        rezultat=z;
    }
    string getIme()const{
        return ime;
    }
    int getRezultat()const{
        return rezultat;
    }
    void setRezultat(const int& novi){
        rezultat=novi;
    }
};
class Tim{
    string naziv;
    vector<Sportas>sportasi;
public:
    Tim(string n){
        naziv=n;
    }
    void dodajSportasa(const Sportas& s){
        sportasi.push_back(s);
    }
    void ispisiRezultatVeciOd(int x){
        for(auto& z : sportasi){
            if(z.getRezultat()>x){
                cout<<z.getIme()<<" ";
                cout<<z.getRezultat()<<endl;
            }
        }
    }
    void promijeniRezultat(const string& s, const int& k){
        for(auto& v : sportasi){
            if(v.getIme()==s){
                v.setRezultat(k);
            }
        }
    }
    void ispisiSveSportase()const{
        for(auto& j : sportasi){
            cout<<j.getIme()<<" ";
            cout<<j.getRezultat()<<endl;
        }
    }
    
};
int main() {
    // Kreiranje sportaša
    Sportas s1("Marko", 12);
    Sportas s2("Ana", 18);
    Sportas s3("Luka", 9);

    // Kreiranje tima
    Tim mojTim("Šahovski klub");

    // Dodavanje sportaša u tim
    mojTim.dodajSportasa(s1);
    mojTim.dodajSportasa(s2);
    mojTim.dodajSportasa(s3);

    // Ispis sportaša s rezultatom većim od 10
    cout << "Sportaši s rezultatom većim od 10:" << endl;
    mojTim.ispisiRezultatVeciOd(10);

    // Promjena rezultata jednog sportaša
    mojTim.promijeniRezultat("Luka", 15);

    // Ispis svih sportaša nakon promjene rezultata
    cout << "\nNakon promjene rezultata:" << endl;
    mojTim.ispisiSveSportase();

    return 0;
}
