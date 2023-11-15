#include "Wizard.h"
#include <iostream>

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int ranking)
    : Character(WIZARD, name, health, attackStrength), ranking(ranking) {}


/*Stores the wizard's rank as an int.
When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied
by the ratio of the attacking wizard's rank over the defending wizard's rank.
The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration. */
void Wizard::attack(Character &enemy) {
    if(enemy.getType() == WIZARD) {
        Wizard *oppSide = dynamic_cast<Wizard *>(&enemy);

        if(oppSide) {
            double damage;

            damage = attackStrength * (static_cast<double>(ranking) / oppSide->ranking);
            enemy.damage(damage);

            cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
            cout << enemy.getName() << " takes " << damage << " damage." << endl;

            return;
        }
    }

    double damage = attackStrength;
    enemy.damage(damage);

    cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
    cout << enemy.getName() << " takes " << damage <<  " damage." << endl;
}