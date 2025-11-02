#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;
/*Napišite program koji sortira vektor stringova po duljini stringa (od najkraćeg prema
 najdužem) koristeći std::sort s lambda funkcijom.*/
void funkcija(vector<string>& v){
    sort(v.begin(), v.end(),[](string a, string b){
        return (a.size()<b.size());
    });
    
    for (string s : v){
        cout<<s<<endl;
    }

}
int main(){
    vector<string>v={"oko","kisa","labudica","an","laura",};
    funkcija(v);
    
    return 0;
}
