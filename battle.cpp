// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int battle() //battle function will eventually take enemy ID as argument
{
    cout << "Select a battle option" << endl;
	cout << "1 - Basic Attack" << endl;
	cout << "2 - Ability" << endl;
	cout << "3 - Magic" << endl;
	cout << "4 - Item" << endl; //allows the player to select an option
	short choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "basic attack" << endl;
		break;
//Basic attack
	case 2:
		cout << "Ability" << endl;
		break;
//Ability
	case 3:
		cout << "Magic" << endl;
		break;
//Magic
	case 4:
		cout << "Item" << endl;
		break;
//Item
	}
	short i;
	cin >> i;
	
	return 0;
}

int main()
{
	battle();
}

