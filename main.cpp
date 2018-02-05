#include <iostream>
#include <string>
#include <stdexcept>
#include "Player.h"
#include "Introduction.h"

using namespace std;

int main()
{
    Player mainCharacter;
    Introduction intro;
    mainCharacter.name = intro.getName();  // Assigns name taken in Introduction class to the name variable stored in the Player class
    mainCharacter.gender = intro.chooseGender(mainCharacter.name);  // Assigns chosen gender to the attribute in the Player class
    mainCharacter.setCharacterClass(intro.chooseClass());  // Takes the choice made by the player and sets their class and stats
    return 0;
}
