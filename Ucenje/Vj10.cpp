#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
/*Napišite funkciju koja u rečenici nakon svakog samoglasnika doda slovo ’p’ i sam samoglasnik. Koristite funkcije STL-a find, insert.
 "Ja sam dobro"-> "Japa sapam dopobropo"*/
void funkcija(string& s){
    auto it=s.begin();
    while(it!=s.end()){
        it=find_if(it, s.end(),[](char c){
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        });
        if(it!=s.end()){
            char x=(*it);
            it=s.insert(it+1,'p'); //PAZI TRIBA SPREMIT VRIJEDNOST U ITERATOR
            it=s.insert(it+1,x);
            
        }
        else{
            break;
        }
        it++;
    }
    cout << s ;
}
int main(){
    string s="Ja sam dobro";
    funkcija(s);
    
    return 0;
}

