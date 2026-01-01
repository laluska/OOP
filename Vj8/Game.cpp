#include "Game.h"

GameCharacter::GameCharacter(std::string n, int h)
    : name(n), health(h), max_health(h) {}

GameCharacter::~GameCharacter() {}

void GameCharacter::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

bool GameCharacter::isAlive() const {
    return health > 0;
}

int GameCharacter::getHealth() const {
    return health;
}

std::string GameCharacter::getName() const {
    return name;
}

Player::Player(std::string n, int h)
    : GameCharacter(n, h), score(0) {}

void Player::addScore(int s) {
    score += s;
}

Enemy::Enemy(std::string n, int h, int d)
    : GameCharacter(n, h), difficulty(d) {}

Warrior::Warrior(std::string n)
    : Player(n, 120), shield(false) {}

void Warrior::attackEnemy(Enemy* e) {
    if (!e || !e->isAlive()) return;
    e->takeDamage(20);
    if (!e->isAlive()) addScore(10);
}

void Warrior::specialAbility() {
    shield = true;
}

void Warrior::displayStatus() const {
    std::cout << name << " " << health << std::endl;
}

Mage::Mage(std::string n)
    : Player(n, 80), mana(100) {}

void Mage::attackEnemy(Enemy* e) {
    if (!e || !e->isAlive()) return;
    if (mana >= 20) {
        e->takeDamage(40);
        mana -= 20;
    } else {
        e->takeDamage(20);
    }
    if (!e->isAlive()) addScore(10);
}

void Mage::specialAbility() {
    if (health > 50)
        std::cout << name << " teleports" << std::endl;
}

void Mage::displayStatus() const {
    std::cout << name << " " << health << " " << mana << std::endl;
}

Gnome::Gnome(std::string n)
    : Enemy(n, 90, 3) {}

void Gnome::attackPlayer(Player* p) {
    if (!p || !p->isAlive()) return;
    p->takeDamage(5 * difficulty);
}

void Gnome::specialAbility() {
    if (health > 20)
        std::cout << name << " blows trumpet" << std::endl;
}

void Gnome::displayStatus() const {
    std::cout << name << " " << health << std::endl;
}

Boss::Boss(std::string n)
    : Enemy(n, 300, 8) {}

void Boss::attackPlayer(Player* p) {
    if (!p || !p->isAlive()) return;
    p->takeDamage(10 * difficulty);
}

void Boss::specialAbility() {
    health += 50;
    if (health > 300) health = 300;
}

void Boss::displayStatus() const {
    std::cout << name << " " << health << std::endl;
}

int main() {
    std::vector<GameCharacter*> v;

    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Gnome* gnomeo = new Gnome("Gnomeo");
    Gnome* sneaky = new Gnome("Sneaky");
    Boss* dragon = new Boss("Dragon");

    v = {conan, merlin, gnomeo, sneaky, dragon};

    conan->attackEnemy(gnomeo);
    conan->displayStatus(); gnomeo->displayStatus();

    merlin->attackEnemy(sneaky);
    merlin->displayStatus(); sneaky->displayStatus();

    gnomeo->attackPlayer(conan);
    gnomeo->displayStatus(); conan->displayStatus();

    merlin->attackEnemy(gnomeo);
    dragon->attackPlayer(merlin);
    merlin->attackEnemy(gnomeo);
    conan->attackEnemy(dragon);
    merlin->attackEnemy(dragon);

    for (auto c : v) c->specialAbility();

    GameCharacter* max = nullptr;
    for (auto c : v) {
        if (c->isAlive()) {
            c->displayStatus();
            if (!max || c->getHealth() > max->getHealth())
                max = c;
        }
    }

    if (max)
        std::cout << max->getName() << std::endl;

    for (auto c : v) delete c;
}
