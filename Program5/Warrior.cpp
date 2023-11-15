#include "Warrior.h" 
#include <iostream>

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &team) 
    : Character(WARRIOR, name, health, attackStrength), team(team) {}

/*Stores the warrior's allegiance as a string.
The warrior does not attack warriors that have the same allegiance.
The damage done by the warrior is the percentage of the warrior's health remaining
(health / MAX_HEALTH) multiplied by the warrior's attack strength.*/
void Warrior::attack(Character &enemy) {
    if(enemy.getType() == WARRIOR) {
        Warrior *oppSide = dynamic_cast<Warrior *>(&enemy);

        if(oppSide && oppSide->team == team) {
            cout << "Warrior " << name << " does not attack Warrior " << oppSide->getName() << "." << endl;
            cout << "They share an allegiance with " << team << "." << endl;

            return;
        }
    }

    double damage = (health / MAX_HEALTH) * attackStrength;         
    enemy.damage(damage);

    cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
    cout << enemy.getName() << " takes " << damage << " damage." << endl;
}