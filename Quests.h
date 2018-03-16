#ifndef QUESTS_H
#define QUESTS_H
#include <string>

using namespace std;
class Quests {
  
  string qname;
  string qreward;
  int qpoints; 
  int qnumber; 
  
  public:
  Quests();
  
  
   void insertDetails (string qname, string qreward, int qpoints);
  string getReward(int qnumber);
  
  
  void SeeDetails(int qnumber);
};


#endif //QUESTS_H