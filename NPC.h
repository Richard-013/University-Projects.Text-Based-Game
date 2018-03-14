#ifndef NPC_H
#define NPC_H
#include <string>

using namespace std;

class NPC
{
    int NPCID;
    
    //setNPCDetails variables
    string name;
    string zone;
    string quest;
    string item; 
    
    int damage;
    int health;
    
    //get variables
    string duelPhrase;
    string battleReward;
    string meetingMessage;

    public:
        NPC();
        void setNPCDetails(string name, string zone, string quest, string item);
        void setNPCHealth(int health, int NPCID);
        void setNPCDamage(int damage, int NPCID);
        void setDuelPhrase(string duelPhrase,int NPCID);
        void setBattleReward(string battleReward, int NPCID);
    
        string getName(int NPCID);
        string getZone(int NPCID);
        string getQuest(int NPCID);
        string getItem(int NPCID);
        string getDuelPhrase(int NPCID);
        string getBattleReward(int NPCID);
        int getHealth(int NPCID);
        int getDamage(int NPCID);
        string NPCmeeting(int NPCID);
        

};

#endif //NPC_H
