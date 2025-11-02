#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
/* Napišite funkciju koja za string koji predstavlja ime i prezime vraća string u kojem su
 inicijali.
 "John Johnny Depp"-> "J.J.D."*/
string funkcija(string& s){
    stringstream ss(s);
    string rijeci;
    string inicijali;
    while(ss>>rijeci){
        char c=toupper(rijeci[0]);
        inicijali.push_back(c);
        inicijali+='.';
    }
    
    return inicijali;
}
int main(){
    string s="laura duje ivan Marcel";
    cout<<funkcija(s);
    return 0;
}
