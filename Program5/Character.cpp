#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength)
    : type(type), name(name), health(health), attackStrength(attackStrength) {}

HeroType Character::getType() const {
    return type;
}

const string &Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::damage(double d) {
    health -= d;

    if(health < 0) {
        health = 0;
    }
}

bool Character::isAlive() const {
    return (static_cast<int>(health) > 0);
}
