#include <iostream>
#include "Player.h"
#include "Mob.h"
#include "Battle.h"
#include "ability-use.h"
#include "libsqlite.hpp"


using namespace std;


int useAbility(Player playerObj, Mob enemy, int turn)
{
    //grabbing player info
    int skipTurn,abilityDamage,enraged,poisoned;

    sqlite::sqlite db("RPGDatabase.db");
    auto cur = db.get_statement();
    cur->set_sql("SELECT * FROM CharacterData WHERE CharacterClassID = ?");
    cur->prepare();
    cur->bind(1, playerObj.characterID);
    cur->step();
    int attack = cur->get_int(8);
    int defence = cur->get_int(9);
    int intelligence = cur->get_int(10);
    int perception = cur->get_int(11);
    int dexterity = cur->get_int(12);


    //grabbing mob info-soon


if(playerObj.classID==1)
{
    cout<<" 1 - Enrage to deal extra "<<enemy.getHP()%10<<" damage next turn."<<endl;
    cout<<" 2 - Shield Bash -- dash forward to slam the enemy with the shield."<<endl;
    cout<<" 3 - Spin your blades -- area of effect damage"<<endl;

    int ability;
    cin>>ability;

    switch(ability)
    {
    case 1:
        {
        int extraFromEnrage;
        enraged=1;
        extraFromEnrage=enemy.getHP()%10;
        break;
        }
    case 2:
        {
        abilityDamage = attack + turn + 0.5*(enemy.getHP()%10);
        cout<<"You crushed your enemy with your shield, dealing " << abilityDamage << "."<<endl;
        return abilityDamage;
        break;
        }
    case 3:
        {
        abilityDamage = attack + turn + rand()%12;
        cout<<"You've dealt "<<abilityDamage<<" to all the enemies."<<endl;
        return abilityDamage;
        break;
        }
     default:
        {
        cout<<"Invalid input.";
        cin>>ability;
        }
    break;
    }
}
if(playerObj.classID==2)
{
    cout<<" 1 - Backstab"<<endl;
    cout<<" 2 - Shadow Kick"<<endl;
    cout<<" 3 - Fan of Knives -- area of effect damage"<<endl;

    short ability;
    cin>>ability;
  
    switch(ability)
    {
    case 1:
        {
        abilityDamage = playerObj.dexterity + turn + 0.25*(enemy.getHP()%50);
        cout<<"You've lurked from the shadows to stab your enemy in the back, dealing "<<abilityDamage<<" damage and poisoning them for an extra "<<enemy.getHP()%10<<" next turn."<<endl;
        poisoned = 1;
        return abilityDamage;
        break;
        }
    case 2:
        {
        abilityDamage = playerObj.dexterity + turn + rand()%10;
        cout<<"You've kicked your enemy where it hurts the most! You've dealt "<<abilityDamage<< " damage."<<endl;
        return abilityDamage;
        break;
        }
    case 3:
        {
        abilityDamage = playerObj.dexterity + turn + rand()%12;
        cout<<"You've dealt "<<abilityDamage<<" to all the enemies."<<endl;
        return abilityDamage;
        break;
        }
    default:
    {
        cout<<"Invalid input.";
        cin>>ability;
    }
    break;
    }
}
if(playerObj.classID==3)
{
    cout<<" 1 - Mutilate"<<endl;
    cout<<" 2 - Concussive shot"<<endl;
    cout<<" 3 - Rain with arrows"<<endl;

    short ability;
    cin>>ability;

    switch(ability)
    {

    case 1:
        {
        abilityDamage = perception + rand()%10;
        cout<<"You've grabbed your skinning knife and dealt "<<abilityDamage<<" to the enemy's face."<<endl;
        return abilityDamage;
        break;
        }
    case 2:
        {
        abilityDamage = perception + turn + enemy.getHP()%5;
        cout<<"You've hit your enemy in the head dealing "<<abilityDamage<< " damage and dizzying it for the next turn."<<endl;
        skipTurn=1;
        return abilityDamage;
        break;
        }
    case 3:
        {
        abilityDamage = perception + turn + rand()%12;
        cout<<"You've dealt "<<abilityDamage<<" to all the enemies."<<endl;
        return abilityDamage;
        break;
        }
     default:
        {
        cout<<"Invalid input.";
        cin>>ability;
        }
    break;
    }
}  
if(playerObj.classID==4)
{
    cout<<" 1 - Fireball"<<endl;
    cout<<" 2 - Ice Cone"<<endl;
    cout<<" 3 - Blizzard"<<endl;

    short ability;
    cin>>ability;

    switch(ability)
    {
        case 1:
            {
            abilityDamage = intelligence + turn + 0.25*(enemy.getHP()%50);
            cout<<"You conjured up a ball of flame that rushed through your enemy dealing "<<abilityDamage<<" damage."<<endl;
            return abilityDamage;
            break;
            }
        case 2:
            {
            cout<<"You've freezed yourself, becoming invulnerable to any damage for the next turn."<<endl;
            skipTurn=1;
            abilityDamage = 0;
            return abilityDamage;
            break;
            }
        case 3:
            {
            abilityDamage = intelligence + turn + rand()%12;
            cout<<"You've dealt "<<abilityDamage<<" to all enemies.";
            return abilityDamage;
            break;
            }
        default:
            {
            cout<<"Invalid input.";
            cin>>ability;
            }
    break;
    }

}
}


