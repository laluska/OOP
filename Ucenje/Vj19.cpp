#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;
/*  Napišite program koji u vektoru brojeva uklanja sve duplikate koristeći std::sort i
 std::remove.*/
void funkcija(vector<int>& v){
    sort(v.begin(), v.end());
    int i=0;
    auto it=remove_if(v.begin()+1, v.end(),[&i](int x){
        if(i==x){
            return true;
        }
        else{
            i=x;
            return false;
        }
    });
        
    v.erase(it,v.end());

    
    for(int i : v){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>v={1,2,6,3,5,4,5,4,6,2,7,8,9};
    funkcija(v);
    return 0;
}
