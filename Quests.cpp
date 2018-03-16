#include <iostream>
#include <string>
#include "Quests.h"
#include "libsqlite.hpp"

//using namespace std;


Quests::Quests()
{
  //ctor
};

void Quests::insertDetails(string qname, string qreward, int qpoints )
{ //cout <<qname <<"," <<qpoints<< endl;
  string databaseFile = "RPGDatabase.db";
 try 
 {
  
        sqlite::sqlite db(databaseFile);
        auto cur = db.get_statement();
        cur->set_sql( "INSERT INTO QuestData (QuestName,QuestReward,QuestPoints) VALUES(?,?,?)");
        //cur->set_sql ("SELECT * FROM NPCData;");      
        cur->prepare();
        cur->bind(1,qname);
        //cur->bind(2,qnumber); It's a primary key
        cur->bind(2,qreward);
        cur->bind(3,qpoints);
        cur->step();
       
 }

catch(sqlite::exception e ) //catch all sql issues
{
  cerr << e.what() << endl;
 
}
 //return qreward;
};

string Quests::getReward(int qnumber)  // Allows the player to load their progress from the information stored in the database
{
	  string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
    cur->set_sql( "SELECT * FROM QuestData WHERE QuestsNumber = ?");
		cur->prepare();
		cur->bind(1,qnumber);
    cur->step();
    qreward=cur->get_text(2);
		
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
   return qreward;
}



