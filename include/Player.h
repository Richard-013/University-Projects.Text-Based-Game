#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player();
        void setCharacterClass(int classChoice);

        std::string name;
        // The following defines the player's starting stats
        std::string characterClass = "Villager";
        int gender;  // Gender: 1 is male, 2 is female
        int level = 1;
        int experience = 0;
        int health = 10;
        int attack = 3;
        int defence = 3;
        int intelligence = 3;
        int perception = 3;
        int dexterity = 3;
        int classID = 0;  // Use this to reference player class as it is easier to evaluate integers accurately

    protected:

    private:
};

#endif // PLAYER_H
