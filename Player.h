#pragma once
#include <string>

enum class JobEnum {WARRIOR, PALADIN, THEIF, BARD, WIZARD, SCOUT};
enum class RaceEnum {HUMAN, ELF, TIEFLING, ORK, LIZARDMAN, KHAJIIT};

class Player {
public:
	std::string name;
	int pDef;			// physical defence
	int mDef;			// magical defence
	int pAtk;			// physical attack
	int mAtk;			// magical attack
	int agil;			// agility
	int vitl;			// vitality
	int intl;			// intelligence
	int chrm;			// charm
	int luck;			// luck

	RaceEnum race;		// modificators for characteristics
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

void CreateCharacter(Player& thePlayer); // standalone function that fills out a player's data
