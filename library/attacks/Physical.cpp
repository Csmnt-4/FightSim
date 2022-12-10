//
// Created by victor on 10/12/22.
//

#include <iostream>
#include <csignal>
#include "library/entities/Player.h"
#include "library/entities/Monster.h"
#include "library/helpers/DieRoller.h"

bool AutomaticFight(Player &player, Monster monster, DieRoller dice) {
    int playerHealth = player.vitl;
    int monsterHealth = monster.vitl * 10;
    int playerAttackDamage;
    int monsterAttackDamage;
    int playerChances;
    int monsterChances;

    std::cout << "\n" << ModToString(monster.mod) << " " << RaceToString(monster.race) << " appears in front of you!"
              << std::endl;
    sleep(1);
    std::cout << player.name << " begins their attack on " << ModToString(monster.mod) << " "
              << RaceToString(monster.race) << std::endl;

    do {
        playerAttackDamage = dice.Roll1DN(5) * player.pAtk + dice.Roll1DN(4) * player.modPAtk + dice.Roll1DN(5);
        monsterAttackDamage = dice.Roll1DN(4) * monster.pAtk + dice.Roll1DN(3) * monster.modPAtk + dice.Roll1DN(4);

        playerChances =
                dice.Roll1DN(5) * (player.agil + player.modAgil) + dice.Roll1DN(5) * player.luck;
        monsterChances = dice.Roll1DN(5) * (monster.agil + monster.modAgil + monster.luck);

        if (playerHealth > 0) {
            if (dice.Roll1DN(100) <= playerChances) {
                sleep(2);
                std::cout << player.name << " hits " << ModToString(monster.mod) << " "
                          << RaceToString(monster.race) << " for " << playerAttackDamage << " damage!" << std::endl;
                monsterHealth -= playerAttackDamage;

            } else {
                sleep(2);
                std::cout << player.name << " misses the" << " " << RaceToString(monster.race) << std::endl;
                std::cout << "  Your chance to hit was " << playerChances << "%" << std::endl;
            }
            if (monsterHealth > 0) {
                if (dice.Roll1DN(100) <= monsterChances) {
                    sleep(2);
                    std::cout << ModToString(monster.mod) << " " << RaceToString(monster.race) << " hits " << "Player "
                              << player.name << " for " << monsterAttackDamage << " damage!" << std::endl;
                    if (monsterAttackDamage > 50)
                        std::cout << "Critical hit!" << std::endl;
                    playerHealth -= monsterAttackDamage;
                    std::cout << "  HP left: " << playerHealth << std::endl;
                } else {
                    sleep(2);
                    std::cout << ModToString(monster.mod) << " " << RaceToString(monster.race) << " misses player "
                              << player.name << std::endl;
                    if (monsterChances > 0)
                        std::cout << "  Their chance to hit was " << monsterChances << "%" << std::endl;
                }
            };
        };

    } while (monsterHealth > 0 && playerHealth > 0);

    player.vitl = playerHealth;
    sleep(2);

    if (playerHealth > 0) {
        return true;
    } else {
        if (monsterHealth == monster.vitl * 10)
            std::cout << "That was a very unlucky fight. Come have another later, when you have more agility! Or luck..." << std::endl;

        return false;
    }
}
