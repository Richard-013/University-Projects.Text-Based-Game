#include <iostream>
#include <string>
using namespace std;

class Item {
    // private:
        string name = "";
        int level = 0;
    
    public:
        string getName();
        void setName(string n);
        int getLevel();
        void levelingUp();
};

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
    level = level + 1;
}

int countItems = 0;
Item items[10];


void addItem(){
    string name;
    cout << "Enter item name:";
    cin >> name;
    items[countItems].setName(name);
    countItems++;
}

void deleteItem(){
    cout << "What item do you want to drop?";
    for (int i = 0; i <countItems; i ++) {
        cout << endl << i + 1 << "-" << items [i] .getName() << endl;
    }
    int num;
    cin >> num;
    int index = num-1;
    
    if (index>=0&&index<countItems) {
        for(int i = index; i < countItems-1; i++) {
            items[i].setName(items[i+1].getName());
        }
        items[countItems-1].setName("");
        countItems--;
    } else {
        cout<<"Empty slot. \n";
    }
}

void levelUpItem(){
    cout << "What item do you want to level up?";
    for (int i = 0; i <countItems; i ++) {
        cout << endl << i + 1 << "-" << items [i] .getName() << endl;
    }
    int num;
    cin >> num;
    int index = num-1;
    
    if (index>=0&&index<countItems) {
        items[index].levelingUp();
    } else {
        cout<<"Empty slot. \n";
    }
}



int main () {
    

    int choice;
    int index;
    
    
    while (true) {
        cout << "Your Inventory:";
        if(countItems==0) cout<<"\nThere are no items in Inventory";
        else
            for (int i = 0; i <countItems; i ++) {
                cout << endl << items[i].getName() << " level: "<< items[i].getLevel()<< endl;
            }
        cout << "\n1: Add item \n";
        cout << "2: Drop item \n";
        cout << "3: Level up some item \n";
        cin >> choice;
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                deleteItem();
                break;
            case 3: 
                 levelUpItem();
                 break;
        }
    }
}
