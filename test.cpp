#include <iostream>
#include <string>
#include "libsqlite.hpp"
//#include "SaveProgress.h"
#include "Player.h"
#include "Battle.h"
#include "Item.h"
#include "Mob.h"

using namespace std;

int main()
{

    /*string sqliteFile = "RPGDatabase.db";

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
			
		
        auto a = cur->step();
        do
        {
          cout << cur->get_text(1) << endl;
          a = cur->step();
        } while( a );
		
		Player player;
		SaveProgress sp;
		sp.load( player, 17 );
		cout << player.level << endl;
		player.setLevel();
		cout << player.level << endl;
		sp.save( player );
		return 0;
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        cerr << e.what() << endl;
        return 1;
    }*/
    
    //SaveProgress sp;
    //sp.firstSave();
    Battle bt;
    Player testguy;
    Mob badguy;
    Item sword;
    bt.battle(testguy, badguy, sword);
    return 0;
}