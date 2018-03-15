#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "ability-use.h"
#include "Player.h"
#include "Mob.h"
#include "Item.h"
#include "Battle.h"
#include "libsqlite.hpp"

using namespace std;



int Battle::basic_attack(Player playerObj, Mob enemy, Item equipped)
{	  srand(time(NULL));
    int hit = rand() % 100+1;
    int crit = rand() % 100+1;
	  if(equipped.getHitChance() >= hit) //If player rolls within his hit chance...
      {
          if (equipped.getRange() > 0) //If the player is using a ranged weapon...
          {
              int incomingDamage = equipped.getDmg() + 1.2*playerObj.dexterity - enemy.getArmor(); //Calculates incoming damage, using player, enemy and weapon attributes
              if(equipped.getCritChance() >= crit)
              {
                cout << "Critical hit!" << endl;
                incomingDamage *= 2;
              }
              cout << "You hit for " << incomingDamage << endl;
              return incomingDamage;
          }
          else //If the player is using a melee weapon...
          {
                int incomingDamage = equipped.getDmg() + 1.2*playerObj.attack - enemy.getArmor();
                if(equipped.getCritChance() >= crit)
                {
                  cout << "Critical hit!" << endl;
                  incomingDamage *= 2;
                }
                cout << "You hit the enemy for " <<incomingDamage << " damage!" << endl;
                return incomingDamage;
          }
      }
	  else
      {   //If the player misses...
          cout << "You missed!" << endl;
          return 0;
	  }
}

int Battle::abilityUse(Player playerObj, Mob enemy, int turn)
{
  int incomingDamage = useAbility(playerObj, enemy, turn);
  return incomingDamage;
}

int Battle::magic(Player playerObj, Mob enemy)
{
  if(playerObj.classID == 4) //MAGIC WILL BE MAGE ONLY FOR SIMPLICITIES SAKE
		{
      int mageHitChance = 50 + (playerObj.intelligence)*5;
			int hit = rand() % 100 + 1;
			if(mageHitChance >= hit)
			{
				int incomingDamage = playerObj.intelligence*2;
				cout << "Magic attack hits for "+incomingDamage << endl;
        return incomingDamage;
			}
			else
			{
				cout << "You missed!" << endl;
        return 0;
			}
   }
	else
	{
		cout << "Your feeble mind cannot comprehend magic!" << endl;
    return 0;
	}
}

void Battle::item()
{
  //coming soon
}

int Battle::enemyphase(Player playerObj, Mob enemy)
{
  /*if(skipTurn==1)
  {
    return 0;
  }*/
  int hit = rand() % 100+1;
  int crit = rand() % 100+1;  
  if(enemy.getHitChance() >= hit)
  {
    int incomingDamage = enemy.getDmg() - playerObj.defence;
    /*if(enraged == 1 or poisoned == 1)
    {
      incomingDamage = incomingDamage + bosshp%10;
    }*/
    if(incomingDamage < 0) //Incoming damage cannot be negative
    {
      incomingDamage = 0;
    }
    if(enemy.getCritChance() >= crit)
    {
      cout << "Enemy Crit!" << endl;
      incomingDamage *= 2;
    }
    cout << "Enemy " << enemy.getName() << " swings at you for " << incomingDamage << " damage!" << endl;
    return incomingDamage;
  }
  else
  {
    cout << "Enemy Missed!" << endl;
    return 0;
  }
	//reminder: after enemy battle phase if enraged==1 or poisoned==1 deal bosshp%10 dmg
	//reminder: if skipTurn==1 end enemy battle phase

}

void Battle::battle(int CharacterID, int MobID, Item equipped)
  //battle function takes player, mob and item objects as parameters
  //item object should be players equipped weapon
{ Player playerObj;
  sqlite::sqlite db("RPGDatabase.db");
  auto cur = db.get_statement();
  cur->set_sql("select * from CharacterData where CharacterID = ?");
  cur->prepare();
  cur->bind(1, CharacterID);
  cur->step();
  playerObj.name = cur->get_text(1);
  playerObj.classID = cur->get_int(2);
  playerObj.level = cur->get_int(3);
  playerObj.experience = cur->get_int(4);
  playerObj.health = cur->get_int(5);
  playerObj.remainingHealth = cur->get_int(6);
  playerObj.attack = cur->get_int(7);
  playerObj.defence = cur->get_int(8);
  playerObj.intelligence = cur->get_int(9);
  playerObj.perception = cur->get_int(10);
  playerObj.dexterity = cur->get_int(11);
  Mob enemy;
  auto cur2 = db.get_statement();
  cur2->set_sql("select * from Mobs where MobID = ?");
  cur2->prepare();
  cur2->bind(1, MobID);
  cur2->step();
  enemy.setName(cur2->get_text(1));
  enemy.setLevel(cur2->get_int(2));
  enemy.setArmor(cur2->get_int(3));
  enemy.setHP(cur2->get_int(4));
  enemy.setSpeed(cur2->get_int(5));
  enemy.setDmg(cur2->get_int(6));
  enemy.setHitChance(cur2->get_int(7));
  enemy.setCritChance(cur2->get_int(8));
  enemy.setRange(cur2->get_int(9));
  int enemyHP = enemy.getHP();
  int turn = 0;
  printf("\033c");
  if(equipped.getSpeed() < enemy.getSpeed()) //Enemy has attack priority if they have higher speed
  {
    turn = 1;
  }
  cout << " Level " << enemy.getLevel() << " " << enemy.getName() << " appears!" << endl;
  cout << "Select a battle option" << endl;
	cout << "1 - Basic Attack" << endl;
	cout << "2 - Ability" << endl;
	cout << "3 - Magic" << endl;
	cout << "4 - Item" << endl; //allows the player to select an option
  int hp = playerObj.health;
  while(hp > 0 && enemyHP > 0)
  {
	
    while(turn % 2== 0)
  { //While it is the players turn:
    short choice;
    cin >> choice;
    printf("\033c");
    cout << " Select a battle option" << endl;
    cout << "1 - Basic Attack" << endl;
    cout << "2 - Ability" << endl;
    cout << "3 - Magic" << endl;
    cout << "4 - Item" << endl;
    switch (choice)
    {
    case 1:
    {
      enemyHP = enemyHP - basic_attack(playerObj, enemy, equipped);
      ++turn;
      break;
    }
    case 2:
    {
      enemyHP = enemyHP - abilityUse(playerObj, enemy, turn);
      ++turn;
      break;
    }
    case 3:
    {
      enemyHP = enemyHP - magic(playerObj, enemy);
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
    while(turn%2==1)
    {
      hp = hp - enemyphase(playerObj, enemy);
      cout << "Your HP: " << hp << "                 " << "Enemy HP: " << enemyHP << endl;
      ++turn;
    }
  }
	if(hp <= 0)
  {
    cout << "You fought bravely, but you were overpowered and killed. " << endl;
    cout << "GAME OVER" << endl;
  }
  if(enemyHP <= 0)
  {
    cout << "Your foe falls to the ground, lifeless." << endl;
    cout << "VICTORY!" << endl;
  }
  
  
}



