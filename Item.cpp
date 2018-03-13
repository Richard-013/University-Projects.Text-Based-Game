#include <iostream>

#include "Item.h"
using namespace std;

string Item::getName(){
    return name;
}

void Item::setName(string n) {
    name = n;
}

int Item::getLevel(){
    return level;
}

void Item::levelingUp() {
    armor *= 1.5;
    hitChance *= 1.5;
    critChance *= 1.5;
    dmg *= 1.5;
    level = level + 1;
}

int Item::getArmor(){
    return armor;
}
void Item::setArmor(int a){
    armor = a;
}
int Item::getDmg(){
    return dmg;
}
void Item::setDmg(int d){
    dmg = d;
}
