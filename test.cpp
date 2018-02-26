#include <iostream>
#include <string>
#include "../libsqlite.hpp"
#include "SaveProgress.h"

using namespace std;

int main()
{
    string sqliteFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        
        
        cur->set_sql( "SELECT count(*) "
					  "FROM CharacterData " );
        cur->prepare();
        cur->step();
		int count = cur->get_int(0);
		cout << count << endl;
			
		/*
        auto a = cur->step();
        do
        {
          cout << cur->get_text(1) << endl;
          a = cur->step();
        } while( a );
		*/
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
        return 1;
    }
    
    //SaveProgress sp;
    //sp.firstSave();
    return 0;
}