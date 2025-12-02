#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ocjena{
    string predmet;
    int ocjena;
public:
    Ocjena(string p, int o){
        predmet=p;
        ocjena=o;
    }

    int getOcjena()const{
        return ocjena;
    }
};
class Ucenik{
    string ime;
    vector<Ocjena>ocjene;
public:
    Ucenik(string i){
        ime=i;
    }
   
    void dodajOcjenu(const Ocjena& o){
        ocjene.push_back(o);
    }
    
    double izracunajaprosijek(){
        double zbroj=0;
        for(auto& p : ocjene){
            zbroj+=p.getOcjena();
        }
        return zbroj/ocjene.size();
    }
    
    void ispisiIznadProsjeka(){
        double prosjek=izracunajaprosijek();
        for(auto& s : ocjene){
            if(s.getOcjena()>prosjek){
                cout<<s.getOcjena()<<" ";
            }
        }
    }
};
int main() {
    Ocjena o1("Matematika", 5);
    Ocjena o2("Engleski", 4);
    Ocjena o3("Fizika", 2);
    Ocjena o4("Povijest", 5);

    Ucenik u1("Marko");

    u1.dodajOcjenu(o1);
    u1.dodajOcjenu(o2);
    u1.dodajOcjenu(o3);
    u1.dodajOcjenu(o4);

    u1.ispisiIznadProsjeka(); // ispisuje ocjene koje su iznad prosjeka njegovih ocjena

    return 0;
}
