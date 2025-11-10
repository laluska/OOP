#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*funkcija koja prima tri numericka argumenta num, len i k, a vraca vektor duljine len u kojem su visekratnici od num koji nisu visekratnivi od k u rastucem poretku po apsolutno vrijednosti*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> funkcija(int num, int len, int k){
    vector<int> v;
    int i = 1;

    while(v.size() < len){
        int visekratnik = num * i;
        if(visekratnik % k != 0){
            v.push_back(visekratnik);
        }
        i++;
    }

    sort(v.begin(), v.end(), [](int a, int b){
        return abs(a) < abs(b);
    });

    return v;
}

int main(){
    int num = 15;
    int len = 5;
    int k = 10;

    vector<int> rezultat = funkcija(num, len, k);

    for(int x : rezultat){
        cout << x << " ";
    }

    return 0;
}
