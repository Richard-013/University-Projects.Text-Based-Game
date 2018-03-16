// Compile Command:
// g== --std=c++14 game.cpp Quests.cpp Battle.cpp Item.cpp Player.cpp SaveProgress.cpp Introduction.cpp ability-use.cpp Mob.cpp NPC.cpp -o Game -lsqlite3
// Creates an executable called Game

#include <iostream>
#include <string>
#include "libsqlite.hpp"
#include "Quests.h"
#include "Battle.h"
#include "Item.h"
#include "Player.h"
#include "SaveProgress.h"
#include "Introduction.h"

using namespace std;

string qUpdates;
int input;
void quest1(Player &playerObj);
void quest2(Player &playerObj);
void quest3(Player &playerObj);
void end(Player &playerObj);
void ClothingStore(Player &playerObj);
void MagicVillage(Player &playerObj);
void RaceArena(Player &playerObj);
void MagicForest(Player &playerObj);
void Hospital(Player &playerObj);
void Lake(Player &playerObj);
void Fishing(Player &playerObj);
void Sailing(Player &playerObj);
void collectFlour(Player &playerObj);
void StripCow(Player &playerObj);
void DirtyWork(Player &playerObj);
void wantToSave(Player &playerObj);
Quests QuestsOne;

void RaceArena (Player &playerObj) {
  cout << "\n I am Bully and I have a new quest for you!" << endl;
  cout << "\n Fight me! If you will win, I'll be given you the Black Belt"<< endl;
  Battle bt;
  Item fists;
  bt.battle(playerObj.characterID, 6, fists);
  //battle
  cout << "***Congratulations! You won a black belt and 10 points."<< endl;
  QuestsOne.insertDetails ("RaceArena","BlackBelt",10);
}

void ClothingStore(Player &playerObj) {
        cout << "\n The commands here are (1.buyglasses),(2.clothes),(3.buyhat)." << endl;
        cout << "\n 1. buyglasses" << endl;
        cout << "\n 2. clothes" << endl;
        cout << "\n 3. buyhat" << endl;
        cout << "\n 4. I don't want any of these";
        cout << "\n ";
        cin >> input;
      
        switch (input) {

            case 1: case 2: case 3:
            
            { quest1 (playerObj);
            qUpdates = "Quest updated";
            //questUpdate1();
            quest2(playerObj);
            break;}
      
			case 4:
            cout << "\n If you don't want one of these, it's ok." << endl;
            cout << endl ;
         
      }
}

void quest2(Player &playerObj) {
    //system("cls");
    playerObj.checkpoint = 1;
    wantToSave( playerObj );
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
      
        RaceArena(playerObj);
        Hospital(playerObj);
        break;

        case 2:
       
        cout << "\n You should then go to the hospital. Someone is waiting for you!" << endl;
        cout << "\n ";
     
        Hospital(playerObj);}
}


void MagicVillage(Player &playerObj) {

    //system("cls");
    cout << "\n You are in the Magic viillage. The first quest is to go to ClothingStore" << endl;
    cout << "\n 1. Ok go there." << endl;
    cout << "\n ";
    cin >> input;
    switch (input) {

        case 1:
        ClothingStore(playerObj);
        break;
        
        case 2:
        cout << "Ok then if you don't want." << endl;
        quest2(playerObj);

    }   
}

void LastFight (Player &playerObj) 
{
	playerObj.checkpoint = 2;
	wantToSave( playerObj );
	cout << "\n I think that you have waited so much for this!" << endl;
	cout << "\n You were really brave!" << endl;
	cout << "\n You have done the quests and have the fight with the mobs!..." << endl;
	cout << "\n Now is the last turn. You will win or you will lose?" << endl;
	Battle bt;
	Item weapon;
	bt.battle(playerObj.characterID, 10, weapon);
	playerObj.checkpoint = 4;
	wantToSave( playerObj );
}


void DirtyWork(Player &playerObj) {
  cout <<"\n I can see that you have muscles " << endl;
  cout << "\n Thank you for helping me with all of these" << endl;
  cout <<"\n ***Congratiulations! Now you have the Shovel. Good luck with your fight!***"<< endl;
  QuestsOne.insertDetails ("Dirty Work", "shovel",20);
  LastFight(playerObj);
}

void collectFlour(Player &playerObj) {  
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
    LastFight(playerObj);
   break;
    case 2 : 
   DirtyWork(playerObj);}
}

