#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"
#include "Mob.h"
#include "Item.h"

using namespace std;

class Battle
{
    public:
        void basic_attack(Player playerObj, Mob enemy, Item equipped);
		void ability(Player playerObj, Mob enemy);
		int main();

    protected:

    private:
};

#endif