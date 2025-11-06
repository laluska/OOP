#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
/*funkcija prima vektor int sve neparne brojeve mnozi,a sve 0 mijenja sa 2*/
void funkcija(vector<int>& v){
    vector<int>novi;
    replace_if(v.begin(),v.end(),[](int x){
        return (x==0);
    },2);
    
    transform(v.begin(),v.end(),back_inserter(novi),[](int b){
        if(b%2==1){
            return b*2;
        }
        else{
            return b;
        }
    });
    for(int i : novi){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>v={0,2,3,0,4,5,6,7};
    funkcija(v);
    return 0;
}
