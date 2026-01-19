#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iterator>

using namespace std;
class Vektor {
private:
    int x;
    int y;
public:
    Vektor(int i, int j) :x(i), y(j) {}
    Vektor operator*(const Vektor& other) {
        return Vektor(x * other.x, y * other.y);
    }

    Vektor operator*(int k) {
        int prvi=k*x;
        int drugi = k * y;
        return Vektor(prvi,drugi);
    }
    friend ostream& operator<<(ostream& out,const Vektor& obj);
};
ostream& operator<<(ostream& out, const Vektor& obj) {
    out << obj.x <<" "<< obj.y;
    return out;
}

int main() {
    Vektor v1(5, 3);
    Vektor v2(6, 3);
    int k = 2;

    cout << v1 * v2<<endl;
    cout << v2 * k;

    return 0;
}
