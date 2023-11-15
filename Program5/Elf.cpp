#include "Elf.h"
#include <iostream>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
    : Character(ELF, name, health, attackStrength), family(family) {}

/*Stores the elf's family name as a string.
The elf does not attack an elf from its own family.
The damage done by the elf is the percentage of the elf's health remaining
(health / MAX_HEALTH) multiplied by the elf's attack strength.*/
void Elf::attack(Character &enemy) {
    if(enemy.getType() == ELF) {
        Elf *oppSide = dynamic_cast<Elf *>(&enemy);

        if(oppSide && oppSide->family == family) {
            cout << "Elf " << name << " does not attack Elf " << oppSide->getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            
            return;
        }
    }

    double damage = (health / MAX_HEALTH) * attackStrength;
    enemy.damage(damage);

    cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
    cout << enemy.getName() << " takes " << damage << " damage." << endl;
}