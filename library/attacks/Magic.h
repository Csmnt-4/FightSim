#ifndef FIGHTSIM_MAGIC_H
#define FIGHTSIM_MAGIC_H

//TODO: Ask about #pragma once

#include <string>

//TODO: Change to hashmap
enum class SpellElementEnum {
    WIND = 0,
    FIRE = 1,
    WATER = 1,
    EARTH = 1,
    ICE = 2,
    METAL = 3,
    ELECTRIC = 3,
    LIGHTNING = 3,
    STATIC = 3,
    MAGIC = 5,
    SPIRIT = 5,
    LIGHT = 5,
    SHADOW = 5,
    BLOOD = 6,
    VAMPIRIC = 6,
    NECROTIC = 8,
    DEAD = 8,
    ACID = 8,
    POISONOUS = 8,
    GAS = 8,
    MENTAL = 8,
    ILLUSORY = 9,
    HARMFUL = 9,
    HOLY = 11,
    DARK = 11,
    PURE = 12,
    CHAOS = 12,
    RADIOACTIVE = 15,
    ATOMIC = 15,
    STAR = 15,
    FORBIDDEN = 17,
};

enum class SpellTypeEnum {
    CLOUD = 2,
    RAY = 1,
    STRIKE = 1,
    BURST = 1,
    BLADE = 1,
    BOLT = 1,
    ORB = 2,
    SPHERE = 2,
    SPRAY = 1,
    TOUCH = 1,
    BLOW = 1,
    HAND = 2,
    ARM = 1,
    GRASP = 1,
    STORM = 1,
    WALL = 3,
    PEIRCE = 1,
    KNIFE = 1,
    BOW = 1,
    THORN = 1,
    WHIP = 1,
    DEFENCE = 3,
    ATTACK = 1,
    SCREAM = 1,
    FORCE = 2,
    BEAM = 1,
    SLASH = 1,
    BARRIER = 3,
};

class Spell {
public:
    SpellElementEnum elem;
    SpellTypeEnum type;

    int powr;
    int lett;
    int vowl;
    int cons;
    int chan;

    int baseChan;
    int baseType;
    int baseElem;

    void Print(); //displays the monster information
};

//TODO: Implement basic spell-defining function
int FindSpellType(std::string &spell);

int FindSpellElem(std::string &spell);

int CountLetters(std::string &spell);

int CountVowels(std::string &spell);

int CountConsonants(std::string &spell);

#endif //FIGHTSIM_MAGIC_H

