#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class Animal {
protected:
    std::string name;
    int age;
    double weight;

    Animal(std::string, int, double);

public:
    virtual ~Animal() = default;

    virtual std::string getSpecies() const = 0;
    virtual double getDailyFood() const = 0;
    virtual std::string getName() const = 0;
};

class Mammal : virtual public Animal {
protected:
    bool hasFur;

public:
    Mammal(std::string, int, double, bool);
};

class Aquatic : virtual public Animal {
protected:
    double maxDiveDepth;

public:
    Aquatic(std::string, int, double, double);
};

class Lion : public Mammal {
public:
    Lion(std::string, int, double);
    std::string getSpecies() const override;
    double getDailyFood() const override;
    std::string getName() const override;
};

class Elephant : public Mammal {
public:
    Elephant(std::string, int, double);
    std::string getSpecies() const override;
    double getDailyFood() const override;
    std::string getName() const override;
};

class Dolphin : public Mammal, public Aquatic {
public:
    Dolphin(std::string, int, double);
    std::string getSpecies() const override;
    double getDailyFood() const override;
    std::string getName() const override;
};

class SeaTurtle : public Aquatic {
public:
    SeaTurtle(std::string, int, double);
    std::string getSpecies() const override;
    double getDailyFood() const override;
    std::string getName() const override;
};

template<typename T>
class ZooSection {
    std::vector<std::unique_ptr<T>> animals;

public:
    void addAnimal(std::unique_ptr<T> a) {
        if (!a) throw std::runtime_error("null");
        animals.push_back(std::move(a));
    }

    double totalFood() const {
        double sum = 0;
        for (const auto& a : animals)
            sum += a->getDailyFood();
        return sum;
    }

    size_t size() const {
        return animals.size();
    }

    T* getAnimal(size_t i) const {
        return animals[i].get();
    }
};

class ZooKeeper {
    static int totalAnimalsServed;

public:
    void processAnimal(Animal*);
    static int getTotalAnimalsServed();
};

#endif
