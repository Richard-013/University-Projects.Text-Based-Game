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
    hitChance *=1.5;
    critChance *=1.5;
    dmg*=1.5;
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
int Item::getSpeed(){
    return speed;
}
void Item::setSpeed(int s){
    speed = s;
}
int Item::getHitChance(){
    return hitChance;
}
void Item::setHitChance(int h) {
    hitChance = h;
}

int Item::getCritChance(){
    return hitChance;
}
void Item::setCritChance(int c) {
    critChance = c;
}

int Item::getRange(){
    return range;
}
void Item::setRange(int r){
    range = r;
}

void Item::itemReset(){
    name = "";
    level = 0;
    armor = 0;
    dmg = 0;
    speed = 0;
    hitChance = 0;
    critChance = 0;
    range = 0;
}