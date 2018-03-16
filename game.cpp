#include <iostream>
#include "Quests.h"
#include "Quests.cpp"
#include "libsqlite.hpp"
#include <string>
using namespace std;
string qUpdates;
int input;
void quest1();
void quest2();
void quest3();
void end();
void ClothingStore();
void MagicVillage();
void RaceArena();
void MagicForest();
void Hospital();
void Lake();
void Fishing();
void Sailing();
void collectFlour();
void StripCow();
void DirtyWork();
Quests QuestsOne;

void RaceArena () {
  
  cout << "\n I am Bully and I have a new quest for you!" << endl;
  cout << "\n Fight me! If you will win, I'll be given you the Black Belt"<< endl;
  //battle
  cout << "***Congratiulations! You won a black belt and 10 points."<< endl;
  QuestsOne.insertDetails ("RaceArena","BlackBelt",10);
}
void ClothingStore() {
       
        cout << "\n The commands here are (1.buyglasses),(2.clothes),(3.buyhat)." << endl;
        cout << "\n 1. buyglasses" << endl;
        cout << "\n 2. clothes" << endl;
        cout << "\n 3. buyhat" << endl;
        cout << "\n 4. I don't want any of these";
        cout << "\n ";
        cin >> input;
      
        switch (input) {

            case 1: case 2: case 3:
            
            { quest1 ();
            qUpdates = "Quest updated";
            //questUpdate1();
            quest2;
            break;}
      
            case 4;
            cout << "\n If you don't want one of these, it's ok." << endl;
            cout << endl ;
         
      }}

void quest2() {

    //system("cls");
    cout << "\n Now I have a recommendation for you.." << endl;
    cout << "\n You should go to the Race Arena. " << endl;
    cout << "\n But firstly, you should go to the Gym and learn a new fighstyle." << endl;
    cout << "\n ";
  

   
    cout << "\n 1. Okay, I will go to the Gym firstly and then to the Race Arena. " << endl;
    cout << "\n 2. I don't think I'm the right person for this. I don't like sport." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
       
        
        cout << "\n Wish you have fun!" << endl;
        cout << "\n ";
        qUpdates = "Quest updated";
      
        RaceArena();
        Hospital();
        break;

        case 2:
       
        cout << "\n You should then go to the hospital. Someone is waiting for you!" << endl;
        cout << "\n ";
     
        Hospital();}
}


void MagicVillage() {

    //system("cls");
    cout << "\n You are in the Magic viillage. The first quest is to go to ClothingStore" << endl;
    cout << "\n 1. Ok go there." << endl;
    cout << "\n ";
    cin >> input;
    switch (input) {

        case 1:
        ClothingStore();
        break;
        
        case 2:
        cout << "Ok then if you don't want." << endl;
        quest2();

    }   
}
 void LastFight () 
 {
   cout << "\n I think that you have waited so much for this!" << endl;
   cout << "\n You were really brave!" << endl;
   cout << "\n You have done the quests and have the fight with the mobs!..." << endl;
   cout << "\n Now is the last turn. You will win or you will lose?" << endl;
   //the last battle
 }


void DirtyWork() {
  cout <<"\n I can see that you have muscles " << endl;
  cout << "\n Thank you for helping me with all of these" << endl;
  cout <<"\n ***Congratiulations! Now you have the Shovel. Good luck with your fight!***"<< endl;
QuestsOne.insertDetails ("Dirty Work", "shovel",20);
LastFight();
}
 void collectFlour() {
  
  cout << "\n Now you should work with the tractor to give me some flour." << endl;
  cout << "\n Working on this..." << endl;
  cout << "\n Thank you! I don't have so much money, but I can give you 2 bags of flour!"<< endl;
  QuestsOne.insertDetails ("CollectFlour", "bags of flour",40);
   cout << "\n Wish you the best! " << endl;
  cout << "\n Be careful. ";
  cout << endl;
  cout << "\n Now, would you like to go have the last fight?" << endl;
  cout << "\n Or do dirty work in order to win a Shovel?"<< endl;
   cout << "\n 1. Yes, sure! That's why I started that game" << endl;
  cout << "\n 2. No, I prefer to get the shovel to fight with dragon." << endl;
  cin>> input;
   
  switch (input) 
  { case 1: 
    LastFight();
   break;
    case 2 : 
   DirtyWork();}
}

