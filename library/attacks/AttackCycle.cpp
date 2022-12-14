#include <iostream>
#include <csignal>
#include "library/entities/Player.h"
#include "library/entities/Monster.h"

bool AutomatedFight(Player &player, Monster &monster, DieRoller dice) {
    int playerHealth = player.vitl;
    int monsterHealth = monster.vitl * 10;

    int playerAttackDamage;
    int monsterAttackDamage;
    int playerChances;
    int monsterChances;

    std::cout << "\n" << ModToString(monster.mod) << " " << RaceToString(monster.race) << " appears in front of you!\n";
    std::cout << player.name << " begins their attack on " << ModToString(monster.mod) << " "
              << RaceToString(monster.race) << "\n";

    while (monsterHealth > 0 && playerHealth > 0) {
        // previously DieRoller failed with segmentation error while trying to use the negative or zero values. After few iterations changed DieRoller.
        playerAttackDamage =
                2 * dice.Roll1DN(player.pAtk) + dice.Roll1DN(player.modPAtk) + dice.Roll1DN(player.luck);
        monsterAttackDamage =
                2 * dice.Roll1DN(monster.pAtk) + dice.Roll1DN(monster.modPAtk) + dice.Roll1DN(monster.luck);

        playerChances =
                70 - (monster.agil + dice.Roll1DN(monster.modAgil) - player.agil + dice.Roll1DN(player.modAgil)) *
                     (dice.Roll1DN(3) + dice.Roll1DN(3)) + dice.Roll1DN(player.luck);
        monsterChances =
                70 - player.agil + dice.Roll1DN(player.modAgil) - monster.agil + dice.Roll1DN(monster.modAgil) +
                dice.Roll1DN(monster.luck);


        sleep(2);
        if (dice.Roll1DN(100) <= playerChances) {
            std::cout << player.name << " hits " << ModToString(monster.mod) << " "
                      << RaceToString(monster.race) << " for " << playerAttackDamage << " damage!" << std::endl;
            if (playerAttackDamage > 20)
                std::cout << "Critical hit!" << std::endl;
            monsterHealth -= playerAttackDamage;
        } else {
            std::cout << player.name << " misses the" << " " << RaceToString(monster.race) << std::endl;
            std::cout << "  Your chance to hit was " << playerChances << "%" << std::endl;
        }

        sleep(2);
        if (monsterHealth > 0) {
            if (dice.Roll1DN(100) <= monsterChances) {
                std::cout << ModToString(monster.mod) << " " << RaceToString(monster.race) << " hits " << "Player "
                          << player.name << " for " << monsterAttackDamage << " damage!" << std::endl;
                if (monsterAttackDamage > 20)
                    std::cout << "Critical hit!" << std::endl;
                playerHealth -= monsterAttackDamage;
                std::cout << "  HP left: " << playerHealth << std::endl;
            } else {
                std::cout << ModToString(monster.mod) << " " << RaceToString(monster.race) << " misses player "
                          << player.name << std::endl;
                if (monsterChances > 0)
                    std::cout << "  Their chance to hit was " << monsterChances << "%" << std::endl;
            }
        };
    };
    sleep(2);
    player.vitl = playerHealth;

    if (playerHealth > 0) {
        return true;
    } else {
        if (monsterHealth == monster.vitl * 10)
            std::cout
                    << "That was a very unlucky fight. Come have another later, when you have more agility! Or luck..."
                    << std::endl;

        return false;
    }
}

bool ManualFight(Player &player, Monster &monster, DieRoller dice) {
    int playerHealth = player.vitl;
    int monsterHealth = monster.vitl * 10;

    std::cout << "\n" << ModToString(monster.mod) << " " << RaceToString(monster.race) << " appears in front of you!\n";
    std::cout << player.name << " begins their attack on " << ModToString(monster.mod) << " "
              << RaceToString(monster.race) << "\n";

    while (monsterHealth > 0 && playerHealth > 0) {
        /** TODO: Attack cycle
         * tell : monster state = sequence of random(open/defencive) -> basic atk -> random(leanLeft/leanRight/leanFront/leanBack)
         *                                                            -> tricks -> check player int (maybe add perception?) -> random(trickLeft/trickRight/trickFront/trickBack)
         *                                                            -> basic def -> random(postureFocus(+ parry chance)/postureDefence(take attack-defence))
         * player choice : attack(swingLeft/swingRight/shortStab(front)/longStab(back)) or defence(postureFocus(parry chance)/postureDefence(take damage-defence))
         * TODO: MAGIC!!! EVERYBODY LOVES TO SHOOT FIREBALLS!!!
         *
         * check (state vs choice)
         * roll damage
         * if !defence
         *      roll parry chances
         *      if !parry apply damage
         * else
         *      apply damage - defence
         * tell : parry/chances || result/damage
         *
         * player state = result of previous choice (attack side to lean || posture)
         * tell : monster choice = result of previous state -> !parry -> was lean -> lean to same side attack
         *                                                            -> was trick -> lean to different side attack
         *                                                            -> was parry/defence
         *                                                                  -> check int (perception?)
         *                                                                          -> half-rand(swingLeft/swingRight/shortStab(front)/longStab(back))
         *                                                  -> parried player attack
         *                                                            -> was lean -> lean to different side attack
         *                                                            -> was trick -> lean to same side attack
         *                                                            -> was parry/defence
         *                                                                  -> check int (perception?)
         *                                                                         -> half-rand(swingLeft/swingRight/shortStab(front)/longStab(back))
         *
         * check (state vs choice)
         * roll damage
         * if defence
         *      apply damage - defence
         * else
         *     roll parry chances
         *     if !parry apply damage
         * tell : parry/chances || result/damage
         */
    }
    sleep(2);
    player.vitl = playerHealth;

    if (playerHealth > 0) {
        return true;
    } else {
        if (monsterHealth == monster.vitl * 10)
            std::cout
                    << "That was a very unlucky fight. Come have another later, when you have more agility! Or luck..."
                    << std::endl;

        return false;
    }
}
