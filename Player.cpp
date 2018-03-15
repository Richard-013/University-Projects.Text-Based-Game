#include "Player.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Player::Player()
{
        // Constructor for Player class
}

void Player::setCharacterClass(int classChoice) // Sets character class based upon player choice
{
    switch( classChoice )  // Switch statement to set character attributes based on their chosen class
    {
        case 1:  // Sets the player as a Warrior
            classID = 1;
            characterClass = "Warrior";
            health = health + 2;
            attack = attack + 3;
            defence = defence + 4;
            intelligence = intelligence + 1;
            perception = perception + 1;
            dexterity = dexterity + 1;
            break;
        case 2:  // Sets the player as a Rogue
            classID = 2;
            characterClass = "Rogue";
            health = health + 1;
            attack = attack + 3;
            defence = defence + 2;
            intelligence = intelligence + 1;
            perception = perception + 1;
            dexterity = dexterity + 4;
            break;
        case 3:  // Sets the player as an Archer
            classID = 3;
            characterClass = "Archer";
            health = health + 1;
            attack = attack + 3;
            defence = defence + 1;
            intelligence = intelligence + 1;
            perception = perception + 4;
            dexterity = dexterity + 2;
            break;
        case 4:  // Sets the player as a Mage
            classID = 4;
            characterClass = "Mage";
            health = health + 1;
            attack = attack + 1;
            defence = defence + 1;
            intelligence = intelligence + 4;
            perception = perception + 3;
            dexterity = dexterity + 2;
            break;
        default:
            throw invalid_argument( "Received invalid class choice" );
    }
}
void Player::gainExperience(int experienceReward) //input is the experience rewarded from quests or battles
{
    cout<<"Good job! You've earned "<<experienceReward<<" experience points."<<endl;//message for the player
    
    string databaseFile = "RPGDatabase.db";

        try
        {
            //getting the experience from database
            sqlite::sqlite db( databaseFile );
            auto cur = db.get_statement();
            cur->set_sql( "SELECT CharacterExperience FROM CharacterData WHERE CharacterID = ?");
            cur->bind(1,characterID)
            cur->prepare();
            cur->step();
            
            experience = cur->get_int(0); //the experience the player already has
            
            //calculating new experience
            experience += experienceReward;
            
            //changing experience from database
            cur->set_sql("UPDATE CharacterData SET CharacterExperience = ? WHERE CharacterID = ?");
            cur->bind(1,experience);
            cur->bind(2,characterID);
            cur->prepare();
            cur->step();
        }
        catch( sqlite::exception e )      // catch all sql issues
        {
            cerr << e.what() << endl;
        }
}

void Player::levelUp() //since the story is linear this can only do so much....
{
    
    cout<<"Congratulations! You leveled up!"<<endl;
    
    string databaseFile = "RPGDatabase.db";

        try
        {
            //getting the level from database
            sqlite::sqlite db( databaseFile );
            auto cur = db.get_statement();
            cur->set_sql( "SELECT CharacterLevel FROM CharacterData WHERE CharacterID = ?");
            cur->bind(1,characterID)
            cur->prepare();
            cur->step();
            level = cur->get_int(0);
            
            //calculating new level            
            level += 1;
     
            cout<<"You are now level "<<level<<"!"<<endl;
            
            //changing level from database
            cur->set_sql("UPDATE CharacterData SET CharacterLevel = ? WHERE CharacterID = ?;");
            cur->bind(1,level);
            cur->bind(2,characterID);
            cur->prepare();
            cur->step();
        }
        catch( sqlite::exception e )      // catch all sql issues
        {
            cerr << e.what() << endl;
        }
}

void Player::raiseStats() //call when player levels up
{
    string databaseFile = "RPGDatabase.db";

        try
        {
            //getting the level from database
            sqlite::sqlite db( databaseFile );
            auto cur = db.get_statement();
            cur->set_sql( "SELECT * FROM CharacterData WHERE CharacterID = ?");
            cur->bind(1,characterID)
            cur->prepare();
            cur->step();
            name = cur->get_text(1);
            classID = cur->get_int(2);
            level = cur->get_int(3);
            health = cur->get_int(5);
            attack = cur->get_int(7);
            defence = cur->get_int(8);
            intelligence = cur->get_int(9);
            perception = cur->get_int(10);
            dexterity = cur->get_int(11);
            
            //calculating new stats
            switch(classID)
            {
                case 1: //warrior
                    {
                    health = health + 2;
                    attack = attack + 3;
                    defence = defence + 4;
                    intelligence = intelligence + 1;
                    perception = perception + 1;
                    dexterity = dexterity + 1;
                    break;
                    }
                case 2: //rogue
                    {
                         health = health + 1;
                         attack = attack + 3;
                         defence = defence + 2;
                         intelligence = intelligence + 1;
                         perception = perception + 1;
                         dexterity = dexterity + 4;
                         break;
                    }
                case 3: //archer
                    {
                         health = health + 1;
                         attack = attack + 3;
                         defence = defence + 1;
                         intelligence = intelligence + 1;
                         perception = perception + 4;
                         dexterity = dexterity + 2;
                         break;
                    }
                case 4: //mage
                    {
                        health = health + 1;
                        attack = attack + 1;
                        defence = defence + 1;
                        intelligence = intelligence + 4;
                        perception = perception + 3;
                        dexterity = dexterity + 2;
                        break;
                    }
                 default:
                        throw invalid_argument( "Received invalid class choice" );
            }
            
            //notifying the player
            cout<<"Updated stats!"<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Attack: "<<attack<<endl;
            cout<<"Defence: "<<defence<<endl;
            cout<<"Intelligence: "<<intelligence<<endl;
            cout<<"Perception: "<<perception<<endl;
            cout<<"Dexterity: "<<dexterity<<endl;
            
            //changing stats in the database
            cur->set_sql("UPDATE CharacterData SET CharacterHealth = ?,CharacterAttack = ?, CharacterDefence = ?, CharacterIntelligence = ?, CharacterPerception =?, CharacterDexterity =? WHERE CharacterID = ?;");
            cur->bind(1,health);
            cur->bind(2,attack);
            cur->bind(3,defence);
            cur->bind(4,intelligence);
            cur->bind(5,perception);
            cur->bind(6,dexterity);            
            cur->prepare();
            cur->step();
        }
        catch( sqlite::exception e )      // catch all sql issues
        {
            cerr << e.what() << endl;
        }
}
/*
// Tests for Player class code
Player mainCharacter;

cout << "Please enter your name: ";
cin >> mainCharacter.name;
cout << "Please choose a class:\n  1 - Warrior\n  2 - Rogue\n  3 - Archer\n  4 - Mage\n  " << endl;
cin >> mainCharacter.classID;
try
{
    mainCharacter.setCharacterClass(mainCharacter.classID);
}
catch( invalid_argument )
{
    mainCharacter.setCharacterClass(1);
    cout << "Invalid choice made, assigning default class of Warrior" << endl;
}
cout << endl << "Name: " << mainCharacter.name << endl;
cout << "Class: " << mainCharacter.characterClass << endl;
cout << "Level: " << mainCharacter.level << endl;
cout << "Health: " << mainCharacter.health << endl;
cout << "Attack: " << mainCharacter.attack << endl;
cout << "Defence: " << mainCharacter.defence << endl;
cout << "Intelligence: " << mainCharacter.intelligence << endl;
cout << "Perception: " << mainCharacter.perception << endl;
cout << "Dexterity: " << mainCharacter.dexterity << endl;
cout << "Character Class ID: " << mainCharacter.classID << endl;
cin.ignore();
*/
