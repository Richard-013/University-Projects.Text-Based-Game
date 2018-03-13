#include <iostream>
#include <string>
#include "Mob.h"
using namespace std;

string Mob::getName(){
    return name;
}

void Mob::setName(string n) {
    name = n;
}

int Mob::getLevel(){
    return level;
}

void Mob::levelingUp() {
    level = level + 1;
}

int Mob::getArmor(){
    return armor;
}

void Mob::setArmor(int a){
    armor = a;
}

int Mob::getDmg(){
    return dmg;
}

void Mob::setDmg(int d){
    dmg = d;
}

int Mob::getSpeed(){
    return speed;
}

void Mob::setSpeed(int s){
    speed = s;
}

int Mob::getHitChance(){
    return hitChance;
}

void Mob::setHitChance(int h) {
    hitChance = h;
}

int Mob::getRange(){
    return range;
}

void Mob::setRange(int r){
    range = r;
}
