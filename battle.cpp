#include <iostream>
#include <cstdlib>
#include <string>
//#include "passive-output.cpp"
//#include "Player.h"
//#include "Mob.h"
//#include "Item.h"
#include "libsqlite.hpp"

using namespace std;

struct PlayerCharacter //Pulls character data from database and saves it as local variables
{
  int playerClass;
  int level;
  int exp;
  int health;
  int remHealth;
  int attack;
  int defence;
  int intelligence;
  int perception;
  int dexterity;
  
  PlayerCharacter()
  {
  short id = Player::CharacterID;
  sqlite::sqlite db("RPGDatabase.db");
  auto cur = db.get_statement();
  cur->set_sql("SELECT * FROM CharacterData WHERE CharacterID = ?");
  cur->prepare();
  cur->bind(1, id);
  cur->step();
  string name = cur->get_text(1);
  playerClass = cur->get_int(2);
  level = cur->get_int(3);
  exp = cur->get_int(4);
  health = cur->get_int(5);
  remHealth = cur->get_int(6);
  attack = cur->get_int(7);
  defence = cur->get_int(8);
  intelligence = cur->get_int(9);
  perception = cur->get_int(10);
  dexterity = cur->get_int(11);
  
  //cout << name << " " << playerClass << " " << level << " " << exp << " " << health << " " << remHealth << " " << attack << " " << defence << " " << intelligence << " " << perception << " " << dexterity << endl;
  }
};

void battle(PlayerCharacter PC, Monster Mob, Item Weapon) 
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
		turn = turn + 1;
		int hit = rand() % 100+1;
	    if(hitChance >= hit) //If player rolls within his hit chance...
		{
			if (Weapon.getRange > 0) //If the player is using a ranged weapon...
			{
				incomingDamage = Weapon.getDmg() - 1.2*PC.dexterity + Enemy.getArmor(); //Calculates incoming damage, using player, enemy and weapon attributes
				Enemy.setHP(Enemy.getHP() - incomingDamage);
			}
			else //If the player is using a melee weapon...
			{
				incomingDamage = Weapon.getDmg() - 1.2*PC.attack + Enemy.getArmor();
				Enemy.setHP(Enemy.getHP() - incomingDamage);
			}
			cout << "You hit the enemy for "+incomingDamage << endl;
        }
		else
		{ //If the player misses...
			cout << "You missed!" << endl;
		}
		break;
	}
	case 2:
	{	
		turn = turn + 1;
		cout << "Ability" << endl;
		//ability-use();
		//incomingDamage = abilityDamage;
		//Enemy.setHP(Enemy.getHP() - abilityDamage);
		break;
	}
	case 3:
	{
		if(PC.characterClass == 4) //MAGIC WILL BE MAGE ONLY FOR SIMPLICITIES SAKE
		{
			turn = turn + 1;
			hit = rand() % 100 + 1;
			if(mageHitChance >= hit)
			{
				//pseudo code: mobHP = mobHP - magicdmg - 1.6*intelligence
				cout << "Magic attack" << endl;
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

}

int main()
{
  //PlayerCharacter test;
}
