#include <iostream>
#include <stdexcept>
#include "libsqlite.hpp"
//#include "battle.h"
#include "Introduction.h"
//#include "Item.h"
//#include "Mob.h"
#include "Player.h"
#include "SaveProgress.h"

using namespace std;

// Declarations of functions, definitions are below main()
void gameStart(Player &playerObj);
void gameFinale(Player &playerObj);
void runWholeGame(Player &playerObj);
void wantToSave(Player &playerObj);

int main()  // Main function that runs the game
{
	bool runGame = true;  // This variable is used to let the player break the game loop and quit the game
	do
	{
		Player playerObj;
		SaveProgress saveProg;

		int answer, loadID;
		bool invalidAnswer = true;  // This variable is used to run loops that check for valid input

		// Title Screen
		cout << "################################################################" << endl;
		cout << "#                                                              #" << endl;
		cout << "#                           Generica                           #" << endl;
		cout << "#                                                              #" << endl;
		cout << "################################################################" << endl << endl << endl;

		try
		{
			// Menu
			cout << "Welcome to Generica, the generic RPG game" << endl;
			cout << "Would you like to start a new game or load a previous save?" << endl;
			cout << "    1 - Start a new game" << endl;
			cout << "    2 - Load a previous save" << endl;
			cout << "    3 - Exit the game" << endl;

			do  // Do-While loop to take input and check its validity
			{
				cin >> answer;
				if( answer == 1 || answer == 2 || answer == 3 )
				{
					invalidAnswer = false;
				}
			} while( invalidAnswer );

			if( answer == 1 )
			{
				// If the player starts a new game then this will launch the whole game from the start
				runWholeGame( playerObj );
			}
			else if( answer == 2 )
			{
				// Loads player data
				cout << "What is the ID of the character?" << endl;
				cin >> loadID;
				playerObj.firstTimeSaving = false;
				saveProg.load(playerObj, loadID);
			}
			else if( answer == 3 )
			{
				// This sets the runGame variable to false so the game know's to exit after this if-statement
				runGame = false;
			}
			else
			{
				// Error occurs if the player manages to make an invalid choice
				throw std::invalid_argument( "Received invalid selection" );
			}
		}
		catch( const std::invalid_argument& e )  // Catches any invalid choices given by the player as an error
		{
			cout << "You did not make a valid choice, the game will now end" << endl;
		}
		
		if( playerObj.checkpoint == 4 )
		{
			cout << "This character has already completed the game" << endl;
			cout << "Please begin angain to select a new character" << endl;
			cout << "Press enter to restart the game" << endl;

			cin.ignore();
			continue;
		}
		else
		{
			switch( playerObj.checkpoint )
			{
				case 0:  // Runs the entire game from the beginning as the player has not made any progress
					runWholeGame( playerObj );
					runGame = false;
					break;
				case 1:  // Runs the game from part 2
					gameStart( playerObj );
					gameFinale( playerObj );
					runGame = false;
					break;
				case 2:  // Runs the game from part 3
					gameFinale( playerObj );
					runGame = false;
					break;
				default:  // Runs the game from the beginning if there is no checkpoint saved
					cout << "No checkpoint data found, beginning game from the start" << endl;
					runWholeGame( playerObj );
					runGame = false;
					break;
			}
		}
	} while( runGame );
	
	return 0;
}

void gameStart( Player &playerObj )
{
	// Part 1 of the game story
	playerObj.checkpoint = 0;  // Sets the player's progress marker as 0 i.e. the start of the game
	Introduction intro;
	intro.characterCreation( playerObj );
	wantToSave( playerObj );
}

void gameFinale( Player &playerObj )
{
	// Endgame
	playerObj.checkpoint = 3;  // Sets the player's progress marker as 3, so they hav completed most the game
	// Finale code here
	playerObj.checkpoint = 4;  // Sets the player's progress marker as 4, they have completed the game
	wantToSave( playerObj );
}

void runWholeGame(Player &playerObj)
{
	// This function runs the whole game in sequence from the start
	gameStart(playerObj);
	gameFinale(playerObj);
}

void wantToSave(Player &playerObj)
{
	SaveProgress saveProg;
	int answer;
	bool invalidAnswer = true;
	do
	{
		cout << "Would you like to save your progress?" << endl;
		cout << "    1 - Yes\n    2 - No" << endl;
		cin >> answer;
		
		if( answer == 1 || answer == 2 )
		{
			invalidAnswer = false;
		}
	} while( invalidAnswer );
	
	if( answer == 1 && playerObj.firstTimeSaving )
	{
		saveProg.firstSave( playerObj );
		cout << endl << "Your characterID is " << playerObj.characterID << endl;
		cout << "Please remember this in order to load your progress at a later date" << endl;
	}
	else if( answer == 1 && playerObj.firstTimeSaving != true )
	{
		saveProg.save( playerObj );
	}
}
