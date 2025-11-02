#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/* Napišite funkciju koja promijeni rečenicu tako da izbaci praznine i znakove interpunkcije,
 a između riječi ubaci znak ”-”.*/
void funkcija(string& s){
    auto it=s.begin();
    while(it!=s.end()){
       it= find_if(it, s.end(), [](char c){
            return c==' '||c=='!'||c=='?'||c=='.';
        });
        if(it==s.end()){break;}
        else{
            s.erase(it);
            it=s.insert(it, '-');
            ++it;
        }
        ++it;
    }
    cout<<"string je"<<s<<endl;
    
}
int main(){
    string s="Pas,je.mal i plav";
    funkcija(s);
    return 0;
}
