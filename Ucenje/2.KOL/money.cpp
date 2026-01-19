#include <iostream>
using namespace std;

class money {
    int euri;
    int centi;

public:
    money(int e, int c = 0) {
        euri = e;
        centi = c;
    }

    friend ostream& operator<<(ostream& out, const money& obj);

    money operator+(const money& other) const {
        int totalCenti = centi + other.centi;
        int totalEuri = euri + other.euri + totalCenti / 100;
        totalCenti %= 100;

        return money(totalEuri, totalCenti);
    }
};

ostream& operator<<(ostream& out, const money& obj) {
    out << obj.euri << ".";
    if (obj.centi < 10) out << "0";  // da ispis bude 1.05 umjesto 1.5
    out << obj.centi << " €";
    return out;
}

int main() {
    money water(1, 50), coffe(2, 70), sugar(1);

    cout << "Total: " << water + coffe + sugar << endl;

    return 0;
}
