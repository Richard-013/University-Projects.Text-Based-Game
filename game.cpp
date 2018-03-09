#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
void quest1();
void quest2();
void quest3();
void questUpdate();
void end();
void questUpdate1();
void ClothingStore();
void MagicVillage();
void RaceArena();
void MagicForest();
void questUpdate3();
void questUpdate2();
void Hospital();



int input;
int stages[8] = {1, 0, 0, 0, 0, 0, 0, 0};

string qUpdates;
string qStages;

int main() 
    {

    srand (time(NULL));

    system("cls");
    cout << "\n Welcome to RPG!" << endl;
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        qUpdates = "Quest adventure began";
        qStages = "Spawn in the MagicVillage";
        //questUpdate();

        MagicVillage();

        case 2:
        return EXIT_SUCCESS;}


void MagicVillage() {

    system("cls");
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
       quest2();

    }   
}

void ClothingStore() {

    if (stages[0] == 1) 
        system("cls");
        cout << "\n The commands here are (1.buyglasses),(2.clothes),(3.buyhat)." << endl;
        cout << "\n 1. buyglasses" << endl;
        cout << "\n 2. clothes" << endl;
        cout << "\n 3. buyhat" << endl;
        cout << "\n 4. I don't want any of these";
        cout << "\n ";
        cin >> input;
      
      switch (input) {

            case 1: case 2: case 3:
            
            quest1 ();
            qUpdates = "Quest updated";
            questUpdate1();
            break;

            case 4:
            system("cls");
            cout << "\n If you don't want one of these, it's ok." << endl;
            cout << "\n ";
            system("pause");
      }   
}
        


   // if (stages[1] == 1) {
      //  stage2();
    //}

    //if (stages[2] == 1) {
    //    stage3();
    //}

    //else {
    //    stage4(sword, gold);
    //}


void quest1() {

    system("cls");
    cout << "Congratiulation! You have purchased a new item from Clothing Store.";
    cout << "\n ";
    system("pause");
    stages[1] = 1;

}
 void quest2() {

    system("cls");
    cout << "\n Now I have a recommendation for you.." << endl;
    cout << "\n You should go to the Race Arena. " << endl;
    cout << "\n But firstly, you should go to the Gym and learn a new fighstyle." << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n 1. Okay, I will go to the Gym firstly and then to the Race Arena. " << endl;
    cout << "\n 2. I don't think I'm the right person for the this. I don't like sport." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        stages[0] = 0;
        stages[2] = 1;
        system("cls");
        cout << "\n Wish you have fun!" << endl;
        cout << "\n ";
        system("pause");

        qUpdates = "Quest updated";
        questUpdate2();
        RaceArena();
        Hospital();
        //riverstead();

        case 2:
        stages[0] = 0;
        stages[1] = 1;
        system("cls");
        cout << "\n You should then go to the hospital. Someone is waiting for you!" << endl;
        cout << "\n ";
        system("pause");
        
        Hospital();

    }
}

void Hospital() {
    system("cls");
    cout << "\n Hello! I am Greg. Can you help me with something?" << endl;
    cout << "\n I will recompense you with a talisman." << endl;
    cout << "\n With it you can respawn in the Hospital to get healed any time." << endl;
    system("pause");

    system("cls");
    cout << "\n There, in the magic forest, is a tree which has magic wood." << endl;
    cout << "\n I need a piece of that wood to treat my ill daughter." << endl;
    cout << "\n She has not much time remaining. Tell me. You can help?" << endl;
    system("pause");

    system("cls");
    cout << "\n 1. Yes, sure, I will help you right now." << endl;
    cout << "\n 2. Sorry, I don't think I can help you. Maybe later." << endl;
    cin >> input;

    switch (input) {

        case 1:
        system("cls");
        cout << "\n I will teleport you in the forest right now." << endl;
        cout << "\n";
        
        MagicForest();

        case 2:
        system ("cls");
        cout << "\n But please, I beg you. Mary, my girl, really needs that." << endl;
        cout << "\n Okay, I will try to help you with this." << endl;
        cout << endl;
        
        MagicForest();
    }
}

void MagicForest() {

    system("cls");
    cout << "\n Now you are at the forest entrance." << endl;
    cout << "\n The tree with the magic wood is nearby. " << endl;
    cout << "\n 1. Move left." << endl;
    cout << "\n 2. Move right." << endl;
    cout << "\n 3. Move forward." << endl;
    cin>> input ;

    switch (input) {

        case 1:
        system ("cls");
        cout << "\n Here it is the tree." << endl;
        cout << "\n You now have to find a magic knife to cut a piece of that tree." << endl;
        cout << "\n Going to it. It's almost here..." << endl;
        system ("pause");

        system ("cls");
        cout << "\n Now you have it! Congratiulations!" << endl;
        
        cout << "\n Now go fast to the tree and return to Gary" << endl;
        cout << "\n with the magic piece of wood for his daughter." << endl;
        cout << endl;
        system ("pause");
        stages[3]=1;
        qUpdates = "Quest updated";
        questUpdate3();

        case 2:
        system("cls");
        cout << "\n Here in your way is a knife." << endl;
        cout << "\n Oh, good, you got it. You will need it" << endl;
        cout << "\n to can cut a piece of that magic wood for Gary" << endl;
        cout << "\n Now back at the entrance and move left, there is the tree." <<endl;
        cout << "\n You have received now your teleport item"<< endl ;
        system("pause");
        qUpdates = "Quest updated";
       
        questUpdate3();

    }
}
  
void Lake() {
  
  system("cls");
  cout <<  "\n You are now at the lake near the city" << endl;
  cout << "\n What would you like to do?" << endl;
  cout << "\n 1. I'd like to fish. It's that possible?" << endl;
  cout << "\n 2. I'd like sailing with boat. "
  cin >> input;

    switch (input)
    {case 1:
     system("cls");
    Fishing();
    
     case 2:
    system ("cls");
    Sailing();}

}

  void Fishing() {
      cout << "\n You're now fishing."
      system("pause")
      cout << "\n Oh, look! You caught a golden fish!" << endl;
      cout << "\n This will help you with health in your battle" << endl;
      cout << "\n with the dragon if you will "
  }
    
    
    
    
    
    
    
  

  void questUpdate1() {

    system("cls");
    cout << "\n " << qUpdates << " Go to clothing store and buy something."  << endl;
    cout << "\n ";
    system("pause");

    if (qStages != " ") {
        system("cls");
        cout << "\n " << qStages << endl;
        cout << "\n ";
        system("pause");
    }


}

void questUpdate2() {
    system ("cls");
    cout << "\n" << qUpdates << "Go to the gym and buy a new fightsyle and then to Race Arena." << endl;
    cout << "\n";
    system("pause");

}


void questUpdate3() {
    system("cls");
    cout << "\n" << qUpdates << "Give the magic wood to the Gary's daughter." << endl;
return;
}



void end() {

    system("cls");
    cout << "\n Thank you for playing RPG!" << endl;
    cout << "\n ";
    system("pause");
    main();
}



