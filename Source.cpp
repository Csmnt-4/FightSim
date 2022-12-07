#include <iostream>
#include "Monster.h"
#include "Player.h"

bool Fight(Player, Monster) {
    return true;
}

void main() {
    Player playerOne;

    CreateCharacter(playerOne);

    bool done = false;

    while (!done) {
        Monster creatureThe;
        GenerateMonsterManually(creatureThe);

        if (Fight(playerOne, creatureThe)) {
            std::cout << "The player " << playerOne.name << " won!" << std::endl;
            std::cout << "They have " << playerOne.vitl * 10 << " HP left." << std::endl;
        }
        else {
            std::cout << "Monster " << ModificatorToString(creatureThe.modificator) << " "
                      << RaceToString(creatureThe.race) << " won!" << std::endl;
            std::cout << "They have slained " << playerOne.name << "." << std::endl;
            done = true;
        }
    }
}

std::string RaceToString(RaceEnum race) {
    switch (race) {
    case RaceEnum::UNDEAD: {
        return "Undead";
        break;
    }
    case RaceEnum::SYREN: {
        return "Syren";
        break;
    }
    case RaceEnum::BANSHEE: {
        return "Banshee";
        break;
    }
    case RaceEnum::GOBLIN: {
        return "Goblin";
        break;
    }
    case RaceEnum::IMP: {
        return "Imp";
        break;
    }
    case RaceEnum::WYVERN: {
        return "Wyvern";
        break;
    }
    default: {
        throw std::invalid_argument("Unknown Monster");
        break;
    }
    }
}

std::string ModificatorToString(ModificatorEnum mod) {
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
        return "Halfdead";
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
        throw std::invalid_argument("Unknown Modificator");
        break;
    }
    }
}