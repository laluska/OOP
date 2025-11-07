#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*Napišite funkciju koja riječi iz rečenice (std::string) sprema u vektor stringova (std::vector
 <std::string>).*/
void funkcija(string& s) {
    vector<string>novi;
    auto start=s.begin();
    while(start!=s.end()){
        auto it=find(start,s.end(),' ');
        string rijec=s.substr(distance(s.begin(),start),distance(start, it));
        novi.push_back(rijec);
        if(it==s.end()){
            break;
        }
        start=it+1;
    }
    for(string i : novi){
        cout<<i<<endl;
    }
}

int main() {
    string s = "John Johny Depp";
    funkcija(s);
    return 0;
}
