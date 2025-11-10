#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void funkcija(vector<int>& v, int k, int n){
    auto it=v.begin();
    while(it!=v.end()){
        it=find_if(it,v.end(),[n](int c){
            return (c==n);
        });
        if(it!=v.end()){
            it=v.erase(it);
        }
    }
    auto it1=v.begin();
    while(it1!=v.end()){
        it1=find_if(it1,v.end(),[k](int c){
            return (c==k);
        });
        if(it1!=v.end()){
            it1=v.insert(it1+1, 0);
        }
    }
    for(int s : v){
        cout<<s<<" ";
    }
    
}
int main(){
    vector<int>v={1,2,3,4,5};
    int n=2;
    int k=3;
    funkcija(v, k, n);
    return 0;

}
