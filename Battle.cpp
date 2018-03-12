#include <iostream>
#include <cstdlib>
#include <string>
//#include "passive-output.cpp"
#include "Player.h"
#include "Mob.h"
#include "Item.h"
#include "Battle.h"
#include "libsqlite.hpp"

using namespace std;


void Battle::basic_attack(Player playerObj, Mob enemy, Item equipped)
{		int hit = rand() % 100+1;
	  if(equipped.getHitChance() >= hit) //If player rolls within his hit chance...
    {
      if (equipped.getRange() > 0) //If the player is using a ranged weapon...
      {
          int incomingDamage = equipped.getDmg() - 1.2*playerObj.dexterity + enemy.getArmor(); //Calculates incoming damage, using player, enemy and weapon attributes
          enemy.setHP(enemy.getHP() - incomingDamage);
          cout << "You hit the enemy for "+incomingDamage << endl;
      }
      else //If the player is using a melee weapon...
      {
        int incomingDamage = equipped.getDmg() - 1.2*playerObj.attack + enemy.getArmor();
        enemy.setHP(enemy.getHP() - incomingDamage);
        cout << "You hit the enemy for "+incomingDamage << endl;
      }
    }
		else
		{ //If the player misses...
			cout << "You missed!" << endl;
		}
}

void Battle::ability(Player playerObj, Mob enemy)
{
  //ability.use(playerObj.classID);
}

void Battle::magic(Player playerObj, Mob enemy)
{
  if(playerObj.classID == 4) //MAGIC WILL BE MAGE ONLY FOR SIMPLICITIES SAKE
		{
      int mageHitChance = 50 + (playerObj.intelligence)*5;
			int hit = rand() % 100 + 1;
			if(mageHitChance >= hit)
			{
				int incomingDamage = playerObj.intelligence*2;
        enemy.setHP(enemy.getHP() - incomingDamage);
				cout << "Magic attack hits for "+incomingDamage << endl;
			}
			else
			{
				cout << "You missed!" << endl;
			}
        }
	else
	{
		cout << "Your feeble mind cannot comprehend magic!" << endl;
	}
}

void Battle::item()
{
  //coming soon
}

void Battle::battle(Player playerObj, Mob enemy, Item equipped)
  //battle function takes player, mob and item objects as parameters
  //item object should be players equipped weapon
{
	  int turn = 0;
    //passive();
	cout << "Level " << enemy.getLevel() << " " << enemy.getName() << " appears!" << endl;
  cout << "Select a battle option" << endl;
	cout << "1 - Basic Attack" << endl;
	cout << "2 - Ability" << endl;
	cout << "3 - Magic" << endl;
	cout << "4 - Item" << endl; //allows the player to select an option
	while(turn % 2== 0)
  { //While it is the players turn:
    short choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      basic_attack(playerObj, enemy, equipped);
      ++turn;
      break;
    }
    case 2:
    {
      ability(playerObj, enemy);
      ++turn;
      break;
    }
    case 3:
    {
      magic(playerObj, enemy);
      ++turn;
      break;
    }
    case 4:
    {
      //item();
      ++turn;
      break;
    }
    default:
        cout << "Invalid choice!" << endl;
        continue;
  }
 }
}

	/* ENEMY BATTLE PHASE GOES HERE*/
	//reminder: after enemy battle phase if enraged==1 or poisoned==1 deal bosshp%10 dmg
	//reminder: if skipTurn==1 end enemy battle phase



/*int main()
{
  Player testguy;
  Mob enemydude;
  Item sword;
  Battle::battle(testguy, enemydude, sword);
  return 0;
}*/
