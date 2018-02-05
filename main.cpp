#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Player
{
    public:
        Player()  // Constructor for player class
        {

        }

        string name;

        // The following defines the player's starting stats
        string characterClass = "Villager";
        int level = 1;
        int health = 10;
        int attack = 3;
        int defence = 3;
        int intelligence = 3;
        int perception = 3;
        int dexterity = 3;
        int classID = 0;  // Use this to reference player class as it is easier to evaluate integers accurately

        void setCharacterClass(int classChoice) // Sets character class based upon player choice
            {
                switch( classChoice )
                {
                case 1:
                    classID = 1;
                    characterClass = "Warrior";
                    health = health + 2;
                    attack = attack + 3;
                    defence = attack + 4;
                    intelligence = intelligence + 1;
                    perception = perception + 1;
                    dexterity = dexterity + 1;
                    break;
                case 2:
                    classID = 2;
                    characterClass = "Rogue";
                    health = health + 1;
                    attack = attack + 3;
                    defence = attack + 2;
                    intelligence = intelligence + 1;
                    perception = perception + 1;
                    dexterity = dexterity + 4;
                    break;
                case 3:
                    classID = 3;
                    characterClass = "Archer";
                    health = health + 1;
                    attack = attack + 3;
                    defence = attack + 1;
                    intelligence = intelligence + 1;
                    perception = perception + 4;
                    dexterity = dexterity + 2;
                    break;
                case 4:
                    classID = 4;
                    characterClass = "Mage";
                    health = health + 1;
                    attack = attack + 1;
                    defence = attack + 1;
                    intelligence = intelligence + 4;
                    perception = perception + 3;
                    dexterity = dexterity + 2;
                    break;
                default:
                    throw invalid_argument( "Received invalid class choice" );
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
};

class Introduction
{
    public:
        Introduction()
        {

        }

        void playerCharacterSetup()
        {
            char answer;
            cout << "Welcome to the game" << endl;
            cout << "Say, I don't know your name, would you tell me it? Y/N" << endl;
            cin >> answer;
        }
};

int main()
{
    Player mainCharacter;
    return 0;
}
