#include <iostream>
#include <string>
#include "SaveProgress.h"
#include "Player.h"
#include "libsqlite.hpp"

using namespace std;

SaveProgress::SaveProgress()
{
    //ctor
}

//void SaveProgress::firstSave(Player playerObj)  // Runs when it is the first time the player has saved the game
void SaveProgress::firstSave()
{
    string databaseFile = "RPGDatabase.db";

    int characterID = assignCharacterID();
    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
        
        cur->set_sql( "insert into CharacterData (CharacterID, CharacterName, CharacterClassID, CharacterLevel, CharacterExperience, CharacterHealth, CharacterRemainingHealth, CharacterAttack, CharacterDefence, CharacterIntelligence, CharacterPerception, CharacterDexterity) "
                      "values (4, \"Mary\", 2, 12, 480, 20, 19, 7, 7, 7, 7, 7);" );
        cur->prepare();
		cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

int SaveProgress::assignCharacterID()  // Assigns the player a unique characterID for their save
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

        int characterID = cur->get_int(0);
        characterID =+ 1;
        return characterID;
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void SaveProgress::save(Player playerObj)  // Saves the player's progress (used after the first save)
{
	//Same SQL as firstSave function but without running the assignCharacterID function
}

void SaveProgress::load(Player playerObj, int characterID)  // Allows the player to load their progress from the information stored in the database
{
	//SQL to take player stats from database
}
