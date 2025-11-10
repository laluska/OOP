#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*izbinarnog u oktalni*/
void funkcija(vector<string>& v){
    int temp=0;
    vector<int>novi;
    for(string i : v){
        for(int n=0;n<i.size();n++){
            temp+=(i[i.size()-1-n]-'0')*pow(2, n);
        }
        novi.push_back(temp);
        temp=0;
    }

    for(int x : novi){
        cout<<x<<" ";
    }
    
}
int main(){
    vector<string>v={"111","101","001"};
    funkcija(v);
    return 0;
}
