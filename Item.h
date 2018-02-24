#ifndef practice_Item_h
#define practice_Item_h
#include <string>
using namespace std;
class Item {
    // private:
        string name = "";
        int level = 0;
        int armor = 0;
        int dmg = 0;
        int speed = 0;
        int hitChance = 0;
        int critChance = 0;
        int range = 0;
        
    public:
        string getName();
        void setName(string n);
        int getLevel();
        void levelingUp();
        int getArmor();
        void setArmor(int a);
        int getDmg();
        void setDmg(int d);
        int getSpeed();
        void setSpeed(int s);
        int getHitChance();
        void setHitChance(int h);
        int getCritChance();
        void setCritChance(int h);
        int getRange();
        void setRange(int r);
        void itemReset();
};
#endif