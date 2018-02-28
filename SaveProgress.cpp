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

void SaveProgress::firstSave(Player playerObj)  // Runs when it is the first time the player has saved the game
{
    string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "INSERT INTO CharacterData ( CharacterName, CharacterClassID, CharacterLevel, CharacterExperience, CharacterHealth, CharacterRemainingHealth, CharacterAttack, CharacterDefence, CharacterIntelligence, CharacterPerception, CharacterDexterity) "
                      "VALUES ( ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? );" );
		cur->prepare();
		cur->bind( 1, playerObj.name );
		cur->bind( 2, playerObj.classID );
		cur->bind( 3, playerObj.level );
		cur->bind( 4, playerObj.experience );
		cur->bind( 5, playerObj.health );
		cur->bind( 6, playerObj.health );
		cur->bind( 7, playerObj.attack );
		cur->bind( 8, playerObj.defence );
		cur->bind( 9, playerObj.intelligence );
		cur->bind( 10, playerObj.perception );
		cur->bind( 11, playerObj.dexterity );
		cur->step();

		setCharacterID(playerObj);
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void SaveProgress::setCharacterID(Player playerObj)
{

	string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT MAX(CharacterID) "
					  "FROM CharacterData ");
		cur->prepare();
		cur->step();
		playerObj.characterID = cur->get_int(0);
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
