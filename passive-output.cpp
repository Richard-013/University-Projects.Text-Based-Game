#include <iostream>

using namespace std;

int shield;

void passive(Player playerObj.classID)
{
//grabbing player info

    id = playerObj.classID;
    sqlite::sqlite db("RPGDatabase.db");
    auto cur = db.get_statement();
    cur->set_sql("SELECT * FROM CharacterData WHERE CharacterClassID = ?");
    cur->prepare();
    cur->bind(1, id);
    cur->step();
    int attack = cur->get_int(8);
    int defence = cur->get_int(9);
    int intelligence = cur->get_int(10);
    int perception = cur->get_int(11);
    int dexterity = cur->get_int(12);

if(id==1)
    {
    shield = defence + turn;
    cout<<"***You gain extra shield every turn. (+" +  shield + ")";
    break;
    }
case 2:
    {
    cout<<"***You always strike first in a battle.";
    break;
    }
case 3:
    {
    int extradmg;
    extradmg = rand()%10;//random number between 0-9
    cout<<"***You've put poison on your arrows and deal (+." +extradmg +") every turn.";
    break;
    }
case 4:
    {
    int chance;
    chance = rand()%3;
    cout<<"***Every 3 turns you summon a portal that has a chance in three to terminate the enemy.";
    if(chance==1)
    {
    //terminatheenemy
    }
 break;
    }


}

}
