#include <iostream>
#include <string>
using namespace std;
#include <iostream>
class Predmet{
    string naziv;
    int ects;
public:
    Predmet(string n, int e){
        n=naziv;
        e=ects;
    }
    
    string getnaziv()const{
        return naziv;
    }
};
class Student{
    string ime;
    int godine;
    vector<Predmet>predmeti;
public:
    Student(string i, int g){
        i=ime;
        g=godine;
    }
    void dodajPredmet(const Predmet& p){
        predmeti.push_back(p);
    }
    
    void ispisiPredmete()const{
        for(auto &p : predmeti){
            cout<< p.getnaziv();
        }
    }
    void setIme(const string& novi){
        ime=novi;
    }
    string getIme()const{
        return ime;
    };
    
};
int main() {
    // Kreiramo studente
    Student s1("Luka", 20);
    Student s2("Maja", 22);

    // Kreiramo predmete
    Predmet p1("Programiranje", 6);
    Predmet p2("Matematika", 5);
    Predmet p3("Fizika", 4);

    // Dodajemo predmete studentima
    s1.dodajPredmet(p1);
    s1.dodajPredmet(p2);

    s2.dodajPredmet(p2);
    s2.dodajPredmet(p3);

    // Ispisujemo predmete studenata
    s1.ispisiPredmete();
    s2.ispisiPredmete();

    // Promjena imena studenta
    s1.setIme("Luka Novak");
    std::cout << "Novo ime s1: " << s1.getIme() << std::endl;

    return 0;
}
