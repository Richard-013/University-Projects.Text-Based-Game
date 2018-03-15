#ifndef practice_Mob_h
#define practice_Mob_h
#include "Item.h"
#include <string>
using namespace std;
class Mob {
    private:
        string name = "";
        int level = 0;
        Item items[6];
        int armor = 0;
        int HP = 30;
        int speed = 0;
        int dmg = 7;
        int hitChance = 90;
        int critChance = 10;
        int range = 0;
    public:
        string getName();
        void setName(string n);
        int getLevel();
        void setLevel(int l);
        void levelingUp();
        int getArmor();
        void setArmor(int a);
        int getHP();
        void setHP(int h);
        int getDmg();
        void setDmg(int d);
        int getSpeed();
        void setSpeed(int s);
        int getHitChance();
        void setHitChance(int h);
        int getRange();
        int getCritChance();
        void setCritChance(int c);
        void setRange(int r);
        void showInventory();
        void addItem();
        void deleteItem();
        void levelUpItem();
        void mobReset();
};

#endif
