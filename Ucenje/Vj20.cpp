#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;
/*  Napišite program koji iz vektora cijelih brojeva filtrira sve brojeve veće od 10, kvadrira
 ih i sprema u novi vektor. Za filtriranje koristite lambda izraz.*/
void funkcija(vector<int>& v){
    vector<int>novi;
    
    copy_if(v.begin(), v.end(), back_inserter(novi),[](int x){
        return (x>10);
    });
    
    for(int &x:novi){
        x=x*x;
    }
    
    for(int i : novi){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>v={1,2,3,4,5,6,10,11,12};
    funkcija(v);
    return 0;
}
