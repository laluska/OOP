#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;
/* Napišite funkciju koja prima dva vektora i vraća vektor onih elemenata koji se nalaze
 u prvom vektoru, ali se ne nalaze u drugom. Koristite std::binary_search.*/
vector<int> funkcija(vector<int>& v1, vector<int>v2){
    vector<int>novi;
    for(int i: v1){
        bool postoji=binary_search(v2.begin(),v2.end(),i);
        if (postoji==false){
            novi.push_back(i);
        }
    }

    
    return novi;
}
int main(){
    vector<int>v1={1,2,3,4,5,6,7};
    vector<int>v2={4,5,6,7,8,9,10};
    vector<int>novi=funkcija(v1,v2);
    for(int i : novi){
        cout<<i<<" ";
    }
    return 0;
}
