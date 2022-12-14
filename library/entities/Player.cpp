#include "Player.h"
#include "library/helpers/DieRoller.h"

#include<iostream>
#include <csignal>

void Player::Print() {
    system("cls");
    std::cout << "Name: " << name << std::endl;

    std::cout << "Race: ";
    switch (race) {
        case HumanoidRaceEnum::HUMAN:
            std::cout << "Human" << std::endl;
            break;
        case HumanoidRaceEnum::ELF:
            std::cout << "Paladin" << std::endl;
            break;
        case HumanoidRaceEnum::TIEFLING:
            std::cout << "Tiefling" << std::endl;
            break;
        case HumanoidRaceEnum::ORK:
            std::cout << "Ork" << std::endl;
            break;
        case HumanoidRaceEnum::LIZARDMAN:
            std::cout << "Lizrdman" << std::endl;
            break;
        case HumanoidRaceEnum::KHAJIIT:
            std::cout << "Khajiit" << std::endl;
            break;
        default:
            std::cout << "Uknown character class" << std::endl;
    }

    std::cout << "Class: ";
    switch (job) {
        case JobEnum::WARRIOR:
            std::cout << "Warrior" << std::endl;
            break;
        case JobEnum::PALADIN:
            std::cout << "Paladin" << std::endl;
            break;
        case JobEnum::THEIF:
            std::cout << "Theif" << std::endl;
            break;
        case JobEnum::BARD:
            std::cout << "Bard" << std::endl;
            break;
        case JobEnum::WIZARD:
            std::cout << "Wizard" << std::endl;
            break;
        case JobEnum::SCOUT:
            std::cout << "Scout" << std::endl;
            break;
        default:
            std::cout << "Uknown character class" << std::endl;
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

    std::cout << "INT: " << intl << " (";
    if (modIntl > 0) std::cout << "+" << modIntl << ")" << std::endl;
    else std::cout << modIntl << ")" << std::endl;

    std::cout << "CHR: " << chrm << " (";
    if (modChrm > 0) std::cout << "+" << modChrm << ")" << std::endl;
    else std::cout << modChrm << ")" << std::endl;

    std::cout << "LUK: " << luck << " (";
    if (modLuck > 0) std::cout << "+" << modLuck << ")" << std::endl;
    else std::cout << modLuck << ")\n" << std::endl;
}

void CreateCharacter(Player &thePlayer) {
    DieRoller dice;
    int choice;
    std::cout << "Please enter a name for your character: ";
    std::getline(std::cin, thePlayer.name);

    std::cout << "What race do you wish to play as?" << std::endl;
    std::cout << "Please enter the # of your choice:" << std::endl;
    std::cout << "1) Human" << std::endl;
    std::cout << "2) Elf\t\t\t +INT,\t++AGL,\t--DEF" << std::endl;
    std::cout << "3) Tiefling\t\t++INT,\t +CHR,\t -VIT,\t -LUK" << std::endl;
    std::cout << "4) Ork\t\t\t +DEF,\t +ATK,\t +VIT,\t -CHR,\t -INT" << std::endl;
    std::cout << "5) Lizardman\t +DEF,\t +ATK,\t +AGL,\t--VIT" << std::endl;
    std::cout << "6) Khajiit\t\t +CHR,\t++LUK,\t -DEF,\t -VIT" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1: {
            thePlayer.race = HumanoidRaceEnum::HUMAN;
        }
            break;
        case 2: {
            thePlayer.race = HumanoidRaceEnum::ELF;
            thePlayer.modIntl = dice.Roll1DN(3);
            thePlayer.modAgil = dice.Roll1DN(3) + dice.Roll1DN(3);
            thePlayer.modPDef = -dice.Roll1DN(3) - dice.Roll1DN(3);
        }
            break;
        case 3: {
            thePlayer.race = HumanoidRaceEnum::TIEFLING;
            thePlayer.modIntl = dice.Roll1DN(3) + dice.Roll1DN(3);
            thePlayer.modChrm = dice.Roll1DN(3);
            thePlayer.modVitl = -dice.Roll1DN(3);
            thePlayer.modLuck = -dice.Roll1DN(3);
        }
            break;
        case 4: {
            thePlayer.race = HumanoidRaceEnum::ORK;
            thePlayer.modPDef = dice.Roll1DN(3);
            thePlayer.modPAtk = dice.Roll1DN(3);
            thePlayer.modVitl = dice.Roll1DN(3);
            thePlayer.modChrm = -dice.Roll1DN(3);
            thePlayer.modIntl = -dice.Roll1DN(3);
        }
            break;
        case 5: {
            thePlayer.race = HumanoidRaceEnum::LIZARDMAN;
            thePlayer.modPDef = dice.Roll1DN(3);
            thePlayer.modPAtk = dice.Roll1DN(3);
            thePlayer.modAgil = dice.Roll1DN(3);
            thePlayer.modVitl = -dice.Roll1DN(3) - dice.Roll1DN(3);
        }
            break;
        case 6: {
            thePlayer.race = HumanoidRaceEnum::KHAJIIT;
            thePlayer.modChrm = dice.Roll1DN(3);
            thePlayer.modLuck = dice.Roll1DN(3) + dice.Roll1DN(3);
            thePlayer.modPDef = -dice.Roll1DN(3);
            thePlayer.modVitl = -dice.Roll1DN(3);
        }
            break;
        default: {
            std::cout << "That was an invalid choice! You are now an elf. May the spirits guide you!" << std::endl;
                thePlayer.race = HumanoidRaceEnum::ELF;
                thePlayer.modIntl = dice.Roll1DN(3);
                thePlayer.modAgil = dice.Roll1DN(3) + dice.Roll1DN(3);
                thePlayer.modPDef = -dice.Roll1DN(3) - dice.Roll1DN(3);
        }
    }

    sleep(2);
    system("cls");

    std::cout << "\nWhat class do you wish to play as?" << std::endl;
    std::cout << "Please enter the # of your choice:" << std::endl;
    std::cout << "1) Warrior" << std::endl;
    std::cout << "2) Paladin" << std::endl;
    std::cout << "3) Theif" << std::endl;
    std::cout << "4) Bard" << std::endl;
    std::cout << "5) Wizard" << std::endl;
    std::cout << "6) Scout" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1:
            thePlayer.job = JobEnum::WARRIOR;
            break;
        case 2:
            thePlayer.job = JobEnum::PALADIN;
            break;
        case 3:
            thePlayer.job = JobEnum::THEIF;
            break;
        case 4:
            thePlayer.job = JobEnum::BARD;
            break;
        case 5:
            thePlayer.job = JobEnum::WIZARD;
            break;
        case 6:
            thePlayer.job = JobEnum::SCOUT;
            break;
        default:
            std::cout << "That was an invalid choice! You are now a bard." << std::endl;
            thePlayer.job = JobEnum::BARD;
    }

    sleep(2);
    system("cls");

    std::cout << "\nHow do you wish to set your characteristics?" << std::endl;
    std::cout << "Please enter the # of your choice:" << std::endl;
    std::cout << "1) Roll 6D3" << std::endl;
    std::cout << "2) Roll 3D6" << std::endl;
    std::cout << "3) Roll 4D6 and drop the lowest" << std::endl;
    std::cout << "4) Roll 1D18" << std::endl;

    std::cin >> choice;
    switch (choice) {
        case 1: {
//            TODO: Consider moving assigning values to function
            thePlayer.pDef = dice.Roll6D3();
            thePlayer.mDef = dice.Roll6D3() / 6;
            thePlayer.pAtk = dice.Roll6D3();
            thePlayer.mAtk = dice.Roll6D3() / 6;
            thePlayer.agil = dice.Roll6D3();
            thePlayer.vitl = dice.Roll6D3();
            thePlayer.intl = dice.Roll6D3();
            thePlayer.chrm = dice.Roll6D3();
            thePlayer.luck = dice.Roll6D3() / 2;
        }
            break;
        case 2: {
            thePlayer.pDef = dice.Roll3D6();
            thePlayer.mDef = dice.Roll3D6() / 5;
            thePlayer.pAtk = dice.Roll3D6();
            thePlayer.mAtk = dice.Roll3D6() / 5;
            thePlayer.agil = dice.Roll3D6();
            thePlayer.vitl = dice.Roll3D6();
            thePlayer.intl = dice.Roll3D6();
            thePlayer.chrm = dice.Roll3D6();
            thePlayer.luck = dice.Roll3D6() / 5 * 3;
        }
            break;
        case 3: {
            thePlayer.pDef = dice.Roll4D6DropLowest();
            thePlayer.mDef = dice.Roll4D6DropLowest() / 4;
            thePlayer.pAtk = dice.Roll4D6DropLowest();
            thePlayer.mAtk = dice.Roll4D6DropLowest() / 4;
            thePlayer.agil = dice.Roll4D6DropLowest();
            thePlayer.vitl = dice.Roll4D6DropLowest();
            thePlayer.intl = dice.Roll4D6DropLowest();
            thePlayer.chrm = dice.Roll4D6DropLowest();
            thePlayer.luck = dice.Roll4D6DropLowest() / 2;
        }
            break;
        case 4: {
            thePlayer.pDef = dice.Roll1DN(18);
            thePlayer.mDef = dice.Roll1DN(18) / 3;
            thePlayer.pAtk = dice.Roll1DN(18);
            thePlayer.mAtk = dice.Roll1DN(18) / 3;
            thePlayer.agil = dice.Roll1DN(18);
            thePlayer.vitl = dice.Roll1DN(18);
            thePlayer.intl = dice.Roll1DN(18);
            thePlayer.chrm = dice.Roll1DN(18);
            thePlayer.luck = dice.Roll1DN(18) / 4 * 3;
        }
            break;
        default: {
            std::cout << "That was an invalid choice! The stats are set by rolling 3D6" << std::endl;
            thePlayer.pDef = dice.Roll3D6();
            thePlayer.mDef = dice.Roll3D6() / 5;
            thePlayer.pAtk = dice.Roll3D6();
            thePlayer.mAtk = dice.Roll3D6() / 5;
            thePlayer.agil = dice.Roll3D6();
            thePlayer.vitl = dice.Roll3D6();
            thePlayer.intl = dice.Roll3D6();
            thePlayer.chrm = dice.Roll3D6();
            thePlayer.luck = dice.Roll3D6() / 5 * 3;
        }
    }

    sleep(2);
    system("cls");
}