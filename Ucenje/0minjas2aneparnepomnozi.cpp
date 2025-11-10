#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void funkcija(vector<int>& v){
    transform(v.begin(), v.end(),v.begin(),[](int x){
        if(x%2==0){
            return x;
        }
        else{
            return x*2;
        }
        
    });
    
    replace_if(v.begin(), v.end(),[](int x){
        return(x==0);
    }, 2);
    
    for(int n : v){
        cout<<n<<" ";
    }
}
int main(){
    vector<int>v={0,3,0,7,2,9,0,5,8};
    funkcija(v);
    return 0;
}
