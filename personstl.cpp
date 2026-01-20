#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Person{
private:
    string ime;
    string prezime;
public:
    Person()=default;
    Person(string i, string p):ime(i),prezime(p){}
    friend ostream& operator<<(ostream& out,const Person& obj);
    friend istream& operator>>(istream& in, Person& obj);
    string getPrezime()const{
        return prezime;
    }
};
ostream& operator<<(ostream& out, const Person& obj){
    out<<obj.ime<<" "<<obj.prezime;
    return out;
}
istream& operator>>(istream& in, Person& obj){
    in>>obj.ime>>obj.prezime;
    return in;
}
int main(){
    ifstream in("names.txt");
    vector<Person>persons;
    copy(istream_iterator<Person>(in), istream_iterator<Person>(), back_inserter(persons));
    
    sort(persons.begin(),persons.end(),[](const Person& a, const Person& b){
        return a.getPrezime()<b.getPrezime();
    });
    copy(persons.begin(),persons.end(),ostream_iterator<Person>(cout," "));
    return 0;
}
