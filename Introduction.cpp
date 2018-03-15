#include "Introduction.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Richard
Introduction::Introduction()
{
    // Constructor for Introduction class
}

// Richard
void Introduction::characterCreation(Player &playerObj)  // Starts the introduction sequence
{
	// Character Creation
	playerObj.name = chooseName();  // Takes the player through choosing their character's name
	playerObj.classID = chooseClass();  // Takes the player through choosing their own class
	try
	{
		playerObj.setCharacterClass(playerObj.classID);  // Sets the player's stats after they have chosen a class
	}
	catch( invalid_argument )
	{
		playerObj.setCharacterClass(1);  // Assigns a character the default class if an error occurs with class assignment
		cout << "Invalid choice made, assigning default class of Warrior" << endl;
	}
}

// Richard
string Introduction::chooseName()  // Allows the player to choose their own name
{
    char answer;
    string name;
    bool invalidAnswer = true;
    int i = 0;
    do
    {
        if( i == 0 )  // First time player is asked for their name
        {
            cout << "Welcome to the game" << endl;
            cout << "Say, I don't know your name, would you tell me it? Y/N" << endl;
            cin >> answer;
            i++;
        }
        else  // Every time after the first that the player is asked for their name
        {
			cout << "Oh, I don't really see why not, would you ";
			for( int count = 1; count <= i; count++ )
			{
				cout << "please ";
			}
			cout << "tell me your name? Y/N" << endl;
            cin >> answer;
			i++;
        }

        if( answer == 'y' || answer == 'Y')  // Breaks the loop once the user has agreed to give their name
        {
            invalidAnswer = false;
        }
    } while( invalidAnswer );

    cout << "Why thank you, so do tell me, what is your name?" << endl;
    cin >> name;  // Takes the player's name

    return name;  // Returns name so that it can be transferred into the Player class
}

// Richard
int Introduction::chooseClass()  // Allows the player to choose their class
{
    int answer;
    bool invalidAnswer = true;
    int i = 0;
    do
    {
        if( i == 0 )  // First time player is asked for their class
        {
            cout << "And what is it that you do again? Are you a:" << endl;
            cout << "  1 - Warrior\n  2 - Rogue\n  3 - Archer\n  4 - Mage" << endl;
            cin >> answer;
            i++;
        }
        else  // Every time after the first that the player is asked for their class
        {
            cout << "Oh, could you please pick one of the choices I gave you, only there's no other options" << endl;
            cin >> answer;
        }

        if( answer == 1 || answer == 2 || answer == 3 || answer == 4 )  // Breaks the loop once the user has agreed to give their class
        {
            invalidAnswer = false;
        }
    } while( invalidAnswer );

    return answer;
}
