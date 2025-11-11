#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
void funkcija(string& s){
    string temp;
    auto start=s.begin();
    
    while(start!=s.end()){
        auto it=find(start,s.end(), ' ');
        
        string rijec(start,it);
        sort(rijec.rbegin(),rijec.rend());
        
        temp+=rijec;
        
        if(it != s.end()){
            temp += ' ';
            it++;
        }
        
        
        rijec="";
        start=it;
        
        
    }
    
    reverse(temp.begin(),temp.end());
    cout<<temp;
}


int main(){
    string s="practice makes perfect";
    funkcija(s);
    return 0;
}
