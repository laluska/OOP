#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Appliance{
protected:
    string name;
    double sati;
    double snaga;
public:
    Appliance(string n, double sa, double sn):name(n),sati(sa),snaga(sn){}
    virtual double powerUsage()=0;
    virtual void print()=0;
    virtual ~Appliance()=default;
};
class WashingMachine:public Appliance{
    public:
    WashingMachine(string n, double sa, double sn):Appliance(n,sa,sn){}
    double powerUsage()override{
        double rez=snaga/sati;
        return rez;
    }
    void print()override{
        cout<<name<<" "<<snaga<<" "<<sati<<" "<<powerUsage()<<endl;
    }
    
};
class Refrigerator:public Appliance{
public:
    Refrigerator(string n, double sn, double sa):Appliance(n,sa,sn){}
    double powerUsage()override{
        double rez1=snaga/sati;
        return rez1;
    }
    void print()override{
        cout<<name<<" "<<snaga<<" "<<sati<<" "<<powerUsage();
    }
};
int main(){
    vector<Appliance*>appliances;
    appliances.push_back(new Refrigerator("frizider",150,20));
    appliances.push_back(new WashingMachine("Mašina",500,45));
    
    for(Appliance* e: appliances){
        e->print();
    }
    for(Appliance* s : appliances){
        delete s;
    }
    
    return 0;
}
