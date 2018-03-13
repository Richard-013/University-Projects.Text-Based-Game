#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "Item.cpp"
#include "Mob.cpp"

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int connectToDb(sqlite3 * db, int rc, char * zErrMsg);
void closeDb(sqlite3 * db);
void getMenuMain();
void getMenuMob();
void showMobs(sqlite3 * db, int rc, char * zErrMsg);
void addMob(sqlite3 * db, int rc, char * zErrMsg);
string setMobName(string name);
int setMobValue(string name);

// main block START

int main () {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   int currentMob = -1;
   int isMenuOpen = true;

   rc = sqlite3_open("test.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   while (isMenuOpen) {
      if (currentMob == -1) {
         getMenuMain();
         int choice1;
         cin >> choice1;

         switch (choice1) {
            case 1:
               addMob(db, rc, zErrMsg);
               break;
            case 2:
               // dropMob();
               break;
            case 3:
               showMobs(db, rc, zErrMsg);
               break;
            case 4:
               // chooseMob();
               break;
            case 5:
               isMenuOpen = false;
               break;
            default:
               cout << "Wrong input" << endl;
               break;
         }
      }
   }

   closeDb(db);

   return 0;
}

// main block END

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   Mob mobs[argc];
   for(i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void getMenuMain(){
    cout << "\n1: Add mob \n";
    cout << "2: Drop mob \n";
    cout << "3: Show mobs \n";
    cout << "4: Choose mob \n";
    cout << "5: Exit \n";
}

void getMenuMob(){
    cout << "\n1: showInventory \n";
    cout << "2: Add item \n";
    cout << "3: Drop item \n";
    cout << "4: Level up item \n";
    cout << "5: Logout \n";
}

void addMob(sqlite3 * db, int rc, char * zErrMsg) {
   string name = setMobName("name");
   int level = setMobValue("level");
   int armor = setMobValue("armor");
   int hp = setMobValue("hp");
   int speed = setMobValue("speed");
   int damage = setMobValue("damage");
   int hitChance = setMobValue("hitChance");
   int critChance = setMobValue("critChance");
   int range = setMobValue("range");

   string sql = "INSERT INTO Mobs values(null, '" + name + "', " + to_string(level) + ", " + to_string(armor) + ", " + to_string(hp) + ", " + to_string(speed) + ", " + to_string(damage) + ", " + to_string(hitChance) + ", " + to_string(critChance) + ", " + to_string(range) + ")";
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ) {
      cout << SQLITE_OK;
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
}

void showMobs (sqlite3 * db, int rc, char * zErrMsg) {
   const char *sql = "SELECT * FROM Mobs";
   // sql = ";";
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ) {
      cout << SQLITE_OK;
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
}

string setMobName (string name) {
   cout << "Enter mob " << name << ": ";
   string temp;
   cin >> temp;
   return temp;
}

int setMobValue (string name) {
   cout << "Enter mob " << name << ": ";
   int temp;
   cin >> temp;
   return temp;
}

void closeDb (sqlite3 * db) {
   cout << "closed connection to db\n";
   sqlite3_close(db);
}
