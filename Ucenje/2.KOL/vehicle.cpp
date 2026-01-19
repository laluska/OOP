#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Vehicle {
protected:
	double brzina;
	double udaljenost;
public:
	Vehicle(int b, double u) :brzina(b),udaljenost(u){}

	virtual double fuel_comsumption() = 0;
	virtual void print() = 0;

	virtual ~Vehicle()=default;
};
class Car : public Vehicle {
public:
	Car(int b, double u):Vehicle(b,u){}
	double fuel_comsumption()override {
		double rez = udaljenost / brzina;
		return rez;
	}
	void print()override {
		cout << brzina << " " << udaljenost << " " << fuel_comsumption() << endl;
	}
};
class Truck :public Vehicle {
public:
	Truck(int b, double u) :Vehicle(b, u) {}
	double fuel_comsumption()override {
		double rez = udaljenost / brzina;
		return rez;
	}
	void print()override {
		cout << brzina << " " << udaljenost << " " << fuel_comsumption() << endl;
	}
};
int main() {
	vector<Vehicle*>vehicles;
	vehicles.push_back(new Car(120,500));
	vehicles.push_back(new Truck(60, 100));
	for (Vehicle* a: vehicles) {
		a->print();
	}
	for (Vehicle* b : vehicles) {
		delete b;
	}
	
	return 0;
}
