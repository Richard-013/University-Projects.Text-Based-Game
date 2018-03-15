#include <iostream>
#include "Quests.h"
#include "Quests.cpp"
//#include <string>

using namespace std;

Quests QuestsOne;

void ClothingStore();
void MagicVillage();
void quest1();
int input;

void quest1() 

{
 cout << "Congratiulation! You have purchased a new item from Clothing Store." << endl;
    cout << "\n ";
    //system("pause");

    QuestsOne.insertDetails ("Clothing",1 ,"Nothing",10);
}  
  

void ClothingStore() {
        //system("cls");
        cout << "\n The commands here are (1.buyglasses),(2.clothes),(3.buyhat)." << endl;
        cout << "\n 1. buyglasses" << endl;
        cout << "\n 2. clothes" << endl;
        cout << "\n 3. buyhat" << endl;
        cout << "\n 4. I don't want any of these";
        cout << "\n ";
        cin >> input;
      
        switch (input) {

            case 1: case 2: case 3:
            
           
            quest1();
            break;

            case 4:
            system("cls");
            cout << "\n If you don't want one of these, it's ok." << endl;
            cout << endl ;
            //system("pause");
      }}


void MagicVillage() {

    //system("cls");
    cout << "\n You are in the Magic viillage. Where would you like to do first?" << endl;
    cout << "\n 1. Clothing Store" << endl;
    cout << "\n 2. Hospital" << endl;
    cout << "\n 3. Get a fightstyle and then go to Race Arena" << endl;
    cout << "\n 4. Magic Forest" << endl;

    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        ClothingStore();
         
        case 2:
        break;
       //quest2();

    }   
}



int main()
{//srand (time(NULL));
  

    //system("cls");
    cout << "\n Welcome to RPG!" << endl;
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        cout<< "Quest adventure began" << endl;
        cout << "Spawn in the MagicVillage" << endl;
        //questUpdate();
        MagicVillage();

        case 2:
        return EXIT_SUCCESS;}}