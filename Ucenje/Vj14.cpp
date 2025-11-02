#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;
/*Napišite funkciju koja od dva vektora formira treći u kojem su svi elementi prva dva
 vektora, ali sortirani i jedinstveni.*/
void funkcija(vector<int>& v1, vector<int>v2){
    vector<int>novi;
    for(int i : v1){
        novi.push_back(i);
    }
    for(int j : v2){
        novi.push_back(j);
    }
    
    sort(novi.begin(),novi.end());
    novi.erase(unique(novi.begin(),novi.end()),novi.end());
    
    for(int n : novi){
        cout<<n<<" ";
    }

    
}
int main(){
    vector<int>v1={1,2,3,3,4,5,6,7};
    vector<int>v2={4,5,6,7,8,9,10};
    funkcija(v1,v2);
    
    return 0;
}
