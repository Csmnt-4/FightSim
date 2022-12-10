#include <iostream>
#include <csignal>
#include "library/entities/Monster.h"
#include "library/entities/Player.h"
#include "library/helpers/DieRoller.h"
#include "library/attacks/Physical.h"


int main() {
    DieRoller dice;
    std::string input;

    Player playerOne;
    CreateCharacter(playerOne);
    playerOne.vitl *= 10;

    std::getline(std::cin, input);

    std::cout << "\nDo you wish to battle manually (Y/N)?" << std::endl;
    std::getline(std::cin, input);
    if ((input == "Y") || (input == "y") || (input == "Yes") || (input == "yes")) {
        std::cout << "Sorry, you cannot do it yet." << std::endl;

        bool done = false;
        while (!done) {
            Monster creatureThe;
            GenerateMonsterRandom(creatureThe);

            if (AutomaticFight(playerOne, creatureThe, dice)) {
                std::cout << playerOne.name << " won!" << std::endl;
                sleep(2);
                std::cout << "  You have " << playerOne.vitl << " HP left." << std::endl;
                std::cout << "  The monster had " << creatureThe.vitl * 10 << " HP." << std::endl;
                sleep(2);
            } else {
                std::cout << ModToString(creatureThe.mod) << " "
                          << RaceToString(creatureThe.race) << " wins." << std::endl;
                sleep(2);
                std::cout << "  They have slain " << playerOne.name << "." << std::endl;
                std::cout << "  The monster had " << creatureThe.vitl * 10 << " HP." << std::endl;
                sleep(2);
                done = true;
            }
        }
    } else {
        bool done = false;
        while (!done) {
            Monster creatureThe;
            GenerateMonsterRandom(creatureThe);

            if (AutomaticFight(playerOne, creatureThe, dice)) {
                std::cout << playerOne.name << " won!" << std::endl;
                sleep(2);
                std::cout << "  You have " << playerOne.vitl << " HP left." << std::endl;
                std::cout << "  The monster had " << creatureThe.vitl * 10 << " HP." << std::endl;
                sleep(2);
            } else {
                std::cout << ModToString(creatureThe.mod) << " "
                          << RaceToString(creatureThe.race) << " wins." << std::endl;
                sleep(2);
                std::cout << "  They have slain " << playerOne.name << "." << std::endl;
                std::cout << "  The monster had " << creatureThe.vitl * 10 << " HP." << std::endl;
                sleep(2);
                done = true;
            }
        }
    }

    return 0;
}
