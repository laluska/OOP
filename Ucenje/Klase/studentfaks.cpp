#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student{
    string smijer;
    string ime;
    double prosjek;
public:
    Student(string s, string i, double p){
        smijer=s;
        ime=i;
        prosjek=p;
    }
    string getSmijer()const{
        return smijer;
    }
    string getIme()const{
        return ime;
    }
    double getProsjek()const{
        return prosjek;
    }
    void setProsjek(const double& novi){
        prosjek=novi;
    }
};
class Fakultet{
    string naziv;
    vector<Student>studenti;
public:
    Fakultet(string n){
        naziv=n;
    }
    
    void dodajStudenta(const Student& s){
        studenti.push_back(s);
    }
    
    void ispisiSveStudente()const{
        for(auto& v : studenti){
            cout<<v.getIme()<<" ";
            cout<<v.getSmijer()<<" ";
            cout<<v.getProsjek()<<endl;
        }
    }
    void ispisiStudenteSaProsjekomVecimOd(int z){
        for(auto& x : studenti){
            if(x.getProsjek()>z){
                cout<<x.getIme()<<" ";
                cout<<x.getSmijer()<<" ";
                cout<<x.getProsjek()<<endl;
            }
        }
    }
    void ispisiSaSmjera(string b){
        for(auto& t : studenti){
            if(t.getSmijer()==b){
                cout<<t.getIme();
            }
        }
    }
    void promijeniProsjek(const string& g, const double& i){
        for(auto& r : studenti){
            if(r.getIme()==g){
                r.setProsjek(i);
            }
        }
    }
};
int main() {
    // Kreiranje studenata
    Student s1("Racunarstvo", "Ana Maric", 4.7);
    Student s2("Strojarstvo", "Luka Ivic", 3.2);
    Student s3("Elektrotehnika", "Klara Peric", 4.1);
    Student s4("Racunarstvo", "Ivan Horvat", 2.8);

    // Kreiranje fakulteta
    Fakultet f1("Tehnicki Fakultet");

    // Dodavanje studenata
    f1.dodajStudenta(s1);
    f1.dodajStudenta(s2);
    f1.dodajStudenta(s3);
    f1.dodajStudenta(s4);

    cout << "\n--- Svi studenti ---\n";
    f1.ispisiSveStudente();

    cout << "\n--- Studenti s prosjekom većim od 4.0 ---\n";
    f1.ispisiStudenteSaProsjekomVecimOd(4.0);

    cout << "\n--- Studenti sa smjera Racunarstvo ---\n";
    f1.ispisiSaSmjera("Racunarstvo");

    // Mijenjanje prosjeka
    cout << "\nMijenjanje prosjeka studentu 'Ivan Horvat'...\n";
    f1.promijeniProsjek("Ivan Horvat", 3.9);

    cout << "\n--- Nakon promjene ---\n";
    f1.ispisiSveStudente();

    return 0;
}
