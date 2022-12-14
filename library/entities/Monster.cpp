#include "Monster.h"

#include <iostream>
#include <string>

void Monster::Print() {
    system("cls");
    std::cout << "Modificator: ";
    switch (mod) {
        case ModificatorEnum::WEAK:
            std::cout << "Weak" << std::endl;
            break;
        case ModificatorEnum::TOUGH:
            std::cout << "Tough" << std::endl;
            break;
        case ModificatorEnum::ORDINARY:
            std::cout << "Ordinary" << std::endl;
            break;
        case ModificatorEnum::HUNGRY:
            std::cout << "Hungry" << std::endl;
            break;
        case ModificatorEnum::WOUNDED:
            std::cout << "Wounded" << std::endl;
            break;
        case ModificatorEnum::TRICKY:
            std::cout << "Tricky" << std::endl;
            break;
        case ModificatorEnum::BLIND:
            std::cout << "Blinded" << std::endl;
            break;
        case ModificatorEnum::FAST:
            std::cout << "Fast" << std::endl;
            break;
        case ModificatorEnum::SLOW:
            std::cout << "Slow" << std::endl;
            break;
        case ModificatorEnum::HALFDEAD:
            std::cout << "Halfdead" << std::endl;
            break;
        default:
            std::cout << " -" << std::endl;
    }


    std::cout << "Race: ";
    switch (race) {
        case MonsterRaceEnum::BANSHEE:
            std::cout << "Banshee" << std::endl;
            break;
        case MonsterRaceEnum::GOBLIN:
            std::cout << "Goblin" << std::endl;
            break;
        case MonsterRaceEnum::IMP:
            std::cout << "Imp" << std::endl;
            break;
        case MonsterRaceEnum::SIREN:
            std::cout << "Siren" << std::endl;
            break;
        case MonsterRaceEnum::UNDEAD:
            std::cout << "Undead" << std::endl;
            break;
        case MonsterRaceEnum::WYVERN:
            std::cout << "Wyvern" << std::endl;
            break;
        default:
            std::cout << "Uknown character race" << std::endl;
    }

    std::cout << "Type: ";
    switch (type) {
        case TypeEnum::UNDEAD:
            std::cout << "Undead" << std::endl;
            break;
        case TypeEnum::MONSTER:
            std::cout << "Monster" << std::endl;
            break;
        case TypeEnum::SPIRIT:
            std::cout << "Spirit" << std::endl;
            break;
        default:
            std::cout << "Uknown type" << std::endl;
    }

    std::cout << "\nPHYS DEF: " << pDef << " (";
    if (modPDef > 0) std::cout << "+" << modPDef << ")" << std::endl;
    else std::cout << modPDef << ")" << std::endl;

    std::cout << "MAG DEF: " << mDef << " (";
    if (modMDef > 0) std::cout << "+" << modMDef << ")" << std::endl;
    else std::cout << modMDef << ")" << std::endl;

    std::cout << "PHYS ATK: " << pAtk << " (";
    if (modPAtk > 0) std::cout << "+" << modPAtk << ")" << std::endl;
    else std::cout << modPAtk << ")" << std::endl;

    std::cout << "MAG ATK: " << pAtk << " (";
    if (modMAtk > 0) std::cout << "+" << modMAtk << ")" << std::endl;
    else std::cout << modMAtk << ")" << std::endl;;

    std::cout << "AGL: " << agil << " (";
    if (modAgil > 0) std::cout << "+" << modAgil << ")" << std::endl;
    else std::cout << modAgil << ")" << std::endl;

    std::cout << "VIT: " << vitl << " (";
    if (modVitl > 0) std::cout << "+" << modVitl << ")" << std::endl;
    else std::cout << modVitl << ")" << std::endl;

    std::cout << "LUK: " << luck << " (";
    if (modLuck > 0) std::cout << "+" << modLuck << ")" << std::endl;
    else std::cout << modLuck << ")\n" << std::endl;

}

