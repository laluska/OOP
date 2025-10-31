#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void word_to_pig_latin(const string& s){
    string samog="aeiouAEIOU";
    string novi=s;
    char c=s[0];
    auto it=(find(samog.begin(),samog.end(),c));
        if (it==samog.end()){
            novi.erase(novi.begin());
            novi.push_back(c);
            novi+="ay";
        }
        else{
            novi+="hay";
        }
    cout<<novi;
}

   

int main(){
    const string s="apple";
    word_to_pig_latin(s);
    return 0;
}
