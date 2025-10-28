#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
void input_vector(vector<int>& v) {
	while (true) {
		int x;
		cout << "Unesi broj" << endl;
		cin >> x;
		if (x == 0) {
			break;
		}
		v.push_back(x);

	}
}
void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i);
	}
}

int main() {
	vector<int>brojevi;
	
	input_vector(brojevi);
	print_vector(brojevi);


}
