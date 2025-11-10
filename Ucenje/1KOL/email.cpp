#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void funkcija(string& s){
    auto it = find(s.begin(), s.end(), '@');

    if(it == s.end()){
        cout << "email nije valjan";
        return;
    }

    for(int i = 0; i < distance(s.begin(), it); i++){
        if(isalnum(s[i])){
            auto it1 = find(it + 1, s.end(), '@');
            
            if(it1 == s.end()){
                auto it2 = find(it + 1, s.end(), '.');
                if(it2 != s.end()){
                    int indeks = distance(s.begin(), it2);
                    
                    if(isalnum(s[indeks - 1]) && isalnum(s[indeks + 1])){
                        cout << "email je valjan";
                    }
                    else{
                        cout << "email nije valjan";
                    }
                }
                else{
                    cout << "email nije valjan";
                }
            }
            else{
                cout << "email nije valjan";
            }
            return;
        }
    }

    cout << "email nije valjan";
}

int main(){
    string s = "aaa@gmail.com";
    funkcija(s);
    return 0;
}
