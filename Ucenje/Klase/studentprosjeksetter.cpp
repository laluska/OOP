#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student{
    string ime;
    int broj;
    double prosjek;
public:
    Student(string i, int b, double p){
        ime=i;
        broj=b;
        prosjek=p;
    }
    string getIme()const{
        return ime;
    }
    int getBroj()const{
        return broj;
    }
    double getProsjek()const{
        return prosjek;
    }
    
    void setProsjek(const double& nova){
        prosjek=nova;
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
    void ispisiStudenteSaProsjekomVecimOd(int y){
        for(auto& t : studenti){
            if(t.getProsjek()>y){
                cout<<t.getIme()<<" ";
                cout<<t.getBroj()<<" ";
                cout<<t.getProsjek()<<endl;
            }
        }
    }
    void promijeniProsjek(const string& s, const double& k){
        for(auto& v : studenti){
            if(v.getIme()==s){
                v.setProsjek(k);
            }
        }
    }
    void ispisiSveStudente()const{
        for(auto& f : studenti){
            cout<<f.getIme()<<" ";
            cout<<f.getBroj()<<" ";
            cout<<f.getProsjek()<<endl;
        }
    }
};
int main(){
    Student s1("Ana Maric",5,3.5);
    Student s2("Ivoo Ivic",2,5.0);
    Student s3("Ana Maric",3,4.1);
    Student s4("Ana Kitic",6,3.3);
    
    Fakultet f1("SOSS");
    
    f1.dodajStudenta(s1);
    f1.dodajStudenta(s2);
    f1.dodajStudenta(s3);
    f1.dodajStudenta(s4);
    
    f1.ispisiStudenteSaProsjekomVecimOd(3.6);
    
    f1.promijeniProsjek("Ana Maric", 5.0);
    f1.ispisiSveStudente();
    return 0;
}
