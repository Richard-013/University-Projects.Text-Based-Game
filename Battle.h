#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"
#include "Mob.h"
#include "Item.h"

using namespace std;

class Battle
{
    public:
    int basic_attack(Player playerObj, Mob enemy, Item equipped);
		int abilityUse(Player playerObj, Mob enemy, int turn);
    int magic(Player playerObj, Mob enemy);
    void item();
    int enemyphase(Player playerObj, Mob enemy);
    void battle(int CharacterID, int MobID, Item equipped);
		int main();
    int turn;

    protected:

    private:
};

#endif