void GenerateMonsterRandom(Monster &theMonster) {
    DieRoller dice;
    int choice = dice.Roll1DN(6);

    switch (choice) {
        case 1: {
            theMonster.race = MonsterRaceEnum::BANSHEE;
            theMonster.type = TypeEnum::SPIRIT;
            theMonster.pDef = 0;
            theMonster.mDef = 8;
            theMonster.pAtk = 1;
            theMonster.mAtk = 7;
            theMonster.agil = 8;
            theMonster.vitl = 8;
            theMonster.luck = 5;
        }
            break;
        case 2: {
            theMonster.race = MonsterRaceEnum::GOBLIN;
            theMonster.type = TypeEnum::MONSTER;
            theMonster.pDef = 3;
            theMonster.mDef = 1;
            theMonster.pAtk = 4;
            theMonster.mAtk = 0;
            theMonster.agil = 12;
            theMonster.vitl = 5;
            theMonster.luck = 5;
        }
            break;
        case 3: {
            theMonster.race = MonsterRaceEnum::IMP;
            theMonster.type = TypeEnum::SPIRIT;
            theMonster.pDef = 3;
            theMonster.mDef = 10;
            theMonster.pAtk = 1;
            theMonster.mAtk = 9;
            theMonster.agil = 10;
            theMonster.vitl = 5;
            theMonster.luck = 5;
        }
            break;
        case 4: {
            theMonster.race = MonsterRaceEnum::SIREN;
            theMonster.type = TypeEnum::MONSTER;
            theMonster.pDef = 8;
            theMonster.mDef = 2;
            theMonster.pAtk = 2;
            theMonster.mAtk = 7;
            theMonster.agil = 8;
            theMonster.vitl = 9;
            theMonster.luck = 4;
        }
            break;
        case 5: {
            theMonster.race = MonsterRaceEnum::UNDEAD;
            theMonster.type = TypeEnum::UNDEAD;
            theMonster.pDef = 10;
            theMonster.mDef = 0;
            theMonster.pAtk = 5;
            theMonster.mAtk = 0;
            theMonster.agil = 5;
            theMonster.vitl = 12;
            theMonster.luck = 0;
        }
            break;
        case 6: {
            theMonster.race = MonsterRaceEnum::WYVERN;
            theMonster.type = TypeEnum::MONSTER;
            theMonster.pDef = 12;
            theMonster.mDef = 3;
            theMonster.pAtk = 10;
            theMonster.mAtk = 0;
            theMonster.agil = 9;
            theMonster.vitl = 11;
            theMonster.luck = 6;
        }
            break;
        default:
            std::cout << "Invalid input at type choice." << std::endl;
    }

    choice = dice.Roll1DN(3);
    switch (choice) {
        case 1: {
            theMonster.pDef += dice.Roll1DN(3);
            theMonster.mDef += dice.Roll1DN(3);
            theMonster.pAtk += dice.Roll1DN(3);
            theMonster.mAtk += dice.Roll1DN(3);;
            theMonster.agil += dice.Roll1DN(3);
            theMonster.vitl += dice.Roll1DN(3);
        }
            break;
        case 2: {
            theMonster.pDef += dice.Roll1DN(4);
            theMonster.mDef += dice.Roll1DN(4);
            theMonster.pAtk += dice.Roll1DN(4);
            theMonster.mAtk += dice.Roll1DN(4);
            theMonster.agil += dice.Roll1DN(4);
            theMonster.vitl += dice.Roll1DN(4);
        }
            break;
        case 3: {
            theMonster.pDef += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.mDef += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.pAtk += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.mAtk += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.agil += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.vitl += dice.Roll1DN(3) - dice.Roll1DN(3);
        }
            break;
        default: {
            std::cout << "Invalid input at difficulty choice." << std::endl;
        }
    }

    choice = dice.Roll1DN(10);

    switch (choice) {
        case 1: {
            theMonster.mod = ModificatorEnum::ORDINARY;
        }
            break;
        case 2: {
            theMonster.mod = ModificatorEnum::WEAK;
            theMonster.modAgil = -dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(3);
            theMonster.modPAtk = -dice.Roll1DN(3);
        }
            break;
        case 3: {
            theMonster.mod = ModificatorEnum::TOUGH;
            theMonster.modPDef = dice.Roll1DN(3);
            theMonster.modVitl = dice.Roll1DN(3);
            theMonster.modAgil = -dice.Roll1DN(3);
        }
            break;
        case 4: {
            theMonster.mod = ModificatorEnum::HUNGRY;
            theMonster.modPAtk = dice.Roll1DN(3);
            theMonster.modAgil = dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(2);
            theMonster.modVitl = -dice.Roll1DN(3);
        }
            break;
        case 5: {
            theMonster.mod = ModificatorEnum::WOUNDED;
            theMonster.modPDef = -dice.Roll1DN(3);
            theMonster.modPAtk = -dice.Roll1DN(2);
            theMonster.modAgil = -dice.Roll1DN(3);
            theMonster.modVitl = -theMonster.vitl / 4;
        }
            break;
        case 6: {
            theMonster.mod = ModificatorEnum::TRICKY;
            theMonster.modLuck = dice.Roll1DN(3);
            theMonster.modAgil = dice.Roll1DN(4);
            theMonster.modVitl = -dice.Roll1DN(2);
        }
            break;
        case 7: {
            theMonster.mod = ModificatorEnum::BLIND;
            theMonster.modLuck = dice.Roll1DN(2);
            theMonster.modPDef = -theMonster.pDef / 2;
            theMonster.modMDef = -theMonster.mDef / 2;
            theMonster.modVitl = -theMonster.mDef / 4;
        }
            break;
        case 8: {
            theMonster.mod = ModificatorEnum::FAST;
            theMonster.modLuck = dice.Roll1DN(3);
            theMonster.modAgil = dice.Roll1DN(8) - dice.Roll1DN(4);
        }
            break;
        case 9: {
            theMonster.mod = ModificatorEnum::SLOW;
            theMonster.modPDef = theMonster.pDef / 4;
            theMonster.modLuck = -dice.Roll1DN(2);
            theMonster.modAgil = -dice.Roll1DN(4);
        }
            break;
        case 10: {
            theMonster.mod = ModificatorEnum::HALFDEAD;
            theMonster.modLuck = dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(4);
            theMonster.modAgil = -dice.Roll1DN(4);
            theMonster.modVitl = -theMonster.vitl / 2;
        }
            break;
        default: {
            std::cout << "That was an invalid choice! You are now a khajiit. May the spirits guide you!" << std::endl;
            theMonster.mod = ModificatorEnum::BLIND;
            theMonster.modMDef = dice.Roll1DN(3);
            theMonster.modLuck = dice.Roll1DN(3) + dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(3);
            theMonster.modVitl = -dice.Roll1DN(3);
        }
    }
}

