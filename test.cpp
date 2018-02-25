#include <iostream>
#include <string>
#include "../../libsqlite.hpp"

using namespace std;

int main()
{
    string sqliteFile = "RPGDatabase.db";

    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        
        cur->set_sql( "select * "
                      "from CharacterData" );
        cur->prepare();
        
        auto a = cur->step();
        do
        {
          cout << cur->get_text(1) << endl;
          a = cur->step();
        } while( a );
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}