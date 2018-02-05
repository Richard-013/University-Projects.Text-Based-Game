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
        Introduction()  // Constructor for Introduction class
        {

        }

        string getName()
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

        int chooseClass()
        {
            int answer;
            bool invalidAnswer = true;
            int i = 0;
            do
            {
                if( i == 0 )  // First time player is asked for their name
                {
                    cout << "So, what is it that you do? Are you a:" << endl;
                    cout << "  1 - Warrior\n  2 - Rogue\n  3 - Archer\n  4 - Mage" << endl;
                    cin >> answer;
                    i++;
                }
                else  // Every time after the first that the player is asked for their name
                {
                    cout << "Oh, could you please pick one of the choices I gave you, only there's no other options" << endl;
                    cin >> answer;
                }

                if( answer == 1 || 2 || 3 || 4 )  // Breaks the loop once the user has agreed to give their name
                {
                    invalidAnswer = false;
                }
            } while( invalidAnswer );

            return answer;
        }
};

int main()
{
    Player mainCharacter;
    Introduction intro;
    mainCharacter.name = intro.getName();  // Assigns name taken in Introduction class to the name variable stored in the Player class
    mainCharacter.setCharacterClass(intro.chooseClass());
    return 0;
}