void StripCow () {
   
  cout << " \n Hi ya! Do you like the atmosfere here at the farm? "<< endl;
   cout << "\n Guess yes! I am Bob the farmer and I'll give you some quests." << endl;
   cout << "\n First, could you help me strip the cow? " << endl;
   cout << "\n Oh thanks, I knew you are a good boy." << endl;
   cout << "\n *** Congratiulations! Here is milk for you to have more calcium***" <<endl;
  QuestsOne.insertDetails ("Strip the cow", "milk",30);
  cout << endl;
  
   collectFlour();

}

void MobsVillage () {
  cout << "\n Oups! It looks like you have been fooled. " << endl;
  cout << "\n The camel took you here. " << endl;
  cout << "\n It's a dangerous place!" << endl;
  cout << "\n Now you need to have some fights with the mobs to can continue your adventure"<< endl;

  //fightig with mobs
  
  cout << "Well done! Here is your reward and good luck for the other quests." << endl;
  cout << "\n ***Congratiulations! You won a new life!" << endl;
  QuestsOne.insertDetails ("Fight with Mobs", "new life",500);
  cout << "\n Now you are going to Bob, my friend." << endl;
  
  StripCow();
}

void Hospital() {
    //system("cls");
    cout << "\n Hello! I am Greg. Can you help me with something?" << endl;
    cout << "\n I will recompense you with a talisman." << endl;
    cout << "\n With it you can respawn in the Hospital to get healed any time." << endl;
    //system("pause");

    //system("cls");
    cout << "\n There, in the magic forest, is a tree which has magic wood." << endl;
    cout << "\n I need a piece of that wood to treat my ill daughter." << endl;
    cout << "\n She has not much time remaining. Tell me. You can help?" << endl;
    //system("pause");

    //system("cls");
    cout << "\n 1. Yes, sure, I will help you right now." << endl;
    cout << "\n 2. Sorry, I don't think I can help you. Maybe later." << endl;
    cin >> input;

    switch (input) {

        case 1:
        //system("cls");
        cout << "\n I will teleport you in the forest right now." << endl;
        cout << "\n";
        
        MagicForest();
        
        
        case 2:
        //system ("cls");
        cout << "\n But please, I beg you. Mary, my girl, really needs that." << endl;
        cout << "\n Okay, I will try to help you with this." << endl;
        cout << endl;
        
        MagicForest();
    }
}
  void Camel () {
   cout << " \n You look a lot like loving to ride camels! " << endl;
   cout << " \n This is true, right ?" << endl;
   cout << " \n Here is my best friend, the Camel Dorry." << endl;
   cout << " \n If you would like to have a walk around the dessert it will be my pleasure!" << endl;
   cout << " \n Just having a good time.... ";
  QuestsOne.insertDetails ("Camel", "Fool",0);
    cout << endl;
   MobsVillage();
}

