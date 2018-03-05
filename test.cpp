#include <iostream>
#include <string>
#include "libsqlite.hpp"
#include "SaveProgress.h"
#include "Player.h"

using namespace std;

int main()
{
    string sqliteFile = "RPGDatabase.db";

    try
    {
		/*
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        
        
        cur->set_sql( "select * "
                      "from CharacterData " );
        cur->prepare();
        cur->step();
		string name = cur->get_text(1);
		cout << name << endl;
		cur->step();
		name = cur->get_text(1);
		cout << name << endl;
		cur->step();
		name = cur->get_text(1);
		cout << name << endl;
		cur->step();
		name = cur->get_text(1);
		cout << name << endl;
		cur->step();
		name = cur->get_text(1);
		cout << name << endl;
			
		/*
        auto a = cur->step();
        do
        {
          cout << cur->get_text(1) << endl;
          a = cur->step();
        } while( a );
		*/
		Player player;
		SaveProgress sp;
		//sp.firstSave(player);
		sp.load(player, 15);
		player.attack = player.attack + 3;
		sp.save(player);
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