#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdexcept>
using namespace std;
template <typename T>
class compareMax{
    T a,b,c;
public:
    compareMax(T d, T e, T f):a(d),b(e),c(f){}
    T najveci()const{
        if(a==b & a==c){
            throw invalid_argument("svi isti");
        }
        if(a>b & a>c){
            return a;
        }
        if(b>a & b>c){
            return b;
        }
        else{
            return c;
        }
    }
};

int main(){
    try{
        compareMax x(4,4,4);
        cout<<x.najveci();
    }
    catch(const exception& e){
        cout<<"Greška"<<e.what();
    }
    return 0;
};
