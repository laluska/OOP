#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include <exception>
#include <numeric>
using namespace std;
class Razlomak {
	int brojnik;
	int nazivnik;
public:
	Razlomak(int b, int n) :brojnik(b),nazivnik(n) {}
	void skrati() {
		int d = std::gcd(brojnik, nazivnik);
		brojnik /= d;
		nazivnik /= d;
	}
	Razlomak operator+(const Razlomak& other) {
		 Razlomak r (brojnik * other.nazivnik + other.brojnik * nazivnik,nazivnik*other.nazivnik);
		 r.skrati();
		 return r;
	}
	
	friend ostream& operator<<(ostream& out, const Razlomak& obj);
};
ostream& operator<<(ostream& out, const Razlomak& obj) {
	out << obj.brojnik << "/" << obj.nazivnik;
	return out;
}

int main() {
	Razlomak r1(12, 6);
	Razlomak r2(4, 2);
	cout << r1 + r2;
	
	return 0;
}
