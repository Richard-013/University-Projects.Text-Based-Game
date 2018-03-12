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

void SaveProgress::firstSave(Player &playerObj)  // Runs when it is the first time the player has saved the game
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
		cur->bind( 6, playerObj.remainingHealth );
		cur->bind( 7, playerObj.attack );
		cur->bind( 8, playerObj.defence );
		cur->bind( 9, playerObj.intelligence );
		cur->bind( 10, playerObj.perception );
		cur->bind( 11, playerObj.dexterity );
		cur->step();

		setCharacterID( playerObj );
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void SaveProgress::setCharacterID(Player &playerObj)
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

void SaveProgress::save(Player &playerObj)  // Saves the player's progress (used after the first save)
{
	string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "UPDATE CharacterData SET CharacterClassID = ?, CharacterLevel = ?, CharacterExperience = ?, CharacterHealth = ?, CharacterRemainingHealth = ?, CharacterAttack = ?, CharacterDefence = ?, CharacterIntelligence = ?, CharacterPerception = ?, CharacterDexterity = ? WHERE CharacterID = ?;");
		cur->prepare();
		cur->bind( 1, playerObj.classID );
		cur->bind( 2, playerObj.level );
		cur->bind( 3, playerObj.experience );
		cur->bind( 4, playerObj.health );
		cur->bind( 5, playerObj.remainingHealth );
		cur->bind( 6, playerObj.attack );
		cur->bind( 7, playerObj.defence );
		cur->bind( 8, playerObj.intelligence );
		cur->bind( 9, playerObj.perception );
		cur->bind( 10, playerObj.dexterity );
		cur->bind( 11, playerObj.characterID );
		cur->step();
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

void SaveProgress::load(Player &playerObj, int characterID)  // Allows the player to load their progress from the information stored in the database
{
	string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM CharacterData WHERE CharacterID = ?");
		cur->prepare();
		cur->bind( 1, characterID );
		cur->step();
		
		string name = cur->get_text(2);
        playerObj.level = cur->get_int(4);
        playerObj.experience = cur->get_int(5);
        playerObj.health = cur->get_int(6);
		playerObj.remainingHealth = cur->get_int(7);
        playerObj.attack = cur->get_int(8);
        playerObj.defence = cur->get_int(9);
        playerObj.intelligence = cur->get_int(10);
        playerObj.perception = cur->get_int(11);
        playerObj.dexterity = cur->get_int(12);
        playerObj.classID = cur->get_int(3);
		playerObj.characterID = cur->get_int(1);
		
		playerObj.checkpoint = loadWorldState( characterID );
		switch( playerObj.classID )
		{
			case 1:
				playerObj.characterClass = "Warrior";
				break;
			case 2:
				playerObj.characterClass = "Rogue";
				break;
			case 3:
				playerObj.characterClass = "Archer";
				break;
			case 4:
				playerObj.characterClass = "Mage";
				break;
			default:
				playerObj.characterClass = "Villager";
		}
		string characterClass = "Villager"; // Make if statement	
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}

int SaveProgress::loadWorldState(int characterID)
{
	string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM WorldState WHERE CharacterID = ?");
		cur->prepare();
		cur->bind( 1, characterID );
		cur->step();
		
		int checkpoint = cur->get_int(3);
		return checkpoint;
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}