void StripCow (Player &playerObj) {
  cout << " \n Hi ya! Do you like the atmosfere here at the farm? "<< endl;
   cout << "\n Guess yes! I am Bob the farmer and I'll give you some quests." << endl;
   cout << "\n First, could you help me strip the cow? " << endl;
   cout << "\n Oh thanks, I knew you are a good boy." << endl;
   cout << "\n *** Congratiulations! Here is milk for you to have more calcium***" <<endl;
  QuestsOne.insertDetails ("Strip the cow", "milk",30);
  cout << endl;
  
   collectFlour(playerObj);

}

void MobsVillage (Player &playerObj) {
  cout << "\n Oups! It looks like you have been fooled. " << endl;
  cout << "\n The camel took you here. " << endl;
  cout << "\n It's a dangerous place!" << endl;
  cout << "\n Now you need to have some fights with the mobs to can continue your adventure"<< endl;
  Battle bt;
  Item weapon;
  bt.battle(playerObj.characterID, 5, weapon);
  bt.battle(playerObj.characterID, 7, weapon);
  bt.battle(playerObj.characterID, 8, weapon);
  cout << "Well done! Here is your reward and good luck for the other quests." << endl;
  cout << "\n ***Congratiulations! You won a new life!" << endl;
  QuestsOne.insertDetails ("Fight with Mobs", "new life",500);
  cout << "\n Now you are going to Bob, my friend." << endl;
  
  StripCow(playerObj);
}

void Hospital(Player &playerObj) {
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
        
        MagicForest(playerObj);
        
        
        case 2:
        //system ("cls");
        cout << "\n But please, I beg you. Mary, my girl, really needs that." << endl;
        cout << "\n Okay, I will try to help you with this." << endl;
        cout << endl;
        
        MagicForest(playerObj);
    }
}

void Camel (Player &playerObj) {
   cout << " \n You look a lot like loving to ride camels! " << endl;
   cout << " \n This is true, right ?" << endl;
   cout << " \n Here is my best friend, the Camel Dorry." << endl;
   cout << " \n If you would like to have a walk around the dessert it will be my pleasure!" << endl;
   cout << " \n Just having a good time.... ";
  QuestsOne.insertDetails ("Camel", "Fool",0);
    cout << endl;
   MobsVillage(playerObj);
}

void  MagicBee(Player &playerObj)
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
       Camel(playerObj);
   
   case 2:
       cout << "But please...I really need that. " << endl;
       cout << "\n You are now searching for that bee..."<< endl;
       cout << "\n Oh! Look, just there!" << endl;
       cout << "\n It looks like a treasure. You should try the key that you have" << endl;
       cout << "\n Trying to unlock it with the key..." << endl;
       cout << "\n Oh! You now have a toxic spray and can go for the magic honey" << endl;
       cout << "\n Well done!";
       cout << endl;
      Camel(playerObj);
   }
}
 
void Fishing (Player &playerObj) 
  {
    //system("cls");
    cout << "\n You're now fishing.";
      
      cout << "\n Oh, look!*** Congratiulations! You caught a golden fish!***" << endl;
      cout << "\n This will help you with health in your battle" << endl;
      cout << "\n with the dragon if you will do the quests until" << endl;
      cout << "\n the final one";
     
        QuestsOne.insertDetails ("Fishing", "golden fish",40);
      cout << endl;
   MagicBee(playerObj);
  }
  
void Sailing (Player &playerObj) {
    
    cout << "\n You are now sailing on the magic lake " << endl;
    cout << "\n Now you should take one water lily " << endl;
    cout << "\n Careful! Don't bend down too much!" << endl;
    cout << "\n ***Congrats! Now you got the water lily***" << endl;
    cout << "\n You can use it to increase your dexterity." << endl;
    cout << endl;
    QuestsOne.insertDetails ("Sailing", "water lily",40);
    MagicBee(playerObj);
    
  }


void Lake(Player &playerObj) {
  
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
    Fishing(playerObj);
    
     case 2:
    //system ("cls");
    Sailing(playerObj);}

}

 
void MagicForest(Player &playerObj) {

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
        Lake (playerObj);
      
 } 


void quest1(Player &playerObj) 
{//system("cls");
 cout << "***Congratiulation! You have purchased a new item from Clothing Store.***" << endl;
    cout << "\n ";
    //system("pause");

    QuestsOne.insertDetails ("Clothing","Scarf",10);
}  
  
