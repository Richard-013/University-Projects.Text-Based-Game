#ifndef ABILITY_USE_H
#define ABILITY_USE_H
#include "Player.h"
#include "Mob.h"
using namespace std;

extern int skipTurn, abilityDamage, enraged, poisoned;
int useAbility(Player playerObj, Mob enemy, int turn);

#endif