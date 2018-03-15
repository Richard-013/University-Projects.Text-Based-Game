#include <iostream>
#include <string>
#include "Quests.h"
#include "libsqlite.hpp"

using namespace std;


Quests::Quests()
{
  //ctor
};

void Quests::insertDetails(string qname, int qnumber,string qreward,int qpoints)
{ cout <<qname <<"," <<qnumber<< endl;
  string databaseFile = "RPGDatabase.db";
 try 
 {
  
sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "INSERT INTO QuestsData (QuestName,QuestNumber,QuestReward,QuestPoints) "
                      "VALUES ( ? , ? , ?, ?  );" );
  
        cur->prepare();
        cur->bind(1,qname );
        cur->bind(2,qnumber);
        cur->bind(3,qreward);
        cur->bind(4,qpoints);
        cur->step();
 }

catch(sqlite::exception e ) //catch all sql issues
{
  cerr << e.what() << endl;
 
}
};

void Quests::SeeDetails(int qnumber)  // Allows the player to load their progress from the information stored in the database
{
	string databaseFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( databaseFile );
        auto cur = db.get_statement();
		
        cur->set_sql( "SELECT * FROM QuestsData WHERE QuestsNumber = ?");
		cur->prepare();
		cur->bind( 4, qnumber );
		cur->step();
		
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
    }
}
