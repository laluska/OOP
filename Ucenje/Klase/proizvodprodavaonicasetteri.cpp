#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Proizvod{
    string ime;
    int cijena;
public:
    Proizvod(string i, int c){
        ime=i;
        cijena=c;
    }
    string getIme()const{
        return ime;
    }
    int getCijena()const{
        return cijena;
    }

    void setCijena(const int& novaCijena){
        cijena=novaCijena;
    }
  
};
class Prodavnica{
    string naziv;
    vector<Proizvod>proizvodi;
public:
    Prodavnica(string n){
        naziv=n;
    }
    
    void dodajProizvod(const Proizvod& p){
        proizvodi.push_back(p);
    }
    void ispisiSkupe(int x)const{
        for(auto& k : proizvodi){
            if(k.getCijena()>x){
                cout<<k.getIme()<<" ";
                cout<<k.getCijena()<<endl;
            }
        }
    }
    void promijeniCijenu(const string& nazivProizvoda, int novaCijena) {
        for (auto& p : proizvodi) {
            if (p.getIme() == nazivProizvoda) {
                p.setCijena(novaCijena);
                break;
            }
        }
    }
    
    
    void ispisiSveProizvode()const{
        for(auto& x : proizvodi){
            cout<<x.getIme()<<" ";
            cout<<x.getCijena()<<endl;
        }
    }
};
int main() {
    // Kreiranje proizvoda
    Proizvod p1("Laptop", 750);
    Proizvod p2("Tablet", 450);
    Proizvod p3("Telefon", 300);
    Proizvod p4("Slusalice", 50);

    // Kreiranje prodavnice
    Prodavnica prodavnica1("TechShop");

    // Dodavanje proizvoda u prodavnicu
    prodavnica1.dodajProizvod(p1);
    prodavnica1.dodajProizvod(p2);
    prodavnica1.dodajProizvod(p3);
    prodavnica1.dodajProizvod(p4);

    // Ispis proizvoda skupljih od 400
    prodavnica1.ispisiSkupe(400);

    // Promjena cijene nekog proizvoda
    prodavnica1.promijeniCijenu("Telefon", 350);

    // Ispis svih proizvoda nakon promjene cijene
    cout << "\nNakon promjene cijene:\n";
    prodavnica1.ispisiSveProizvode();

    return 0;
}
