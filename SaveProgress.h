#ifndef SAVEPROGRESS_H
#define SAVEPROGRESS_H

#include "Player.h"

class SaveProgress
{
    public:
        SaveProgress();
        void firstSave(Player &playerObj);
		void setCharacterID(Player &playerObj);
        void save(Player &playerObj);
		void load(Player &playerObj, int characterID);

    protected:

    private:
};

#endif // SAVEPROGRESS_H
