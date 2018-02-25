#include <iostream>

using namespace std;

void passive(){
//would take as input player class from db
switch(class){
case 1:
{ int shield;
  //reads player's defence from db
  shield = defence + turn;
  cout<<"***You gain extra shield every turn. (+" +  shield + ")";
  break;
}
case 2:
{
  cout<<"***You always strike first in a battle.";
  break;
}
case 3:
{   int extradmg;
    extradmg = rand()%10;//random number between 0-9
    cout<<"***You've put poison on your arrows and deal (+." +extradmg +") every turn.";
    break;
}
case 4:
{   int chance;
    chance = rand()%3;
    cout<<"***Every 3 turns you summon a portal that has a chance in three to terminate the enemy.";
    if(chance==1){
    //terminateenemy
    }
}


}

}
