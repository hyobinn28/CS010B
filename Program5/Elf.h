#ifndef __ELF_H__
#define __ELF_H__

#include "Character.h"

class Elf : public Character {
    public:
        Elf(const string &name, double health, double attackStrength, const string &family);
        void attack(Character &enemy) override;
    private:
        string family;
};

#endif