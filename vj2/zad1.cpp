#include<iostream>
using namespace std;
int *funkcija(int n) {
	int *brojevi = new int[n];
	brojevi[0] = 1;
	brojevi[1] = 1;
	for (int i = 2; i < n; i++) {
		brojevi[i] = brojevi[i - 1] + brojevi[i - 2];
	}
	return brojevi;
}
int main() {
	int n = 7;
	int *niz = funkcija(n);
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}

	delete[] niz;
	return 0;
}