void  MagicBee()
 { 
  cout << "\n Hey you! You are really brave!" << endl;
  cout << "\n Could you help me with something from the magic bee" << endl;
  cout << "\n I saw here in the forect and I am too old to beat this monster" << endl;
  cout << "It's about that gigant bee.. here in the forest " << endl;
  cout << endl;
 
  
  cout << "I need to have some honey from her beehive." << endl;
  cout << "\n This will help me to regain my strength" << endl;
  cout << "\n 1. Sure I can help you." << endl;
  cout << "\n 2. No, I want to go in the desert " << endl;
  cout << endl;
  cin>> input ;
   
   switch (input ) {
     case 1:
       cout << "\n You are now searching for that bee..."<< endl;
       cout << "\n Oh! Look, just there!" << endl;
       cout << "\n It looks like a treasure. You should try the key that you have" << endl;
       cout << "\n Trying to unlock it with the key..." << endl;
       cout << "\n ***Oh! You now have a toxic spray and can go for the magic honey***" << endl;
       cout << "\n Well done!";
       QuestsOne.insertDetails ("MagicBee", "honey",50);
       cout << endl;
       Camel();
   
   case 2:
       cout << "But please...I really need that. " << endl;
       cout << "\n You are now searching for that bee..."<< endl;
       cout << "\n Oh! Look, just there!" << endl;
       cout << "\n It looks like a treasure. You should try the key that you have" << endl;
       cout << "\n Trying to unlock it with the key..." << endl;
       cout << "\n Oh! You now have a toxic spray and can go for the magic honey" << endl;
       cout << "\n Well done!";
       cout << endl;
      Camel();
   }
}
 
  void Fishing () 
  {
    //system("cls");
    cout << "\n You're now fishing.";
      
      cout << "\n Oh, look!*** Congratiulations! You caught a golden fish!***" << endl;
      cout << "\n This will help you with health in your battle" << endl;
      cout << "\n with the dragon if you will do the quests until" << endl;
      cout << "\n the final one";
     
        QuestsOne.insertDetails ("Fishing", "golden fish",40);
      cout << endl;
   MagicBee();
  }
  
  void Sailing () {
    
    cout << "\n You are now sailing on the magic lake " << endl;
    cout << "\n Now you should take one water lily " << endl;
    cout << "\n Careful! Don't bend down too much!" << endl;
    cout << "\n ***Congrats! Now you got the water lily***" << endl;
    cout << "\n You can use it to increase your dexterity." << endl;
    cout << endl;
    QuestsOne.insertDetails ("Sailing", "water lily",40);
    MagicBee();
    
  }


void Lake() {
  
  //system("cls");
  cout << "\n Hey! I am Fizzy and I'll give you the new quest!" << endl;
  cout <<  "\n You are now at the lake near the city" << endl;
  cout << "\n What would you like to do?" << endl;
  cout << "\n 1. I'd like to fish. It's that possible?" << endl;
  cout << "\n 2. I'd like sailing with boat. " << endl;
  cin >> input;

    switch (input)
    {case 1:
     //system("cls");
    Fishing();
    
     case 2:
    //system ("cls");
    Sailing();}

}

 
void MagicForest() {

    //system("cls");
    cout << "\n Now you are at the forest entrance." << endl;
    cout << "\n The tree with the magic wood is nearby. " << endl;
    cout << "\n 1. Move left." << endl;
    cout << "\n 2. Move right." << endl;
    cout << "\n 3. Move forward." << endl;
    cin>> input ;

    switch (input) {

        case 1:
        //system ("cls");
        cout << "\n Here it is the tree." << endl;
        cout << "\n You now have to find a magic knife to cut a piece of that tree." << endl;
        cout << "\n Going to it. It's almost here..." << endl;
        //system ("pause");

        //system ("cls");
        cout << "\n Now you have it! Congratiulations!" << endl;
        QuestsOne.insertDetails ("Hospital","Knife",10);
        cout << "\n Now go fast to the tree and return to Gary" << endl;
        cout << "\n with the magic piece of wood for his daughter." << endl;
        cout << "\n ***Congratiulations! You have received now your teleport item and a key.***"<< endl ;
        QuestsOne.insertDetails ("MacigForest","Teleport item, key",50);
        cout << endl;
        
        
        qUpdates = "Quest updated";
       

        case 2:
        //system("cls");
        cout << "\n Here in your way is a knife." << endl;
        cout << "\n Oh, good, you got it. You will need it" << endl;
        cout << "\n to can cut a piece of that magic wood for Gary" << endl;
        QuestsOne.insertDetails ("Hospital","Knife",10);
        cout << "\n Now back at the entrance and move left, there is the tree." <<endl;
       cout << "\n ***Congratiulations! You have received now your teleport item and a key.***"<< endl ;
        QuestsOne.insertDetails ("MacigForest","Teleport item, key",50);}
        Lake ();
      
 } 


void quest1() 

{//system("cls");
 cout << "***Congratiulation! You have purchased a new item from Clothing Store.***" << endl;
    cout << "\n ";
    //system("pause");

    QuestsOne.insertDetails ("Clothing","Scarf",10);
}  
  

  
 
int main()
  
{ 
 //srand (time(NULL));
 
cout << "\n Welcome to RPG!" << endl;
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        cout<< "Quest adventure began" << endl;
        cout << "Spawn in the MagicVillage" << endl;
        
        MagicVillage();
     //StripCow();
      //collectFlour();
        break;
        
        
        case 2:
        break;}
  
        return 0;}






