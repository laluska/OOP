#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
template <typename T>
class Calculator {
	T br1;
	T br2;
public:
	Calculator(T b, T c) :br1(b), br2(c) {}

	T multiply() {
		T r = br1 * br2;
		return r;
	}

	T devide() {
		if (br2 == 0) {
			throw logic_error("Ne moze se dijeliti s 0");
		}
		return static_cast<T>(br1) / br2;
	}
};
int main() {
	Calculator<double>c1(100.0, 50);

	cout << "Mnozenje: " << c1.multiply() << endl;

	try {
		cout << "Dijeljenje: " << c1.devide() << endl;
	}
	catch (const logic_error& e) {
		cout << "Greska: " << e.what() << endl;
	}

	return 0;
}
