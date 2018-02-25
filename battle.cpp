#include <iostream>
#include <cstdlib>

using namespace std;


void battle() //battle function will eventually take enemy ID as argument
{ int turn = 0;	
    cout << "Select a battle option" << endl;
	cout << "1 - Basic Attack" << endl;
	cout << "2 - Ability" << endl;
	cout << "3 - Magic" << endl;
	cout << "4 - Item" << endl; //allows the player to select an option
	while(true){
    int hit;
    int hitChance = 90;
    int mageHitChance = 90;
	short choice;
	cin >> choice;
	switch (choice){
	case 1:
	{	turn = turn + 1;
		hit = rand() % 100+1;
	    if(hitChance >= hit){
        //pseudo code: mobHP = mobHP - wpnatk - 1.4*attack
		//if PC == RANGED: mobHP = mobHP - wpnatk + 1.2*dexterity
		cout << "basic attack" << endl;
        }
		else{
        cout << "You missed!" << endl;
		}
		break;}
	case 2:
	{	turn = turn + 1;
		cout << "Ability" << endl;
		//pseudo code: mobHP = mobHP - abilitydmg - 1.3*level - 1.4*main stat
		break;
	}
	case 3:
	{
	turn = turn + 1;
        hit = rand() % 100+1;
	    if(mageHitChance >= hit){
        //pseudo code: mobHP = mobHP - magicdmg - 1.6*intelligence
		cout << "Magic attack" << endl;
        }
		else{
        cout << "You missed!" << endl;
		}
		break;
	}
	case 4:
	{
	turn = turn + 1;
	    /*
	    string itemChoice;
	    SELECT itemName FROM inventory WHERE usable = 1;
	    while(cur->step())
            cout << cur->get_text(0) << endl;
        cout << "Choose an item" << endl;
        cin >> itemChoice;
		break;
		*/
	}
    default:
        cout << "Invalid choice!" << endl;
        continue;
        }

	}

}


int main()
{
	battle();
}
