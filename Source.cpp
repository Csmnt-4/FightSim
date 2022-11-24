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
        GenerateMonster(creatureThe);

        if (Fight(playerOne, creatureThe)) {
            std::cout << "The player " << playerOne.name << " won!" << std::endl;
            std::cout << "They have " << playerOne.vitl * 10 << " HP left." << std::endl;
        }
        else {
            std::cout << "Monster " << creatureThe.race << " won!" << std::endl;
            std::cout << "They have " << playerOne.vitl * 10 << " HP left." << std::endl;
            done = true;
        }
    }
}

std::string RaceToChar(RaceEnum race) {
    switch (race)
    {
    default:
    {
        throw std::invalid_argument("Unknown Monster");
        break;
    }
    case RaceEnum::UNDEAD: {
        return "Undead";
        break;
    }
    case RaceEnum::SYREN: {
        return "Syren";
        break;

    } case RaceEnum::BANSHEE: {
        return "Banshee";
        break;
    } case RaceEnum::GOBLIN: {
        return "Goblin";
        break;
    }case RaceEnum::IMP: {
        return "Imp";
        break; }
    case RaceEnum::WYVERN: {
        return "Wyvern";
        break; }
    }
}