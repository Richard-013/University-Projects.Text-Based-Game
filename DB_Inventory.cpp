#include <iostream>

using namespace std;

Item inventoryShop[6];
void setInventoryShop() {
    inventoryShop[0].setName("Vanguard");
    inventoryShop[0].setArmor(20);
    inventoryShop[0].setDmg(0);
    inventoryShop[0].setSpeed(0);
    inventoryShop[0].setHitChance(0);
    inventoryShop[0].setRange(0);
    
    inventoryShop[1].setName("Cheinmail");
    inventoryShop[1].setArmor(5);
    inventoryShop[1].setDmg(0);
    inventoryShop[1].setSpeed(0);
    inventoryShop[1].setHitChance(0);
    inventoryShop[1].setRange(0);
    
    inventoryShop[2].setName("Platmail");
    inventoryShop[2].setArmor(15);
    inventoryShop[2].setDmg(0);
    inventoryShop[2].setSpeed(0);
    inventoryShop[2].setHitChance(0);
    inventoryShop[2].setRange(0);
    
    inventoryShop[3].setName("Weapon Baterfly");
    inventoryShop[3].setArmor(0);
    inventoryShop[3].setDmg(60);
    inventoryShop[3].setSpeed(0);
    inventoryShop[3].setHitChance(95);
    inventoryShop[3].setRange(400);
    
    inventoryShop[4].setName("Weapon Crystalis");
    inventoryShop[4].setArmor(0);
    inventoryShop[4].setDmg(40);
    inventoryShop[4].setSpeed(0);
    inventoryShop[4].setHitChance(90);
    inventoryShop[4].setCritChance(30);
    inventoryShop[4].setRange(400);
    
    inventoryShop[5].setName("Weapon Desolator");
    inventoryShop[5].setArmor(0);
    inventoryShop[5].setDmg(60);
    inventoryShop[5].setSpeed(0);
    inventoryShop[5].setHitChance(100);
    inventoryShop[5].setCritChance(0);
    inventoryShop[5].setRange(500);
}
void showItemsShop(){
    cout<<"Total number of items in Shop: "<<sizeof(inventoryShop)<<endl;
    cout<<"Items: "<<endl;
    for(int i = 0; i < 6; i++){
        cout<<i+1<<") "<<inventoryShop[i].getName()<<endl;
        cout<<"Armor: "<<inventoryShop[i].getArmor()<<"; ";
        cout<<"Dmg: "<<inventoryShop[i].getDmg()<<"; ";
        cout<<"Speed: "<<inventoryShop[i].getSpeed()<<"; ";
        cout<<"HitChance: "<<inventoryShop[i].getHitChance()<<"; ";
        cout<<"CritChance: "<<inventoryShop[i].getCritChance()<<"; ";
        cout<<"Range: "<<inventoryShop[i].getRange()<<"; ";
        cout<<endl;
    }
}

Item getItemFromShopById(int id){
    return inventoryShop[id-1];
}