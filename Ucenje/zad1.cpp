#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> parni(vector<int>& v){
    vector<int>novi;
    for(int i : v){
        if(i%2==0){
            novi.push_back(i);
        }
    }
    return novi;
}


int main(){
    vector<int>v={1,2,3,4,5,6,7,8,9};
    vector<int>novi1=parni(v);
    for(size_t i=0;i<novi1.size();i++){
        cout<<novi1[i];
    }
    return 0;
}
