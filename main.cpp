#include <iostream>
#include <string>
#include "Item.cpp"
#include "DB_Inventory.cpp"
#include "Mob.cpp"

using namespace std;
Mob mobs[10];
int countMobs = 0;
int currentMob = -1;
void getMenuMain(){
    cout << "\n1: Add mob \n";
    cout << "2: Drop mob \n";
    cout << "3: Show mobs \n";
    cout << "4: Choose mob \n";
}

void getMenuMob(){
    cout << "\n1: showInventory \n";
    cout << "2: Add item \n";
    cout << "3: Drop item \n";
    cout << "4: Level up item \n";
    cout << "5: Logout \n";
}

void addMob(){
    string name;
    cout<<"Enter name: ";
    cin>>name;
    mobs[countMobs].setName(name);
    countMobs++;
    cout<<"Mob "<<name<<" added"<<endl;
}

void dropMob(){
    cout<<"Enter id of the mob to delete: ";
    int id;
    cin>>id;
    if(id>=1&&id<=countMobs){
        int index = id -1;
        
        for(int i = index; i<countMobs - 1; i++){
            mobs[i] = mobs[i+1];
        }
        mobs[countMobs-1].mobReset();
        countMobs--;
        cout<<"Mob deleted"<<endl;
    } else {
        cout<<"No mob with that id"<<endl;
    }
}

void showMobs(){
    cout<<"All active Mobs: "<<endl;
    for(int i = 0; i<countMobs; i++){
        cout<<i+1<<") "<<mobs[i].getName()<<endl;
    }
}

void choiceMob(){
    showMobs();
    if(countMobs>0) {
        cout<<"Choose one: ";
        int id;
        cin>>id;
        currentMob = id - 1;
        cout<<mobs[currentMob].getName()<<" choosen"<<endl;
    } else {
        cout<<"No mobs, first add one!"<<endl;
    }
    
}

int main () {
    
    setInventoryShop();
    
    
    while (true) {
        
        
        if(currentMob==-1) {
            getMenuMain();
            int choice1;
            cin >> choice1;
            switch (choice1) {
                case 1:
                    addMob();
                    break;
                case 2:
                    dropMob();
                    break;
                case 3: 
                     showMobs();
                     break;
                case 4: 
                     choiceMob();
                     break;
                default:
                    cout<<"Wrong input"<<endl;
            }
        } else {
            int choice2;
            getMenuMob();
            cin>>choice2;
            switch(choice2){
                case 1:
                    mobs[currentMob].showInventory();
                    break;
                case 2:
                    mobs[currentMob].addItem();
                    break;
                case 3:
                    mobs[currentMob].deleteItem();
                    break;
                case 4:
                    mobs[currentMob].levelUpItem();
                    break;
                case 5:
                    currentMob = -1;
                    break;
            }
            
        }
    }
}