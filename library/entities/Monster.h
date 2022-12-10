#ifndef FIGHTSIM_MONSTER_H
#define FIGHTSIM_MONSTER_H

#include <string>
#include "library/helpers/DieRoller.h"

enum class ModificatorEnum {
    WEAK, TOUGH, ORDINARY, HUNGRY, WOUNDED, TRICKY, BLIND, FAST, SLOW, HALFDEAD,
};
enum class MonsterRaceEnum {
    UNDEAD, SIREN, BANSHEE, GOBLIN, IMP, WYVERN,
};
enum class TypeEnum {
    UNDEAD, MONSTER, SPIRIT,
};

class Monster {
public:
    MonsterRaceEnum race;
    TypeEnum type;
    int pDef;            // physical defence/a measurement of damage mitigation
    int mDef;            // magical defence
    int pAtk;            // physical attack
    int mAtk;            // magical attack
    int agil;            // agility/evasion/chances to not get hit/speed
    int vitl;            // vitality
    int luck;            // luck

    ModificatorEnum mod; // modifications for creature/characteristics
    int modPDef = 0;
    int modMDef = 0;
    int modPAtk = 0;
    int modMAtk = 0;
    int modAgil = 0;
    int modVitl = 0;
    int modLuck = 0;

    void Print(); //displays the monster information
};

void GenerateMonsterManually(Monster &theMonster); //assigns theMonster random stats while you get to choose the output
void GenerateMonsterRandom(Monster &theMonster); //assigns theMonster random type, re-rolls its difficulty and stats

std::string RaceToString(MonsterRaceEnum race);
std::string ModToString(ModificatorEnum mod);

#endif //FIGHTSIM_MONSTER_H