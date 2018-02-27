#ifndef SAVEPROGRESS_H
#define SAVEPROGRESS_H

#include "Player.h"

class SaveProgress
{
    public:
        SaveProgress();
        //void firstSave(Player playerObj);
        void firstSave();
        void save(Player playerObj);
        int assignCharacterID();
		void load(Player playerObj, int characterID);

    protected:

    private:
};

#endif // SAVEPROGRESS_H
