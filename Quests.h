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
   void insertDetails (string qname, int qnumber, string qreward, int qpoints);
   void SeeDetails(int qnumber);
};


#endif //QUESTS_H