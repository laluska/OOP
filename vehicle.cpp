#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Vehicle{
protected:
    string naziv;
public:
    Vehicle(string s):naziv(s){}
    virtual void displayinfo()=0;
    virtual ~Vehicle() = default;
};
class Car:public Vehicle{
    string brand;
    string model;
public:
    
    Car(string b, string m, string s):Vehicle(s),brand(b),model(m){}
    void displayinfo()override{
        cout<<naziv<<" "<<brand<<" "<<model<<endl;
    }
};
class Bike:public Vehicle{
    string type;
    int gearcount;
public:
    
    Bike(string s, string t, int g):Vehicle(s),type(t),gearcount(g){}
    void displayinfo()override{
        cout<<naziv<<" "<<type<<" "<<gearcount<<endl;
    }
};
int main(){
    vector<Vehicle*>vehicles;
    vehicles.push_back(new Car("Auto","BMW","x6"));
    vehicles.push_back(new Bike("Bika","intersport",56));
    
    for(Vehicle* s : vehicles){
        s->displayinfo();
    }
    for(Vehicle* d : vehicles){
        delete d;
    }
    return 0;
}
