#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Automobil{
    string marka;
    string model;
    int godine;
    int cijena;
public:
    Automobil(string m, string mo, int g, int c){
        marka=m;
        model=mo;
        godine=g;
        cijena=c;
    }
    Automobil(const Automobil& a){
        marka=a.marka;
        model=a.model;
        godine=a.godine;
        cijena=a.cijena;
    }
    string getMarka()const{
        return marka;
    }
    string getModel()const{
        return model;
    }
    int getCijena()const{
        return cijena;
    }
    void setCijena(const int& nova){
        cijena=nova;
    }
};
class Garaza{
    string naziv;
    vector<Automobil>automobili;
public:
    Garaza(string n){
        naziv=n;
    }
    void dodajAutomobil(const Automobil& a){
        automobili.push_back(a);
    }
    void ispisiSkupe(int x){
        for(auto& k : automobili){
            if(k.getCijena()>x){
                cout<<k.getModel()<<" ";
                cout<<k.getCijena()<<endl;
            }
        }
    }
    void promijeniCijenu(const string& s, const int& i){
        for(auto& k : automobili){
            if(k.getMarka()==s){
                k.setCijena(i);
            }
        }
    }
    void ispisiSveAutomobile()const{
        for(auto& t : automobili){
            cout<<t.getMarka()<<" ";
            cout<<t.getModel()<<" ";
            cout<<t.getCijena()<<endl;
        }
    }
};
int main() {
    // Kreiranje automobila
    Automobil a1("Audi", "A4", 2018, 25000);
    Automobil a2=a1;
    Automobil a3("Toyota", "Corolla", 2015, 15000);

    // Kreiranje garaže
    Garaza g1("Centar Garaža");

    // Dodavanje automobila u garažu
    g1.dodajAutomobil(a1);
    g1.dodajAutomobil(a2);
    g1.dodajAutomobil(a3);

    // Ispis automobila skupljih od 20000
    cout << "Automobili skuplji od 20000:\n";
    g1.ispisiSkupe(20000);

    // Promjena cijene jednog automobila
    g1.promijeniCijenu("Toyota", 18000);

    // Ispis svih automobila nakon promjene cijene
    cout << "\nNakon promjene cijene:\n";
    g1.ispisiSveAutomobile();

    return 0;
}
