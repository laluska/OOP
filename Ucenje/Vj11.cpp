#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*  Napišite funkciju koja u rečenici iza svakog samoglasnika doda znak ”:”.*/
void funkcija(string& s){
    auto it=s.begin();
    while(it!=s.end()){
       it= find_if(it, s.end(), [](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                   c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        });
        if(it==s.end()){break;}
        else{
            it=s.insert(it+1, ':');
            ++it;
        }
        ++it;
    }
    cout<<"string je"<<s<<endl;
    
}
int main(){
    string s="Pas je mal";
    funkcija(s);
    return 0;
}
