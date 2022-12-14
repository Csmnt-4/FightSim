#ifndef FIGHTSIM_ATTACKCYCLE_H
#define FIGHTSIM_ATTACKCYCLE_H

//TODO: Ask about #pragma once

#include "library/entities/Player.h"
#include "library/entities/Monster.h"

bool AutomatedFight(Player &player, Monster &monster, DieRoller dice);
bool ManualFight(Player &player, Monster &monster, DieRoller dice);

#endif //FIGHTSIM_ATTACKCYCLE_H
