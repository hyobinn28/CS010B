#ifndef __WIZARD_H__
#define __WIZARD_H__

#include "Character.h"

class Wizard : public Character {
    public:
        Wizard(const string &name, double health, double attackStrength, int ranking);
        void attack(Character &enemy) override;
    private:
        int ranking;
};

#endif