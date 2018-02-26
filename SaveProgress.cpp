#include <iostream>
#include <string>
#include "SaveProgress.h"
#include "Player.h"
#include "../libsqlite.hpp"

using namespace std;

SaveProgress::SaveProgress()
{
    //ctor
}

//void SaveProgress::firstSave(Player playerObj)
void SaveProgress::firstSave()
{
    string databaseFile = "RPGDatabase.db";

    int playerID = assignPlayerID();
    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
        
        cur->set_sql( "INSERT INTO CharacterData (CharacterID, CharacterName, CharacterGender, CharacterClassID, CharacterLevel, CharacterExperience, CharacterHealth, CharacterRemainingHealth, CharacterAttack, CharacterDefence, CharacterIntelligence, CharacterPerception, CharacterDexterity) "
                      "VALUES (1, \"Harry\", 'M', 2, 12, 480, 20, 19, 7, 7, 7, 7, 7);" );
        cur->prepare();
        cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

int SaveProgress::assignPlayerID()
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement(); 

        cur->set_sql( "select count(*) "
                      "from CharacterData" );
        cur->prepare();
        cur->step();

        int playerID = cur->get_int(0);
        playerID =+ 1;
        return playerID;
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void SaveProgress::save(Player playerObj)
{

}
