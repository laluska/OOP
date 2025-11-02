#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
/*Napišite funkciju koja riječi iz rečenice (std::string) sprema u vektor stringova (std::vector
 <std::string>).*/
void funkcija(string& s){
    vector<string>novi;
    string rijec;
    stringstream ss(s);
    while(ss>>rijec){ //je li ovo automatski pusha rijec iz stringa u rijec
        novi.push_back(rijec);
    }
    for(string i : novi){
        cout<<i<<endl;
    }
    
}
int main(){
    string s="Bobi je maltezer";
    funkcija(s);
    
}
