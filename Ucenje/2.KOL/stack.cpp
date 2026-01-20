#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
/*Napišite template klasu Stack koja omogućava rad sa stogom. Klasa treba sadržavati:
 · Metode push, pop i top.
 · Bacanje iznimke ako se pokušava izvaditi element iz praznog stoga.*/
template <typename T>
class Stack{
    vector<T>v;
public:
    void push(T x){
        v.push_back(x);
    }
    void pop(T x){
        v.pop_back();
    }
    T top(){
        if (v.empty()){
            throw logic_error("Stog je prazan");
        }
        return v.back();
    }
};
int main(){
    Stack<int> s;
    try{
        s.push(10);
        s.push(20);
        
        cout<<"Vrh:"<<s.top();
    }
    catch (const logic_error& e){
        cout<<"Greska"<<e.what();
        
    }
    
    return 0;
}
