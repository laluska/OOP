#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*Napišite klasu Student s privatnim članovima name, grades (vector ocjena). Implementirajte:
 · void add_grade(int grade) - dodaje ocjenu
 · double average() const - računa prosjek
 · bool passed() const - provjerava je li prosjek >= 2.0
 U main funkciji napravite vektor studenata i izbrojite koliko studenata je položilo.*/
class Student{
private:
    string name;
    vector<int>ocjena;
    
public:
    Student(const string& n){
        name=n;
    }
    
    void add_grade(int grade){
        ocjena.push_back(grade);
    }
    
    double average()const{
        double zbroj=0;
        for(int i : ocjena){
            zbroj=zbroj+i;
        }
        double prosjek=(zbroj/ocjena.size());
        return prosjek;
    }
    
    bool passed()const{
        return(average()>=2.0);
    }
};
int main(){
    vector<Student>studenti;
    Student s1("Ivan");
    s1.add_grade(4);
    s1.add_grade(3);
    
    Student s2("Laura");
    s2.add_grade(5);
    s2.add_grade(3);
    
    Student s3("Kate");
    s3.add_grade(2);
    s3.add_grade(5);
    
    studenti.push_back(s1);
    studenti.push_back(s2);
    studenti.push_back(s3);
    
    int brojac=0;
    for (const auto& s : studenti ){
        if(s.passed()){
            brojac++;
        }
    }
    cout<<"Broj studenata koji su polozili:  "<<brojac<<endl;
    
}
