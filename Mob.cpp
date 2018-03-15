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

void Mob::setLevel(int l){
    level = l;
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

int Mob::getHP(){
    return HP;
}

void Mob::setHP(int h){
    HP = h;
} 

int Mob::getCritChance(){
    return critChance;
}

void Mob::setCritChance(int c){
    critChance = c;
}
