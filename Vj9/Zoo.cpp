#include "Zoo.h"

Animal::Animal(std::string n, int a, double w)
    : name(n), age(a), weight(w) {
    if (name.empty() || age < 0 || weight <= 0)
        throw std::invalid_argument("invalid");
}

Mammal::Mammal(std::string n, int a, double w, bool f)
    : Animal(n, a, w), hasFur(f) {
    std::cout << (hasFur ? "Stvoren sisavac s dlakom" : "Stvoren sisavac s malo dlake") << std::endl;
}

Aquatic::Aquatic(std::string n, int a, double w, double d)
    : Animal(n, a, w), maxDiveDepth(d) {
    std::cout << "Stvorena vodena zivotinja koja roni do " << maxDiveDepth << "m" << std::endl;
}

Lion::Lion(std::string n, int a, double w)
    : Animal(n, a, w), Mammal(n, a, w, true) {}

std::string Lion::getSpecies() const { return "Lion"; }

double Lion::getDailyFood() const {
    double f = weight * 0.06;
    if (f == 0) throw std::logic_error("food");
    return f;
}

std::string Lion::getName() const { return name; }

Elephant::Elephant(std::string n, int a, double w)
    : Animal(n, a, w), Mammal(n, a, w, false) {}

std::string Elephant::getSpecies() const { return "Elephant"; }

double Elephant::getDailyFood() const {
    double f = weight * 0.04;
    if (f == 0) throw std::logic_error("food");
    return f;
}

std::string Elephant::getName() const { return name; }

Dolphin::Dolphin(std::string n, int a, double w)
    : Animal(n, a, w), Mammal(n, a, w, true), Aquatic(n, a, w, 300.0) {}

std::string Dolphin::getSpecies() const { return "Dolphin"; }

double Dolphin::getDailyFood() const {
    double f = weight * 0.05;
    if (f == 0) throw std::logic_error("food");
    return f;
}

std::string Dolphin::getName() const { return name; }

SeaTurtle::SeaTurtle(std::string n, int a, double w)
    : Animal(n, a, w), Aquatic(n, a, w, 200.0) {}

std::string SeaTurtle::getSpecies() const { return "SeaTurtle"; }

double SeaTurtle::getDailyFood() const {
    double f = weight * 0.03;
    if (f == 0) throw std::logic_error("food");
    return f;
}

std::string SeaTurtle::getName() const { return name; }

int ZooKeeper::totalAnimalsServed = 0;

void ZooKeeper::processAnimal(Animal* a) {
    std::cout << "Species: " << a->getSpecies()
              << ", Name: " << a->getName()
              << ", Food: " << a->getDailyFood() << "kg" << std::endl;
    totalAnimalsServed++;
}

int ZooKeeper::getTotalAnimalsServed() {
    return totalAnimalsServed;
}

int main() {
    try {
        ZooSection<Animal> section;
        ZooKeeper keeper;

        section.addAnimal(std::make_unique<Lion>("Simba", 5, 190));
        section.addAnimal(std::make_unique<Elephant>("Dumbo", 10, 5000));
        section.addAnimal(std::make_unique<Dolphin>("Flipper", 7, 150));
        section.addAnimal(std::make_unique<SeaTurtle>("Leonardo", 80, 300));

        for (size_t i = 0; i < section.size(); i++)
            keeper.processAnimal(section.getAnimal(i));

        std::cout << section.totalFood() << std::endl;
        std::cout << ZooKeeper::getTotalAnimalsServed() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
