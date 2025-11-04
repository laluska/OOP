#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
/* Napišite program koji u vektoru stringova pronalazi najduži i najkraći string koristeći
 std::max_element i std::min_element s lambda funkcijom.*/

void funkcija(vector<string>& s){
    auto it_min=min_element(s.begin(), s.end(),[](string& a, string& b){
        return(a.size()<b.size());
    });
    
    auto it_max=max_element(s.begin(), s.end(),[](string& a, string&b){
        return(a.size()>b.size());
    });
    
    string najmanji=(*it_min);
    string najveci=(*it_max);
    
    cout<<"najmanji string je"<<najmanji;
    cout<<"najveci je : "<<najveci;
    
}
int main(){
    vector<string>s={"string","oko","vata","limunada"};
    funkcija(s);
    return 0;
}
