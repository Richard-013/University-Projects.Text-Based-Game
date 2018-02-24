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


void Mob::showInventory(){
    cout<<"Inventory: "<<endl;
    for(int i = 0; i < 6; i++){
        if(items[i].getName()!=""){
            cout<<i+1<<") "<<items[i].getName()<<endl;
            cout<<"Armor: "<<items[i].getArmor()<<"; ";
            cout<<"Dmg: "<<items[i].getDmg()<<"; ";
            cout<<"Speed: "<<items[i].getSpeed()<<"; ";
            cout<<"HitChance: "<<items[i].getHitChance()<<"; ";
            cout<<"CritChance: "<<items[i].getCritChance()<<"; ";
            cout<<"Range: "<<items[i].getRange()<<"; ";
            cout<<endl;
        } else {
            cout<<"empty slot"<<endl;
        }
    }
}

void Mob::addItem(){
    bool haveSlot = false;
    int slotIndex =-1;
    for(int i = 0; i < 6; i++){
        if(items[i].getName()=="") {
            haveSlot = true;
            slotIndex = i;
            break;
        }
    }
    if(haveSlot){
        showItemsShop();
        cout<<"Enter wich item you want to buy: ";
        int a;
        cin>>a;
        items[slotIndex] = getItemFromShopById(a);
        cout<<endl;
    } else {
        cout<<"You have no empty slot for new items";
    }
    
}

void Mob::deleteItem(){
    showInventory();
    cout<<"Input id of item that should be deleted: ";
    int id;
    cin>>id;
    if (id>=1&&id<=6) {
        items[id-1].itemReset();
        cout<<"Item deleted successfuly"<<endl;
    } else {
         cout<<"Empty slot."<<endl;
    }
}

void Mob::levelUpItem(){
    cout << "What item do you want to level up?";
    for (int i = 0; i <sizeof(items); i ++) {
        cout << endl << i + 1 << "-" << items [i] .getName() << endl;
    }
    int num;
    cin >> num;
    int index = num-1;
    
    if (index>=0&&index<6&&items[index].getName()!="") {
        items[index].levelingUp();
    } else {
        cout<<"Empty slot. \n";
    }
}


void Mob::mobReset(){
    name = "";
    level = 0;
    for(int i = 0; i<6; i++){
        items[i].itemReset();
    }
    armor = 0;
    HP = 0;
    dmg = 10;
    hitChance = 90;
    critChance = 10;
}