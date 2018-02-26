#include "Introduction.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Introduction::Introduction()
{
    // Constructor for Introduction class
}

void Introduction::gameBegin()  // Starts the game/introduction sequence
{
    cout << "You awake with a sore back after a restless night of sleep in your uncomfortable bed." << endl;
    cout << "You pull yourself out of the bed with some effort, trying to stretch out the aches" << endl;
    cout << "left behind by the slowly breaking wooden slats of your bed." << endl;

    cout << "\nThe fresh spring air rushes to greet you as you toss away the sheets of your bed," << endl;
    cout << "it still carries a slight chill this early in the morning but after years of farm" << endl;
    cout << "work you are more than used to it. You pull on your clothes and prepare yourself for" << endl;
    cout << "your last day off before the farm began work again." << endl;

    cout << "\nYou wander out of the small home you share with your fellow farm-hands and into the" << endl;
    cout << "town. Despite the early hour, people were already busying themselves about the town," << endl;
    cout << "setting up market stalls, hanging clothes to dry, and just about anything else that" << endl;
    cout << "townspeople did. You greet familiar faces as you walk down the dirt road that leads" << endl;
    cout << "to the centre of the village." << endl;
}

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
            cout << "Oh, I don't really see why not, would you please tell me your name? Y/N" << endl;
            cin >> answer;
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


int Introduction::chooseGender(string name)  // Allows the player to choose their gender
{
    int answer;
    bool invalidAnswer = true;
    int i = 0;
    do
    {
        if( i == 0 )  // First time player is asked for their gender
        {
            cout << "Ah, so, " + name + ", are you a:" << endl;
            cout << "  1 - Boy\n  2 - Girl" << endl;
            cin >> answer;
            i++;
        }
        else  // Every time after the first that the player is asked for their gender
        {
            cout << "Oh, could you please pick one of the choices I gave you" << endl;
            cin >> answer;
        }

        if( answer == 1 || answer == 2 )  // Breaks the loop once the user has agreed to give their gender
        {
            invalidAnswer = false;
        }
    } while( invalidAnswer );

    return answer;
}


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
