#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
/*Napišite klasu Currency koja predstavlja valutu. Klasa treba sadržavati:
· Konstruktor koji prima iznos i oznaku valute.
· Preopterećene operatore + i - za rad s valutama.
· Metodu convert() koja konvertira valutu u drugu valutu koristeći tečaj..*/
class Currency {
	double iznos;
	string oznaka;
public:
	Currency(double i, string s) {
		iznos = i;
		oznaka = s;
	}
	Currency operator+(const Currency& other) {
		if (oznaka == other.oznaka) {
			return Currency(iznos + other.iznos, oznaka);
		}
	}
	Currency operator-(const Currency& other) {
		if (oznaka == other.oznaka) {
			return Currency(iznos - other.iznos, oznaka);
		}
	}
	Currency convert(const Currency& other) {
		double k = 1.55;
		
		return Currency(k * iznos, other.oznaka);
	
	}
	friend ostream& operator<<(ostream& out, const Currency& obj);
};
ostream& operator<<(ostream& out, const Currency& obj) {
	out << obj.iznos;
	out << obj.oznaka;
	return out;
}
int main() {
	Currency c1(150, "$");
	Currency c2(50, "E");

	Currency c3 = c1 + c2;
	cout << c3 << " ";

	Currency c4 = c1 - c2;
	cout << c4 << " ";

	Currency c5 = c1.convert(c2);
	cout << c5 << endl;

	return 0;
}
