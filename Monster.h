#pragma once
#include <string>

enum class ModificatorEnum { WEAK, TOUGH, ORDINARY, HUNGRY, WOUNDED, TRICKY, BLIND, FAST, SLOW, HALFDEAD };
enum class RaceEnum { UNDEAD, SYREN, BANSHEE, GOBLIN, IMP, WYVERN };
enum class TypeEnum { UNDEAD, MONSTER, SPIRIT };


class Monster {
public:
	RaceEnum race;
	TypeEnum type;
	int pDef;			// physical defence/a measurement of damage mitigation
	int mDef;			// magical defence
	int pAtk;			// physical attack
	int mAtk;			// magical attack
	int agil;			// agility/evasion/chances to not get hit/speed
	int vitl;			// vitality
	int luck;			// luck

	ModificatorEnum modificator; // modificators for creature/characteristics
	int modPDef = 0;
	int modMDef = 0;
	int modPAtk = 0;
	int modMAtk = 0;
	int modAgil = 0;
	int modVitl = 0;
	int modLuck = 0;

	void Print(); //displays the monster information
};

void GenerateMonster(Monster& theMonster); //assigns theMonster random stats