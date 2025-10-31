#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*Kod string c chat kaze da triba koristiti referencu jer na taj nacin on mijenja kopiju a ne originalni vektor medutim radi i bez & ne razumin zasto ako je & za adresu adresa cega meni triba ako c nije deklariran uopce*/
void reverse_strings(vector<string>&s){
    for(string c: s){
        reverse(c.begin(),c.end());
        cout<<c<<' ';
    }
}

   

int main(){
    vector<string>s={"apple", "word", "krava"};
    reverse_strings(s);

    return 0;
}
