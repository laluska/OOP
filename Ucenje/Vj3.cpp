#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
//Napišite funkciju koja broji broj riječi u rečenici.
using namespace std;
int funkcija(string& s) {
    int cnt=count_if(s.begin(), s.end(),[](char x){
        return x==' ';
    });
    return cnt +1;  //najjednostavniji nacin ali ne znam jel se ovako moze
}
int main() {
    string s = "kuca je skakutala i pjevala i p i n.";
    cout<<"Broj rijeci je:"<<funkcija(s);
    return 0;
}
