#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
/*Napišite program koji u vektoru brojeva pronalazi broj najbliži zadanom broju koristeći
 std::min_element i lambda izraz sa capture (capture je zadani broj).*/
void funkcija(vector<int>& v){
    int br=105;
    sort(v.begin(),v.end());
    auto it=max_element(v.begin(),v.end(),[br](int x, int y){
        return(abs(x-br)<abs(y-br));
    });
    
    cout<<"Najblizi broj je:"<<*it;
    
}
int main() {
    vector<int>v={42,33,21,100};
    funkcija(v);
}
