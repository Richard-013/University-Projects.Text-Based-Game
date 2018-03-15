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
		int ability(Player playerObj, Mob enemy);
    int magic(Player playerObj, Mob enemy);
    void item();
    int enemyphase(Player playerObj, Mob enemy);
    void battle(Player playerObj, Mob enemy, Item equipped);
		int main();

    protected:

    private:
};

#endif