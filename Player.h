#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player();
        void setCharacterClass(int classChoice);

		// The following defines the player's starting stats and default values
        std::string name = "Harry";
        std::string characterClass = "Villager";
        int level = 1;
        int experience = 0;
        int health = 10;
        int attack = 3;
        int defence = 3;
        int intelligence = 3;
        int perception = 3;
        int dexterity = 3;
        int classID = 1;  // Use this to reference player class as it is easier to evaluate integers accurately

    protected:

    private:
};

#endif // PLAYER_H
