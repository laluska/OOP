#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
/*. Napišite klasu ComplexNumber koja predstavlja kompleksne brojeve. Klasa treba sadržavati:
· Konstruktor s realnim i imaginarnim dijelom.
· Preopterećene operatore +, - i *.
· Metodu modulus() koja vraća apsolutnu vrijednost kompleksnog broja.*/
class ComplexNumber {
	int re;
	int im;
public:
	ComplexNumber(int r, int i) {
		re = r;
		im = i;
	}
	ComplexNumber operator+(const ComplexNumber& other) {
		return ComplexNumber(re + other.re,
			im + other.im);
	}

	ComplexNumber operator-(const ComplexNumber& other) {
		return ComplexNumber(re - other.re,
			im - other.im);
	}
	ComplexNumber operator*(const ComplexNumber& other) {
		return ComplexNumber((re * other.re) - (im * other.im),
			(re * other.im) + (im * other.re));
			
	}
	double modulus()const {
		return(sqrt(pow(re, 2) + pow(im, 2)));
	}

};
int main() {
	ComplexNumber a(5, 6);
	ComplexNumber b(3, 4);

	ComplexNumber c = a + b;
	ComplexNumber d = a * b;

	cout << c.modulus();

	return 0;
}
