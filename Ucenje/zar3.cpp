#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
//parne brojeve sortira uzlazno
using namespace std;
void funkcija(vector<int>& v, vector<int>& novi){
    copy_if(v.begin(), v.end(),back_inserter(novi),[](int x){
        return x%2==0;
    });
    sort(novi.begin(),novi.end(),[](int a,int b){
        return a>b;
    });
}
int main() {
    vector<int>v={1,8,3,6,5,4,7,2,};
    vector<int>novi;
    funkcija(v, novi);
    for(int i=0; i<novi.size();i++){
        cout<<novi.at(i)<<" ";
    }
    return 0;
 
}
