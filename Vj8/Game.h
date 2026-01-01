#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>

class Enemy;
class Player;

class GameCharacter {
protected:
    int health;
    int max_health;
    std::string name;

public:
    GameCharacter(std::string, int);
    virtual ~GameCharacter();

    virtual void displayStatus() const = 0;
    virtual void specialAbility() = 0;

    void takeDamage(int);
    bool isAlive() const;
    int getHealth() const;
    std::string getName() const;
};

class Player : public GameCharacter {
protected:
    int score;

public:
    Player(std::string, int);
    virtual void attackEnemy(Enemy*) = 0;
    void addScore(int);
};

class Enemy : public GameCharacter {
protected:
    int difficulty;

public:
    Enemy(std::string, int, int);
    virtual void attackPlayer(Player*) = 0;
};

class Warrior : public Player {
    bool shield;

public:
    Warrior(std::string);
    void attackEnemy(Enemy*) override;
    void specialAbility() override;
    void displayStatus() const override;
};

class Mage : public Player {
    int mana;

public:
    Mage(std::string);
    void attackEnemy(Enemy*) override;
    void specialAbility() override;
    void displayStatus() const override;
};

class Gnome : public Enemy {
public:
    Gnome(std::string);
    void attackPlayer(Player*) override;
    void specialAbility() override;
    void displayStatus() const override;
};

class Boss : public Enemy {
public:
    Boss(std::string);
    void attackPlayer(Player*) override;
    void specialAbility() override;
    void displayStatus() const override;
};

#endif
