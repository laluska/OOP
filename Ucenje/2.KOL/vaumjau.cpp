#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;
class Animal {
protected:
	string naziv;
public:
	Animal(string s) :naziv(s){}
	virtual string sound() = 0;
	virtual void print() = 0;
	virtual ~Animal()=default;

};
class Dog :public Animal {
public:
	Dog(string s ) :Animal(s) {}
	string sound()override {
		string t = "Woof";
		return t;
	}
	void print()override {
		cout << naziv;
		cout << sound() << endl;
	}
};
class Cat :public Animal {
public:
	Cat(string s) :Animal(s) {}
	string sound()override {
		string p = "Mjau";
		return p;
	}
	void print()override {
		cout << naziv;
		cout << sound() << endl;
	}
};
int main() {
	vector<Animal*>animals;
	animals.push_back(new Dog("Pas"));
	animals.push_back(new Cat("Maca"));

	for (auto* c : animals) {
		c->print();
	}

	for (auto* b : animals) {
		delete b;
	}

	return 0;
}
