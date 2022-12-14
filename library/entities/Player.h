#ifndef FIGHTSIM_PLAYER_H
#define FIGHTSIM_PLAYER_H

//TODO: Ask about #pragma once

#include <string>
#include "library/helpers/DieRoller.h"

enum class JobEnum {
    WARRIOR, PALADIN, THEIF, BARD, WIZARD, SCOUT
};
enum class HumanoidRaceEnum {
    HUMAN, ELF, TIEFLING, ORK, LIZARDMAN, KHAJIIT,
};

//TODO:  Decide on perception
class Player {
public:
    std::string name;
    int pDef;            // physical defence
    int mDef;            // magical defence
    int pAtk;            // physical attack
    int mAtk;            // magical attack
    int agil;            // agility
    int vitl;            // vitality
    int intl;            // intelligence
    int chrm;            // charm
    int luck;            // luck

    HumanoidRaceEnum race;        // modifications for characteristics
    int modPDef = 0;
    int modMDef = 0;
    int modPAtk = 0;
    int modMAtk = 0;
    int modAgil = 0;
    int modVitl = 0;
    int modIntl = 0;
    int modChrm = 0;
    int modLuck = 0;

    JobEnum job;

    void Print(); // method to display the character "sheet", or data
};

void CreateCharacter(Player &thePlayer); // standalone function that fills out a player's data

#endif FIGHTSIM_PLAYER_H