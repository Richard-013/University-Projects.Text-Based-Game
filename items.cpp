#include <iostream>
#include <string>
using namespace std;
struct item{
    string name;
};
int main() {
    item items[10];
    for(int i=0; i<10; i++){
        items[i].name= " ";
    }
    int choice;
    int index;
    string name;
    while(true) {
        cout<<"Your Inventory: ";
        for(int i=0; i<10; i++){
            cout<<endl<<items[i].name<<endl;
        }
        cout<<"\n1: Add item\n";
        cout<<"2: Drop item\n";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter item name:";
                cin>>name;
                for(int i=0; i<10; i++){
                    if(items[i].name==" "){
                        items[i].name=name;
                        break;
                    }
                }
                break;
            case 2:
                 cout<<"What items do you want to drop?";
                 for(int i=0; i<10;i++){
                     cout<<endl<<i<<"-"<<items[i].name<<endl;
                 }
                 cin>>index;
                 if(items[index].name==" "){
                     cout<<"Empty slot.\n";
                     break;
                 }
                 items[index].name=" ";
                 break;
          }
    }
}
