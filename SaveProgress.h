#ifndef SAVEPROGRESS_H
#define SAVEPROGRESS_H

#include "Player.h"

// Richard
class SaveProgress
{
    public:
        SaveProgress();
        void firstSave(Player &playerObj);
		void setCharacterID(Player &playerObj);
		void firstSaveWorldState(Player &playerObj);
        void save(Player playerObj);
		void saveWorldState(Player playerObj);
		void load(Player &playerObj, int characterID);
		int loadWorldState(int characterID);

    protected:

    private:
};

#endif // SAVEPROGRESS_H
