#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void fix_spaces(string&s){
    auto it=unique(s.begin(),s.end(),[](char a, char b){
        return a == ' ' && b==' ';
    });
    s.erase(it,s.end());
    
    for(auto it2=s.begin();it2!=s.end();it2++){
        if (*it2==','|| *it2=='.'){
            if (*(it2 - 1) == ' '){
                it2=s.erase(it2-1);
            }
        }
    }
    
}
int main(){
    string s="Puno   razmaka   ,    i  tocka  .";
    fix_spaces(s);
    cout<<s;
    return 0;
}
