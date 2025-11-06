#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
/*definiraj klasu i posebne članove i funkcije kako bi sljedeci program ispravno radio 1.KOL. KLASA1*/
class Book{
public:
    string naziv;
    string imeAutora;
    
    Book(string n, string i){
        naziv=n;
        imeAutora=i;
    }
    void ispisi(){
        cout<<naziv<<" "<<imeAutora<<endl;
    }
    
};
class Library{
public:
    vector<Book>books;
    
    Library(int){}
    
    void addBook(Book b){
        books.push_back(b);
    }
    
    void listBooks(){
        for(auto& b : books){
            b.ispisi();
        }
    }
};
int main(){
    Library library(4);
    
    library.addBook(Book("Price", "I.B.M"));
    library.addBook(Book("Bajke", "Ivo Andric"));
    library.addBook(Book("Horor", ""));
    library.addBook(Book("Krimi", "R.L.S"));
    
    library.listBooks();
    
    return 0;
}