void GenerateMonsterManually(Monster &theMonster) {
    DieRoller dice;

    int choice;
    std::string input;
    system("cls");
    std::cout << "What creature do thee wish to summon?" << std::endl;
    std::cout << "Please enter the # of your choice:" << std::endl;
    std::cout << "1) Banshee" << std::endl;
    std::cout << "2) Goblin" << std::endl;
    std::cout << "3) Imp" << std::endl;
    std::cout << "4) Syren" << std::endl;
    std::cout << "5) Undead" << std::endl;
    std::cout << "6) Wyvern" << std::endl;

    do {
        std::cin >> choice;
        switch (choice) {
            case 1: {
                theMonster.race = MonsterRaceEnum::BANSHEE;
                theMonster.type = TypeEnum::SPIRIT;
                theMonster.pDef = 0;
                theMonster.mDef = 8;
                theMonster.pAtk = 1;
                theMonster.mAtk = 7;
                theMonster.agil = 8;
                theMonster.vitl = 8;
                theMonster.luck = 5;
            }
                break;
            case 2: {
                theMonster.race = MonsterRaceEnum::GOBLIN;
                theMonster.type = TypeEnum::MONSTER;
                theMonster.pDef = 3;
                theMonster.mDef = 1;
                theMonster.pAtk = 4;
                theMonster.mAtk = 0;
                theMonster.agil = 12;
                theMonster.vitl = 5;
                theMonster.luck = 5;
            }
                break;
            case 3: {
                theMonster.race = MonsterRaceEnum::IMP;
                theMonster.type = TypeEnum::SPIRIT;
                theMonster.pDef = 3;
                theMonster.mDef = 10;
                theMonster.pAtk = 1;
                theMonster.mAtk = 9;
                theMonster.agil = 10;
                theMonster.vitl = 5;
                theMonster.luck = 5;
            }
                break;
            case 4: {
                theMonster.race = MonsterRaceEnum::SIREN;
                theMonster.type = TypeEnum::MONSTER;
                theMonster.pDef = 8;
                theMonster.mDef = 2;
                theMonster.pAtk = 2;
                theMonster.mAtk = 7;
                theMonster.agil = 8;
                theMonster.vitl = 9;
                theMonster.luck = 4;
            }
                break;
            case 5: {
                theMonster.race = MonsterRaceEnum::UNDEAD;
                theMonster.type = TypeEnum::UNDEAD;
                theMonster.pDef = 10;
                theMonster.mDef = 0;
                theMonster.pAtk = 5;
                theMonster.mAtk = 0;
                theMonster.agil = 5;
                theMonster.vitl = 12;
                theMonster.luck = 0;
            }
                break;
            case 6: {
                theMonster.race = MonsterRaceEnum::WYVERN;
                theMonster.type = TypeEnum::MONSTER;
                theMonster.pDef = 12;
                theMonster.mDef = 3;
                theMonster.pAtk = 10;
                theMonster.mAtk = 0;
                theMonster.agil = 9;
                theMonster.vitl = 11;
                theMonster.luck = 6;
            }
                break;
            default:
                std::cout << "That was an invalid choice! Repeat the input." << std::endl;
        }
    } while ((choice < 1) || (choice > 6));

    std::cout << "\nDo you wish to enhance your creature?" << std::endl;
    std::cout << "Please enter the # of your choice:" << std::endl;
    std::cout << "1) Make it a little stronger\t\t\t- add 1D3" << std::endl;
    std::cout << "2) I want a challange\t\t\t\t- add 1D4" << std::endl;
    std::cout << "3) Make it... different, but normal\t\t- add 1D3 and substract 1D3" << std::endl;
    std::cout << "4) Leave it as it is" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1: {
            theMonster.pDef += dice.Roll1DN(3);
            theMonster.mDef += dice.Roll1DN(3);
            theMonster.pAtk += dice.Roll1DN(3);
            theMonster.mAtk += dice.Roll1DN(3);;
            theMonster.agil += dice.Roll1DN(3);
            theMonster.vitl += dice.Roll1DN(3);
        }
            break;
        case 2: {
            theMonster.pDef += dice.Roll1DN(4);
            theMonster.mDef += dice.Roll1DN(4);
            theMonster.pAtk += dice.Roll1DN(4);
            theMonster.mAtk += dice.Roll1DN(4);
            theMonster.agil += dice.Roll1DN(4);
            theMonster.vitl += dice.Roll1DN(4);
        }
            break;
        case 3: {
            theMonster.pDef += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.mDef += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.pAtk += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.mAtk += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.agil += dice.Roll1DN(3) - dice.Roll1DN(3);
            theMonster.vitl += dice.Roll1DN(3) - dice.Roll1DN(3);
        }
            break;
        default: {
            std::cout << "That was an invalid choice! The stats are left \"as is\"" << std::endl;
        }
    }

    std::getline(std::cin, input); // either of those lines can prevent the program from accepting the
