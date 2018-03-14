#include <iostream>
//#include <string>
#include "NPC.h"
#include "NPC.cpp"

using namespace std;

int main()
{
    NPC NPCOne;
    NPCOne.setNPCDetails("Greg","Village","Help Mary","Talisman");
    NPCOne.setNPCHealth(10,1);
    NPCOne.setNPCDamage(10,1);
    NPCOne.setDuelPhrase("You dare challenge me? A scared father?",1);
    NPCOne.setBattleReward("Tears of Fatherhood",1);
    
    NPC NPCTwo;
    NPCTwo.setNPCDetails("Fizzy","Lake","Find a golden fish!","Magic Fish");
    NPCTwo.setNPCHealth(20,2);
    NPCTwo.setNPCDamage(20,2);
    NPCTwo.setDuelPhrase("Fishing...fighting... it's all the same.",2);
    NPCTwo.setBattleReward("Fishing Rod",2);
    
    NPC NPCThree;
    NPCThree.setNPCDetails("Bully","Arena","FIGHT ME!","Black Belt");
    NPCThree.setNPCHealth(30,3);
    NPCThree.setNPCDamage(30,3);
    NPCThree.setDuelPhrase("I BREAK SILLY HUMAN!!",3);
    NPCThree.setBattleReward("Bully's tooth",3);
    
    NPC NPCFour;
    NPCFour.setNPCDetails("Rowz","Lake","Sail the dark waters","Bag of fish");
    NPCFour.setNPCHealth(40,4);
    NPCFour.setNPCDamage(40,4);
    NPCFour.setDuelPhrase("Would you like a ride in Rowz's boat?",4);
    NPCFour.setBattleReward("Shiny Coin",4);
    
    NPC NPCFive;
    NPCFive.setNPCDetails("Laira","Clothing store","Get fancy","Sparkly Scarf");
    NPCFive.setNPCHealth(50,5);
    NPCFive.setNPCDamage(50,5);
    NPCFive.setDuelPhrase("You want to mess up my hair? INCONCEIVABLE!",5);
    NPCFive.setBattleReward("Laira's Hairpin",5);
    
    NPC NPCSix;
    NPCSix.setNPCDetails("Bob","Farm","Dirty work","Shovel");
    NPCSix.setNPCHealth(60,6);
    NPCSix.setNPCDamage(60,6);
    NPCSix.setDuelPhrase("You better die fast! I have carrots to plant.",6);
    NPCSix.setBattleReward("Rotten Carrot",6);
    
    return 0;
}