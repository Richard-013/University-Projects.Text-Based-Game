#include <iostream>
#include <string>
#include "libsqlite.hpp"
#include "NPC.h"

NPC::NPC()
{
    
    
};

void NPC::setNPCDetails(string name, string zone, string quest, string item)
{
   //cout << "set npc " << name << ", " << zone << endl;
   string databaseFile = "RPGDatabase.db";
    
   try
    {
        sqlite::sqlite db(databaseFile);
        auto cur = db.get_statement();
        cur->set_sql("INSERT INTO NPCData (NAME,ZONE,QUEST,ITEM) VALUES (?,?,?,?) ");
        cur->prepare();
        cur->bind(1,name);
        cur->bind(2,zone);
        cur->bind(3,quest);
        cur->bind(4,item);
        cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
};
void NPC::setNPCHealth(int health, int NPCID) //the npc will basically deal the same amount of dmg each turn
{
    string databaseFile = "RPGDatabase.db";
    try
    {
        sqlite::sqlite db(databaseFile);
        auto cur = db.get_statement();
        cur->set_sql("UPDATE NPCData SET HEALTH = ? WHERE ID = ? ");
        cur->prepare();
        cur->bind(1,health);
        //cur->bind(2,damage);
        cur->bind(2,NPCID);
        cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void NPC::setNPCDamage(int damage, int NPCID) //the npc will basically deal the same amount of dmg each turn
{
    string databaseFile = "RPGDatabase.db";
    try
    {
        sqlite::sqlite db(databaseFile);
        auto cur = db.get_statement();
        cur->set_sql("UPDATE NPCData SET DAMAGE = ? WHERE ID = ? ");
        cur->prepare();
        cur->bind(1,damage);
        //cur->bind(2,damage);
        cur->bind(2,NPCID);
        cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void NPC::setDuelPhrase(string duelPhrase,int NPCID)
{
    string databaseFile = "RPGDatabase.db";
    try
    {
        sqlite::sqlite db(databaseFile);
        auto cur = db.get_statement();
        cur->set_sql("UPDATE NPCData SET DUELPHRASE = ? WHERE ID = ? ");
        cur->prepare();
        cur->bind(1,duelPhrase);
        cur->bind(2,NPCID);
        cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}
void NPC::setBattleReward(string battleReward,int NPCID)
{
    string databaseFile = "RPGDatabase.db";
    try
    {
        sqlite::sqlite db(databaseFile);
        auto cur = db.get_statement();
        cur->set_sql("UPDATE NPCData SET BATTLEREWARD = ? WHERE ID = ? ");
        cur->prepare();
        cur->bind(1,battleReward);
        cur->bind(2,NPCID);
        cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

string NPC::getName(int characterID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, characterID );
		cur->step();
		name = cur->get_text(1);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return name;
}

string NPC::getZone(int characterID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, characterID );
		cur->step();
        zone = cur->get_text(2);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return zone;
}

string NPC::getQuest(int characterID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, characterID );
		cur->step();
        quest = cur->get_text(3);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return quest;
}

string NPC::getItem(int NPCID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, NPCID );
		cur->step();
        item = cur->get_text(4);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return item;
}
string NPC::getDuelPhrase(int NPCID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, NPCID );
		cur->step();
        duelPhrase = cur->get_text(7);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return duelPhrase;
}
string NPC::getBattleReward(int NPCID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, NPCID );
		cur->step();
        battleReward = cur->get_text(8);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return battleReward;
}
int NPC::getHealth(int NPCID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, NPCID );
		cur->step();
        health = cur->get_int(5);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return health;
}
int NPC::getDamage(int NPCID)
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM NPCData WHERE ID = ?");
		cur->prepare();
		cur->bind( 1, NPCID );
		cur->step();
        damage = cur->get_int(6);
     }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
    return damage;
}

string NPC::NPCmeeting(int NPCID)
{
    name = getName(NPCID);
    zone = getZone(NPCID);
    quest = getQuest(NPCID);
    item = getItem(NPCID);
    duelPhrase = getDuelPhrase(NPCID);
    battleReward = getBattleReward(NPCID);
    
   
    meetingMessage = "You're wondering through the "+zone+" zone. You've met "+name+ ".";
    meetingMessage +="\nHealth: "+to_string(health)+"\nDamage: "+to_string(damage);
    meetingMessage +="\nYou can either:\n(1)Quest!\n(2)Battle!\n(3)Check Out Items!\n";
    
    return meetingMessage;
}
void NPC::NPCmeetingChoice(int MOBID)//always after NPCmeeting
{
    short answer;
    cin>>answer;
    
    switch(answer)
    {
        case 1:
            //run quest function for particular npc
        case 2:
        {
            string databaseFile = "RPGDatabase.db";
            //joining NPCData with Mobs database
            try
            {
                sqlite::sqlite db(databaseFile);
                auto cur = db.get_statement();
                cur->set_sql("SELECT NPCData.NAME, NPCData.DUELPHRASE, NPCData.BATTLEREWARD, Mobs.HP, Mobs.Armor, Mobs.Damage FROM NPCData LEFT JOIN Mobs ON Mobs.MobID=NPCData.MOBID WHERE NPCData.MOBID = ?;");
                cur->bind(1,MOBID);
                cur->prepare();
                cur->step();
                name = cur->get_text(0);
                duelPhrase = cur->get_text(1);
                battleReward = cur->get_text(2);
                health = cur->get_int(3);
                armor = cur->get_int(4);
                damage = cur->get_int(5);
            }
            catch( sqlite::exception e )      // catch all sql issues
            {
                cerr << e.what() << endl;
            }
            cout<<name<<": "<<duelPhrase<<endl;
            cout<<"IF you win, you shall be granted "<<battleReward<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Armor: "<<armor<<endl;
            cout<<"Damage: "<<damage<<endl;
            
            /*
            Battle bt;
            Player testguy;
            Mob badguy;
            Item sword;
            bt.battle(testguy, badguy, sword);
            */
        }
            case 3:
            {
                cout<<"The items are: "<<endl;
                cout<<getItem(int NPCID);
                break;
            }
        
    }
    
}



