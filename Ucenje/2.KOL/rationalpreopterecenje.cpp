#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
/*4. Napišite klasu Rational koja predstavlja racionalni broj. Klasa treba sadržavati:
· Konstruktor koji prima brojnik i nazivnik.
· Preopterećene operatore +, - i /.
· Metodu simplify() koja skraćuje razlomak.
· Metodu toDouble() koja vraća decimalnu vrijednost razlomka.*/
int nzd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return abs(a);
}
class Rational {
	int br;
	int naz;
public:
	Rational(int b, int n) {
		br = b;
		naz = n;
	}
	Rational operator+(const Rational& other) {
		return Rational(br * other.naz + other.br * naz, naz * other.naz);
	}
	Rational operator-(const Rational& other) {
		return Rational(br * other.naz - other.br * naz, naz * other.naz);
	}
	Rational operator/(const Rational& other) {
		return Rational(br * other.naz, naz * other.br);
	}
	friend ostream& operator<<(ostream& out, const Rational& obj);

	Rational simplify() {
		int d = nzd(br, naz);
		br /= d;
		naz /= d;
		return Rational(br, naz);
	}
	double toDouble() {
		double c= static_cast<double> (br) / naz;
		return c;
	}
};
ostream& operator<<(ostream& out, const Rational& obj) {
	cout << obj.br<<"/";
	cout << obj.naz;
	return out;
}

int main() {
	Rational r1(3, 2);
	Rational r2(25, 5);
	Rational r = r1 + r2;
	cout << r << endl;

	Rational r3 = r1 - r2;
	cout << r3 << endl;

	Rational r4 = r2 / r1;
	cout << r4 << endl;

	Rational r5 = r2.simplify();
	cout << r5 << endl;
	double rez = r1.toDouble();
	cout << rez << endl;

	return 0;
}
