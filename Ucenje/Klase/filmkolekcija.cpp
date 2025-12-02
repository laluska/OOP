#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Film{
    string naziv;
    int godina;
public:
    Film(string n, int g){
        naziv=n;
        godina=g;
    }
    string getNaziv()const{
        return naziv;
    }
    int getGodina()const{
        return godina;
    }
   

};
class Kolekcija{
    string ime;
    vector<Film>filmovi;
public:
    Kolekcija(string i){
        ime=i;
    }
    void dodajFilm(const Film& f){
        filmovi.push_back(f);
    }
    void ispisiStarijeOd(int x){
        for(auto& s : filmovi){
            if(s.getGodina()<x){
               
                cout<<s.getNaziv()<<" ";
                cout<<s.getGodina()<<endl;
            }
        }
    }
    
    void ispisiMladjeOd(int y){
        for(auto& z : filmovi){
            if(z.getGodina()>y){
                
                cout<<z.getNaziv()<<" ";
                cout<<z.getGodina()<<endl;
            }
        }
    }
};
int main() {
    // Kreiramo filmove
    Film f1("Inception", 2010);
    Film f2("Titanic", 1997);
    Film f3("Matrix", 1999);
    Film f4("Interstellar", 2014);
    
    // Kreiramo kolekciju
    Kolekcija k1("Moji filmovi");
    
    // Dodavanje filmova u kolekciju
    k1.dodajFilm(f1);
    k1.dodajFilm(f2);
    k1.dodajFilm(f3);
    k1.dodajFilm(f4);
    
    // Ispis filmova starijih od 2000
    cout << "Filmovi stariji od 2000:\n";
    k1.ispisiStarijeOd(2000);
    //Ispis filmova mladjih od 2010
    k1.ispisiMladjeOd(2010);
    
    
    
    return 0;
    
}
