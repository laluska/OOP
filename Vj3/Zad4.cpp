#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string JMBAG;
    int godinaStudija;
    int ects;
    double prosjek;
};

void filter_students(Student studenti[], size_t velicina,
                     void (*akcija)(Student&),
                     bool (*filter)(Student&)) {
    for (size_t i = 0; i < velicina; i++) {
        if (filter(studenti[i])) {
            akcija(studenti[i]);
        }
    }
}

void ispisiStudenta(Student &s) {
    cout << "Ime: " << s.ime
         << ", JMBAG: " << s.JMBAG
         << ", Godina: " << s.godinaStudija
         << ", ETCS: " << s.ects
         << ", Prosjek: " << s.prosjek
         << endl;
}

void povecajGodinu(Student &s) {
    s.godinaStudija++;
}

int main() {
    Student studenti[] = {
        {"Ana", "001", 1, 3, 4.0},
        {"Ivan", "002", 2, 50, 3.2},
        {"Marko", "003", 1, 0, 3.8},
        {"Lucija", "004", 3, 60, 4.2},
        {"Petra", "005", 2, 45, 3.6}
    };
    size_t velicina = sizeof(studenti)/sizeof(studenti[0]);

    auto prviGodinaSaIspitom = [](Student &s){
        return s.godinaStudija == 1 && s.ects > 0;
    };

    auto prosjekVeciOd35 = [](Student &s){
        return s.prosjek > 3.5;
    };

    auto ects45iliVise = [](Student &s){
        return s.ects >= 45;
    };

    cout << " prva godina koji su položili barem jedan ispit:\n";
    filter_students(studenti, velicina, ispisiStudenta, prviGodinaSaIspitom);

    cout << "studenti sa prosjekom većim od 3.5:\n";
    filter_students(studenti, velicina, ispisiStudenta, prosjekVeciOd35);

    cout << " godine studija za studente sa >=45 ETCS:\n";
    filter_students(studenti, velicina, povecajGodinu, ects45iliVise);

    cout << "\nStudenti nakon povećanja godine:\n";
    for (size_t i = 0; i < velicina; i++) {
        ispisiStudenta(studenti[i]);
    }

    return 0;
}
