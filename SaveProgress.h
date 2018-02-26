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
        int assignPlayerID();

    protected:

    private:
};

#endif // SAVEPROGRESS_H
