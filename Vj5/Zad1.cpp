#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

class Karta {
public:
	int broj;
	string zog;

	Karta(int b, string z) {
		broj = b;
		zog = z;
	}

	void ispis() {
		cout << broj << " " << zog << endl;
	}
};

class Mac {
public:
	vector<Karta> karte;

	Mac(){
		vector<string> boje = { "Bati", "Spadi", "Dinara", "Kupi" };
		vector<int> brojevi = { 1,2,3,4,5,6,7,11,12,13 };
		for (auto& a : boje) {
			for (int i : brojevi) {
				karte.push_back(Karta(i, a));
			}
		}
	}

	void promjesaj() {
		random_device rd;
		mt19937 g(rd());
		shuffle(karte.begin(), karte.end(), g);
	}

	vector<Karta> podjeli(int n) {
		vector<Karta> ruka(karte.begin(), karte.begin() + n);
		karte.erase(karte.begin(), karte.begin() + n);
		return ruka;
	}

	void ispisisve() {
		for (auto& k : karte) {
			k.ispis();
		}
	}
};

class Igrac {
public:
	string ime;
	vector<Karta> ruka;
	int bodovi;

	Igrac(string i) {
		ime = i;
		bodovi = 0;
	}

	void podjelaKarata(vector<Karta> karte) {
		ruka = karte;
	}

	int akuza() {
		bodovi = 0;

		for (string boja : { "Bati", "Spadi", "Dinara", "Kupi"}) {
			bool ima1 = false, ima2 = false, ima3 = false;
			for (auto& a : ruka) {
				if (a.zog == boja) {
					if (a.broj == 1) ima1 = true;
					if (a.broj == 2) ima2 = true;
					if (a.broj == 3) ima3 = true;
				}
			}
			if (ima1 && ima2 && ima3) {
				bodovi += 3;
			}
		}

		for (int broj = 1; broj <= 3; broj++) {
			int cnt = 0;
			for (auto& a : ruka) {
				if (a.broj == broj) cnt++;
			}
			if (cnt == 3) bodovi += 3;
			if (cnt == 4) bodovi += 4;
		}

		return bodovi;
	}

	void ispisRuke() {
		cout << ime << " ima: " << endl;
		for (auto& a : ruka) {
			a.ispis();
		}
		cout << endl;
	}
};

int main() {
	Mac mac;
	mac.promjesaj();

	vector<Igrac> igraci;
	igraci.push_back(Igrac("Marcel"));
	igraci.push_back(Igrac("Maka"));
	igraci.push_back(Igrac("Reic"));
	igraci.push_back(Igrac("Tomo"));

	for (auto& a : igraci) {
		a.podjelaKarata(mac.podjeli(10));
	}

	cout << endl;
	cout << "bodovi iz akuze: " << endl;
	for (auto& a : igraci) {
		a.akuza();
		cout << a.ime << " ima " << a.bodovi << " bodova" << endl;
	}

	for (auto& a : igraci) {
		a.ispisRuke();
	}

	return 0;
}
