#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player();
        void setCharacterClass(int classChoice);

		// The following defines the player's starting stats and default values
        std::string name = "Terry";
        std::string characterClass = "Villager";
        int level = 1;
        int experience = 0;
        int health = 10;
		int remainingHealth = health;
        int attack = 3;
        int defence = 3;
        int intelligence = 3;
        int perception = 3;
        int dexterity = 3;
        int classID = 0;  // Use this to reference player class as it is easier to evaluate integers accurately
						  // 0 is a villager, 1 is a warrior, 2 is a rogue, 3 is an archer, 4 is a mage, anything else is not valid
		int characterID;
		int checkpoint;

    protected:

    private:
};

#endif // PLAYER_H