// Richard
void wantToSave(Player &playerObj)
{
	SaveProgress saveProg;
	int answer;
	bool invalidAnswer = true;
	do
	{
		cout << "Would you like to save your progress?" << endl;
		cout << "    1 - Yes\n    2 - No" << endl;
		cin >> answer;
		
		if( answer == 1 || answer == 2 )
		{
			invalidAnswer = false;
		}
	} while( invalidAnswer );
	
	if( answer == 1 && playerObj.firstTimeSaving )
	{
		saveProg.firstSave( playerObj );
		cout << endl << "Your characterID is " << playerObj.characterID << endl;
		cout << "Please remember this in order to load your progress at a later date" << endl;
	}
	else // if( answer == 1 && playerObj.firstTimeSaving != true )
	{
		int playerID = playerObj.characterID;
		saveProg.firstSave( playerObj );
		cout << endl << "Save successful, data for character " << playerID << " has been updated" << endl;
	}
}

int main()  // Main function that runs the game
{
	bool runGame = true;  // This variable is used to let the player break the game loop and quit the game
	do
	{
		Player playerObj;
		SaveProgress saveProg;

		int answer, loadID;
		bool invalidAnswer = true;  // This variable is used to run loops that check for valid input

		// Title Screen
		cout << "################################################################" << endl;
		cout << "#                                                              #" << endl;
		cout << "#                           Generica                           #" << endl;
		cout << "#                                                              #" << endl;
		cout << "################################################################" << endl << endl << endl;

		try
		{
			// Menu
			cout << "Welcome to Generica, the generic RPG game" << endl;
			cout << "Would you like to start a new game or load a previous save?" << endl;
			cout << "    1 - Start a new game" << endl;
			cout << "    2 - Load a previous save" << endl;
			cout << "    3 - Exit the game" << endl;

			do  // Do-While loop to take input and check its validity
			{
				cin >> answer;
				if( answer == 1 || answer == 2 || answer == 3 )
				{
					invalidAnswer = false;
				}
			} while( invalidAnswer );

			if( answer == 1 )
			{
				// If the player starts a new game then this will launch the whole game from the start
				// from the start when it hits the switch statement below as the default value for the player's checkpoint is 0			}
			}
			else if( answer == 2 )
			{
				// Loads player data
				cout << "What is the ID of the character?" << endl;
				cin >> loadID;
				playerObj.firstTimeSaving = false;
				saveProg.load(playerObj, loadID);
			}
			else if( answer == 3 )
			{
				// This sets the runGame variable to false so the game know's to exit after this if-statement
				runGame = false;
			}
			else
			{
				// Error occurs if the player manages to make an invalid choice
				throw std::invalid_argument( "Received invalid selection" );
			}
		}
		catch( const std::invalid_argument& e )  // Catches any invalid choices given by the player as an error
		{
			cout << "You did not make a valid choice, the game will now end" << endl;
		}
		
		if( runGame == false )
		{
			break;
		}
		
		if( playerObj.checkpoint == 4 )
		{
			cout << "This character has already completed the game" << endl;
			cout << "Please begin angain to select a new character" << endl;
			cout << "Press enter to restart the game" << endl;

			cin.ignore();
			continue;
		}
		else
		{
			switch( playerObj.checkpoint )
			{
				case 0:  // Runs the entire game from the beginning as the player has not made any progress
				{
					Introduction intro;
					intro.characterCreation( playerObj );
					cout<< "Quest adventure began" << endl;
					cout << "Spawn in the MagicVillage" << endl;
					MagicVillage(playerObj);
					runGame = false;
					break;
				}
				case 1:  // Runs the game from part 2
				{
					quest2(playerObj);
					runGame = false;
					break;
				}
				case 2:  // Runs the game from part 3
				{
					LastFight(playerObj);
					runGame = false;
					break;
				}
				default:  // Runs the game from the beginning if there is no checkpoint saved
				{
					cout << "No checkpoint data found, beginning game from the start" << endl;
					playerObj.checkpoint = 0;  // Sets the player's progress marker as 0 i.e. the start of the game
					cout<< "Quest adventure began" << endl;
					cout << "Spawn in the MagicVillage" << endl;
					MagicVillage(playerObj);
					runGame = false;
					break;
				}
			}
		}
	} while( runGame );
	
	return 0;
}

  
/*    Commented out in order to use the full main() function from GameFile.cpp
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
*/