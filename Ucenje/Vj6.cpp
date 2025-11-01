#include <iostream>
#include <algorithm>
using namespace std;
//Napišite funkciju koja provjerava je li jedna rečenica palindrom (ignoriraju se praznine
//i znakovi interpunkcije).
void funkcija(string& s) {
    string novi = s;

    novi.erase(remove_if(novi.begin(), novi.end(), [](char x){
        return (x == ' ') || (x == '.') || (x == ',');
    }), novi.end());

    string obrnuto = novi;
    reverse(obrnuto.begin(), obrnuto.end());

    if (novi == obrnuto) {
        cout << "String je palindrom ";
    } else {
        cout << "String nije palindrom ";
    }
}

int main() {
    string s = "a man, a plan, a canal, panama";
    funkcija(s);
    return 0;
}
