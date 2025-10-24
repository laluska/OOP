#include <iostream>
#include <algorithm>
#include <cstddef>
using namespace std;
inline bool ascending(int a, int b){
    if (a>b){
        return true;
    }
    else{
        return false;
    }
}

inline bool descending(int a, int b){
    if (a>b){
        return false;
    }
    else{
        return true;
    }
}
void sort(int niz[], size_t n, bool (*cmp)(int,int)){
   for(int i=0; i< n; i++){
       for(int j=i+1;j<n;j++){
           if(cmp(niz[i],niz[j])){
               swap(niz[i],niz[j]);
           }
       }
        
    }

    
}

int main(){
    int niz[]={2,1,3,9,5,4,7};
    size_t n=7;
    
    sort(niz,n,ascending);
    cout<<"Uzlazno:"<<endl;
    for(int i=0;i<n;i++){
        cout<<niz[i]<<endl;
    }
    sort(niz,n,descending);
    cout<<"silazno:"<<endl;
    for(int i=0;i<n;i++){
        cout<<niz[i]<<endl;
    }
    
    return 0;
}
