#include <iostream>
#include "Player.h"
#include "Mob.h"


using namespace std;

int skipTurn,abilityDamage,enraged,poisoned;

int abilityUse(Player playerObj.classID)
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


    //grabbing mob info-soon


if(id==1)
{
    cout<<" 1 - Enrage to deal extra "+ bossHP%10 +" damage next turn."<<endl;
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
        extraFromEnrage=bossHP%10;
        break;
        }
    case 2:
        {
        abilityDamage = attack + turn + 0.5*(bossHP%10);
        cout<<"You crushed your enemy with your shield, dealing " + abilityDamage + "."<<endl;
        break;
        }
    case 3:
        {
        abilityDamage = attack + turn + rand()%12;
        cout<<"You've dealt "+abilityDamage+" to all the enemies."<<endl;
        break;
        }
     case default:
        {
        cout<<"Invalid input.";
        continue;
        }
    break;
    }
}
if(id==2)
{
    cout<<" 1 - Backstab"<<endl;
    cout<<" 2 - Shadow Kick"<<endl;
    cout<<" 3 - Fan of Knives -- area of effect damage"<<endl;

    short ability;
    cin>>ability;

    case 1:
        {
        abilityDamage = dexterity + turn + 0.25*(bossHP%50);
        cout<<"You've lurked from the shadows to stab your enemy in the back, dealing "+abilityDamage+" damage and poisoning them for an extra "+bossHP%10+" next turn."<<endl;
        poisoned = 1;
        break;
        }
    case 2:
        {
        abilityDamage = dexterity + turn + rand()%10;
        cout<<"You've kicked your enemy where it hurts the most! You've dealt "+abilityDamage+ " damage."<<endl;
        break;
        }
    case 3:
        {
        abilityDamage = dexterity + turn + rand()%12;
        cout<<"You've dealt "<<abilityDamage<<" to all the enemies."<<endl;
        break;
        }
    case default:
    {
        cout<<"Invalid input.";
        continue;
    }
break;
}
if(id==3)
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
        abilityDamage = perception + rand()%10+extradmg;
        cout<<"You've grabbed your skinning knife and dealt "+abilityDamage+" to the enemy's face."<<endl;
        break;
        }
    case 2:
        {
        abilityDamage = perception + turn + bossHp%5+1+extradmg;
        cout<<"You've hit your enemy in the head dealing "+ abilityDamage + " damage and dizzying it for the next turn."<<endl;
        int skipTurn=1;
        break;
        }
    case 3:
        {
        int abilityDamage = perception + turn + rand()%12+1+extradmg;
        cout<<"You've dealt "<<abilityDamage<<" to all the enemies."<<endl;
        break;
        }
     case default:
        {
        cout<<"Invalid input.";
        continue;
        }
    break;
}
if(id==4)
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
            abilityDamage = intelligence + turn + 0.25*(bossHP%50);
            cout<<"You conjured up a ball of flame that rushed through your enemy dealing "+abilityDamage+" damage."<<endl;
            break;
            }
        case 2:
            {
            cout<<"You've freezed yourself, becoming invulnerable to any damage for the next turn."<<endl;
            int skipTurn=1;
            break;
            }
        case 3:
            {
            int abilityDamage = intelligence + turn + rand()%12;
            cout<<"You've dealt "+ abilityDamage +" to all enemies.";
            break;
            }
        case default:
            {
            cout<<"Invalid input.";
            continue;
            }
    break;
    }

return abilityDamage;
}


