#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ucenik{
    string ime;
    int razred;
public:
    Ucenik(string i, int r){
        ime=i;
        razred=r;
    }
    string getIme()const{
        return ime;
    }
};
class Razred{
    string oznaka;
    vector<Ucenik>ucenici;
public:
    Razred(string o){
        oznaka=o;
    }
    
    void dodajUcenika(const Ucenik& u){
        ucenici.push_back(u);
    }
    void ispisiUcenike()const{
        for(auto& u : ucenici){
            cout<<u.getIme()<<" ";
        }
    }
    string getOznaka()const{
        return oznaka;
    }
    size_t getBrojUcenika()const{
        return ucenici.size();
    }
};
int main() {
    Ucenik u1("Sara", 5);
    Ucenik u2("Ivan", 4);
    Ucenik u3("Mia", 5);

    Razred r1("3A");

    r1.dodajUcenika(u1);
    r1.dodajUcenika(u2);
    r1.dodajUcenika(u3);

    r1.ispisiUcenike();

    cout << "Razred " << r1.getOznaka()
         << " ima " << r1.getBrojUcenika() << " učenika." << endl;

    return 0;
}
