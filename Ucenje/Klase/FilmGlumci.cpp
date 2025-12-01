#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Glumac{
    string ime;
    int godine;
public:
    Glumac(string i, int g){
        ime=i;
        godine=g;
    }
    
    string getime()const{
        return ime;
    }
};
class Film{
    string naziv;
    vector<Glumac>glumci;
public:
    Film(string n){
        naziv=n;
    }
    void dodajGlumca(const Glumac& g){
        glumci.push_back(g);
    }
    void ispisiGlumce()const{
        for(auto& p : glumci){
            cout<<p.getime()<<" ";
        }
    }
    auto getBrojGlumaca()const{
        return glumci.size();
    }
};
int main() {
    // Glumci
    Glumac g1("Keanu Reeves", 59);
    Glumac g2("Carrie-Anne Moss", 57);
    Glumac g3("Laurence Fishburne", 63);

    // Film
    Film matrix("The Matrix");

    // Dodavanje glumaca
    matrix.dodajGlumca(g1);
    matrix.dodajGlumca(g2);
    matrix.dodajGlumca(g3);

    // Ispis glumaca
    matrix.ispisiGlumce();

    // Ukupan broj glumaca
    cout << "Film ima " << matrix.getBrojGlumaca() << " glumaca." << endl;

    return 0;
}
