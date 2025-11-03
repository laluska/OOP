#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
// Napišite funkciju koja provjerava je li jedna rečenica palindrom (ignoriraju se praznine
//i znakovi interpunkcije).
using namespace std;
bool funkcija(string& s){
    auto it=remove_if(s.begin(), s.end(),[](char c){
        return ((ispunct(c))||c==' ');
    });
    s.erase(it,s.end());
    string novi=s;
    reverse(novi.begin(), novi.end());
    
    return(novi==s);

    
}
int main(){
    string s="Marko,   okraM..";
    if(funkcija(s)){
        cout<<"String je palindrom ";
    }
    else{
        cout<<"String nije palindrom ";
    }
    
    return 0;
}
