#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
#include <numeric>
//Napišite funkciju koja u vektoru zbraja samo parne elemente koji su kvadrati cijelih
//brojeva. Uvjet napišite u obliku lambda izraza.
using namespace std;
void funkcija(vector<int>& v){
    vector<int>novi;
    copy_if(v.begin(), v.end(), back_inserter(novi), [](int x){
        return ((x%2==0) && (sqrt(x)*sqrt(x)==x));
    });
    
    auto it= accumulate(novi.begin(), novi.end(), 0);
    
    cout<<"Zbroj je: "<<it;
    

    
}
int main() {
    vector<int>v={1,2,4,8,9,16,18,25,36};
    funkcija(v);

    return 0;
 
}
