#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;
/*Napišite funkciju koja duplicira sve elemente vektora. Koristite insert*/
void funkcija(vector<int>& v){
    for(int i=v.size()-1; i>=0 ;i--){
        v.insert(v.begin()+i,v[i] );
    }
    sort(v.begin(),v.end());
    for(int j : v){
        cout<<j<<" ";
    }
}
int main(){
    vector<int>v={1,2,3,4,5,6,7};
    funkcija(v);
    
    return 0;
}
