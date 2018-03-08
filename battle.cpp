#include <iostream>
#include <cstdlib>
#include <string>
//#include "passive-output.cpp"
#include "Player.h"
#include "Mob.h"
#include "Item.h"
#include "libsqlite.hpp"

using namespace std;


/*struct PlayerCharacter() //Pulls character data from database and saves it as local variables
 * THIS CODE IS CURRENTLY NOT IN USE AS PLAYER STATS ARE STORED IN AN INSTANCE OF THE PLAYER CLASS IN PLAYER.CPP
{
  string name;
  int level;
  int exp;
  int health;
  int remHealth;
  int attack;
  int defence;
  int intelligence;
  int perception;
  int dexterity;
  int hitChance;

  PlayerCharacter()
  {
    int id = 1;
    sqlite::sqlite db("RPGDatabase.db");
    auto cur = db.get_statement();
    cur->set_sql("SELECT * FROM CharacterData WHERE CharacterID = ?");
    cur->prepare();
    cur->bind(1, id);
    cur->step();
    string name = cur->get_text(1);
    int playerClass = cur->get_int(2);
    int level = cur->get_int(3);
    int exp = cur->get_int(4);
    int health = cur->get_int(5);
    int remHealth = cur->get_int(6);
    int attack = cur->get_int(7);
    int defence = cur->get_int(8);
    int intelligence = cur->get_int(9);
    int perception = cur->get_int(10);
    int dexterity = cur->get_int(11);
    int hitChance = 90;

    cout << name << " " << playerClass << " " << level << " " << exp << " " << health << " " << remHealth << " " << attack << " " << defence << " " << intelligence << " " << perception << " " << dexterity << endl;
  }
};*/

/*struct Monster
{
  Monster()
  {
    string name;
    int level;
    int armor;
    int HP;
    int speed;
    int dmg;
    int hitChance;
    int critChance;
    int range;
  }
};*/





/*void battle(Player playerObj, Mob enemy, Item equipped)
  //battle function takes player, mob and item objects as parameters
  //item object should be players equipped weapon
{
	  //int turn = 0;
    //passive();
	cout << "Level " << Enemy.getLevel() << " " << Enemy.getName() << " appears!" << endl;
  cout << "Select a battle option" << endl;
	cout << "1 - Basic Attack" << endl;
	cout << "2 - Ability" << endl;
	cout << "3 - Magic" << endl;
	cout << "4 - Item" << endl; //allows the player to select an option
	while(turn % 2== 0){ //While it is the players turn:
  int hitChance = Weapon.getHitChance();
	int mageHitChance = 50 + PC.intelligence*5
	int incomingDamage;
	short choice;
	cin >> choice;
	switch (choice){
	case 1:
	{
		basic_attack();
		break;
	}
	case 2:
	{
		++turn;
		cout << "Ability" << endl;
		//ability-use();
		//incomingDamage = abilityDamage;
		//Enemy.setHP(Enemy.getHP() - abilityDamage);
		break;
	}
	case 3:
	{

		break;
	}
	case 4:
	{
		turn = turn + 1;
	    /*
	    string itemChoice;
	    SELECT itemName FROM inventory WHERE usable = 1;
	    while(cur->step())
            cout << cur->get_text(0) << endl;
        cout << "Choose an item" << endl;
        cin >> itemChoice;
		break;

	}
    default:
        cout << "Invalid choice!" << endl;
        continue;
        }

	}


	/* ENEMY BATTLE PHASE GOES HERE*/
	//reminder: after enemy battle phase if enraged==1 or poisoned==1 deal bosshp%10 dmg
	//reminder: if skipTurn==1 end enemy battle phase

//}


void basic_attack(Player playerObj, Mob enemy, Item equipped)
{		int hit = rand() % 100+1;
	  if(playerObj.hitChance >= hit) //If player rolls within his hit chance...
    {
      if (equipped.getRange > 0) //If the player is using a ranged weapon...
      {
          int incomingDamage = equipped.getDmg() - 1.2*playerObj.dexterity + enemy.getArmor(); //Calculates incoming damage, using player, enemy and weapon attributes
          enemy.setHP(enemy.getHP() - incomingDamage);
      }
      else //If the player is using a melee weapon...
      {
        incomingDamage = equipped.getDmg() - 1.2*playerObj.attack + enemy.getArmor();
        enemy.setHP(enemy.getHP() - incomingDamage);
      }
      cout << "You hit the enemy for "+incomingDamage << endl;
      ++turn;
    }
		else
		{ //If the player misses...
			cout << "You missed!" << endl;
		}
}

void ability(Player playerObj, Mob enemy)
{
  ++turn;
  ability.use(Player playerObj.classID);
}

void magic(Player playerObj, Mob enemy)
{
  if(PC.characterClass == 4) //MAGIC WILL BE MAGE ONLY FOR SIMPLICITIES SAKE
		{
      mageHitChance = 50 + (playerObj.intelligence)*5;
			++turn;
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

int main()
{

  return 0;
}
