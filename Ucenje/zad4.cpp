#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
#include <numeric>
//zbaci sve brojeve koji su manji od srednje vrijednosti (average) vektora.
//Koristi accumulate i remove_if.
using namespace std;
void funkcija(vector<int>& v){
    int suma=accumulate(v.begin(), v.end(), 0);
    double average=suma/v.size();
    auto it=remove_if(v.begin(),v.end(),[average](int x){
        return x<average;
        
    });
    v.erase(it,v.end());


}
int main() {
    vector<int>v={1,2,35,45,5,65,7,8,55};
    funkcija(v);
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<' ';
    }
    return 0;
 
}
