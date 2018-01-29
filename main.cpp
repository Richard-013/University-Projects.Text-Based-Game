#include <iostream>
#include <stdexcept>

using namespace std;

class Player
{
    public:
        int setCharacterClass(int classChoice)
        {
            switch( classChoice )
            {
            case 1:
                classID = 1;
                characterClass = "Warrior";
                break;
            case 2:
                classID = 2;
                characterClass = "Rogue";
                break;
            case 3:
                classID = 3;
                characterClass = "Archer";
                break;
            case 4:
                classID = 4;
                characterClass = "Mage";
                break;
            default:
                throw invalid_argument( "Received invalid class choice" );
            }
        }

        string name;
        string characterClass = "Villager";
        int level = 1;
        int health = 10;
        int attack = 3;
        int defence = 3;
        int intelligence = 3;
        int perception = 3;
        int dexterity = 3;
        int classID = 0;

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
        */
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
