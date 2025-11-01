#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
//Napišite funkciju koja provjerava je li jedna riječ palindrom.
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
    string s = "level";
    funkcija(s);
    
    return 0;
}
