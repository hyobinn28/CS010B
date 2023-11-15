#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Character.h"

class Warrior : public Character {
    public:
        Warrior(const string &name, double health, double attackStrength, const string &team);
        void attack(Character &enemy) override;
    private:
        string team;
};

#endif