//	std::cin.ignore(INT_MAX, '\n');	 // previous input as a new one and thus "skipping" over the next 'getLine'

    std::cout << "\nDo you wish to set modification manually (Y/N)?" << std::endl;
    std::getline(std::cin, input);
    if ((input == "Y") || (input == "y") || (input == "Yes") || (input == "yes")) {
        std::cout << "\nPlease enter the # of your choice:" << std::endl;
        std::cout << "1) Ordinary" << std::endl;
        std::cout << "2) Weak" << std::endl;
        std::cout << "3) Tough" << std::endl;
        std::cout << "4) Hungry" << std::endl;
        std::cout << "5) Wounded" << std::endl;
        std::cout << "6) Tricky" << std::endl;
        std::cout << "7) Blind" << std::endl;
        std::cout << "8) Fast" << std::endl;
        std::cout << "9) Slow" << std::endl;
        std::cout << "10) Halfdead" << std::endl;
        std::cin >> choice;
    } else {
        choice = dice.Roll1DN(10);
    }
    switch (choice) {
        case 1: {
            theMonster.mod = ModificatorEnum::ORDINARY;
        }
            break;
        case 2: {
            theMonster.mod = ModificatorEnum::WEAK;
            theMonster.modAgil = -dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(3);
            theMonster.modPAtk = -dice.Roll1DN(3);
        }
            break;
        case 3: {
            theMonster.mod = ModificatorEnum::TOUGH;
            theMonster.modPDef = dice.Roll1DN(3);
            theMonster.modVitl = dice.Roll1DN(3);
            theMonster.modAgil = -dice.Roll1DN(3);
        }
            break;
        case 4: {
            theMonster.mod = ModificatorEnum::HUNGRY;
            theMonster.modPAtk = dice.Roll1DN(3);
            theMonster.modAgil = dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(2);
            theMonster.modVitl = -dice.Roll1DN(3);
        }
            break;
        case 5: {
            theMonster.mod = ModificatorEnum::WOUNDED;
            theMonster.modPDef = -dice.Roll1DN(3);
            theMonster.modPAtk = -dice.Roll1DN(2);
            theMonster.modAgil = -dice.Roll1DN(3);
            theMonster.modVitl = -theMonster.vitl / 4;
        }
            break;
        case 6: {
            theMonster.mod = ModificatorEnum::TRICKY;
            theMonster.modLuck = dice.Roll1DN(3);
            theMonster.modAgil = dice.Roll1DN(4);
            theMonster.modVitl = -dice.Roll1DN(2);
        }
            break;
        case 7: {
            theMonster.mod = ModificatorEnum::BLIND;
            theMonster.modLuck = dice.Roll1DN(2);
            theMonster.modPDef = -theMonster.pDef / 2;
            theMonster.modMDef = -theMonster.mDef / 2;
            theMonster.modVitl = -theMonster.mDef / 4;
        }
            break;
        case 8: {
            theMonster.mod = ModificatorEnum::FAST;
            theMonster.modLuck = dice.Roll1DN(3);
            theMonster.modAgil = dice.Roll1DN(8) - dice.Roll1DN(4);
        }
            break;
        case 9: {
            theMonster.mod = ModificatorEnum::SLOW;
            theMonster.modPDef = theMonster.pDef / 4;
            theMonster.modLuck = -dice.Roll1DN(2);
            theMonster.modAgil = -dice.Roll1DN(4);
        }
            break;
        case 10: {
            theMonster.mod = ModificatorEnum::HALFDEAD;
            theMonster.modLuck = dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(4);
            theMonster.modAgil = -dice.Roll1DN(4);
            theMonster.modVitl = -theMonster.vitl / 2;
        }
            break;
        default: {
            std::cout << "That was an invalid choice! You are now a khajiit. May the spirits guide you!" << std::endl;
            theMonster.mod = ModificatorEnum::BLIND;
            theMonster.modMDef = dice.Roll1DN(3);
            theMonster.modLuck = dice.Roll1DN(3) + dice.Roll1DN(3);
            theMonster.modPDef = -dice.Roll1DN(3);
            theMonster.modVitl = -dice.Roll1DN(3);
        }
    }
}

