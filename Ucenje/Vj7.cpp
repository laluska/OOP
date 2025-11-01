#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*Inicijalizirajte vektor stringova. Napišite funkciju koja stringove iz vektora sprema u
rečenicu tako da svaku riječ okrene naopako.*/
void funkcija(vector<string>& v){
    vector<string>novi;
    for(string s : v){
        reverse(s.begin(),s.end());
        novi.push_back(s);
    }
    for(string i : novi){
        cout<<i<<" ";
    }
    
}
int main() {
    vector<string>v={"vatra","voda","nebo"};
    funkcija(v);
    return 0;
}
