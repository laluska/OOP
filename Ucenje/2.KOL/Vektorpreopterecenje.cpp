#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
/*
Napišite klasu Vector2D koja sadrži:
- atribute double x, y
- konstruktor Vector2D(double x, double y)
- operator + za zbrajanje vektora
- operator - za oduzimanje vektora
- operator * za množenje skalarom
- metodu length() koja vraća sqrt(x*x + y*y)
*/
class Vector2D {
	double a;
	double b;
public:
	Vector2D(double x, double y) {
		a = x;
		b = y;
	}
	Vector2D operator+(const Vector2D& other) {
		return Vector2D(a + other.a, b + other.b);
	}
	Vector2D operator-(const Vector2D& other) {
		return Vector2D(a - other.a, b - other.b);
	}
	Vector2D operator*(double k) {
		return Vector2D(k * a, k * b);
	}
	double lenght() {
		return (sqrt(a*a+b*b));
	}
	friend ostream& operator<<(ostream& out, const Vector2D obj);
};
ostream& operator<<(ostream& out, const Vector2D obj) {
	out << obj.a<<"i"<<"+";
	out << obj.b<<"j";
	return out;
}
int main() {
	Vector2D v1(12, 3);
	Vector2D v2(13, 20);
	Vector2D c = v1 + v2;
	cout << c << endl;
	Vector2D d = v1 - v2;
	cout << d<< endl;
	Vector2D e = v1 * 3;
	cout << e<< endl;
	cout << v1.lenght() << endl;

	return 0;
}
