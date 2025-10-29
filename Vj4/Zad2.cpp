#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
using namespace std;
void input_vector(vector<int>& v) {
    while (true) {
        int x;
        cout<<"Unesi broj"<<endl;
        cin>>x;
        
        if (x == 0) {
            break;
        }
        v.push_back(x);

    }
}
void print_vector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i)<<" ";
    }
}
void jedinstven_element(vector<int>&v){
    vector<int>jedinstveni;
    for(int i=0;i<v.size();i++){
        auto cnt= count(v.begin(),v.end(),v.at(i));
        if (cnt == 1){
            jedinstveni.push_back(v.at(i));
        }
    }
    cout<<"jedinstevni el. su: "<<endl;
    for(int i=0;i<jedinstveni.size();i++){
        cout<<jedinstveni.at(i)<<" ";
    }
    
    
}

void sortiranje(vector<int>&v){
    auto po_aps=[](int a, int b){
        return abs(a)<abs(b);
    };
    sort(v.begin(),v.end(),po_aps);
    cout<<"Brojevi sortirani po apsolutnoj vijednosti: "<<endl;
    for (int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    
}
int main() {
    vector<int>v;
    
    input_vector(v);
    print_vector(v);
    sortiranje(v);
    jedinstven_element(v);
    
}