std::string RaceToString(MonsterRaceEnum race) {
    switch (race) {
        case MonsterRaceEnum::UNDEAD: {
            return "Undead";
            break;
        }
        case MonsterRaceEnum::SIREN: {
            return "Siren";
            break;
        }
        case MonsterRaceEnum::BANSHEE: {
            return "Banshee";
            break;
        }
        case MonsterRaceEnum::GOBLIN: {
            return "Goblin";
            break;
        }
        case MonsterRaceEnum::IMP: {
            return "Imp";
            break;
        }
        case MonsterRaceEnum::WYVERN: {
            return "Wyvern";
            break;
        }
        default: {
            throw std::invalid_argument("Unknown Monster");
            break;
        }
    }
}

std::string ModToString(ModificatorEnum mod) {
    switch (mod) {
        case ModificatorEnum::BLIND: {
            return "Undead";
            break;
        }
        case ModificatorEnum::FAST: {
            return "Fast";
            break;
        }
        case ModificatorEnum::HALFDEAD: {
            return "Half-dead";
            break;
        }
        case ModificatorEnum::HUNGRY: {
            return "Hungry";
            break;
        }
        case ModificatorEnum::ORDINARY: {
            return "Ordinary";
            break;
        }
        case ModificatorEnum::SLOW: {
            return "Slow";
            break;
        }
        case ModificatorEnum::TOUGH: {
            return "Tough";
            break;
        }
        case ModificatorEnum::TRICKY: {
            return "Tricky";
            break;
        }
        case ModificatorEnum::WEAK: {
            return "Weak";
            break;
        }
        case ModificatorEnum::WOUNDED: {
            return "Wounded";
            break;
        }
        default: {
            throw std::invalid_argument("Unknown Modification");
            break;
        }
    }
}