#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
// Napišite funkciju koja provjerava je li jedna rečenica palindrom (ignoriraju se praznine
//i znakovi interpunkcije).
using namespace std;
void funkcija(string& s) {
    string novi=s;
    reverse(novi.begin(),novi.end() );
    if(s == novi){
        cout<<"String je palindrom";
    }
    else{
        cout<<"String nije palindrom";
    }
    
   
}
 
int main() {
    string s;
    cout<<"Unesi string";
  //je li ovo dobro i zasto moram koristiti cin i zasto ne radi kad sama unosim
    cin>>s;
    funkcija(s);
    
    return 0;
}
