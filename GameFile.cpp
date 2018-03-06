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

void gamePart1(Player &playerObj);
void gamePart2(Player &playerObj);
void gamePart3(Player &playerObj);
void gameFinale(Player &playerObj);
void runWholeGame(Player &playerObj);

int main()
{
	bool runGame = true;  // This variable is used to let the player break the game loop and quit the game
	do
	{
		Player playerObj;
		SaveProgress saveProg;

		int answer, loadID;
		bool invalidAnswer = true;

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

			do
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
		catch( const std::invalid_argument& e )
		{
			cout << "You did not make a valid choice, the game will now end" << endl;
		}
		
		if( runGame )
		{
			break;
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
				case 0:
					runWholeGame( playerObj );
					runGame = false;
					break;
				case 1:
					gamePart2( playerObj );
					gamePart3( playerObj );
					gameFinale( playerObj );
					runGame = false;
					break;
				case 2:
					gamePart3( playerObj );
					gameFinale( playerObj );
					runGame = false;
					break;
				case 3:
					gameFinale( playerObj );
					runGame = false;
					break;
				default:
					cout << "No checkpoint data found, beginning game from the start" << endl;
					runWholeGame( playerObj );
					runGame = false;
					break;
			}
		}
	} while( runGame );
	
	return 0;
}

void gamePart1( Player &playerObj )
{
	// Part 1 of the game story
	Introduction intro;
	intro.gameBegin( playerObj );
}

void gamePart2( Player &playerObj )
{
	// Part 2 of the game story
}

void gamePart3( Player &playerObj )
{
	// Part 3 of the game story
}

void gameFinale( Player &playerObj )
{
	// Endgame
}

void runWholeGame(Player &playerObj)
{
	// This function runs the whole game in sequence from the start
	gamePart1(playerObj);
	gamePart2(playerObj);
	gamePart3(playerObj);
	gameFinale(playerObj);
}
