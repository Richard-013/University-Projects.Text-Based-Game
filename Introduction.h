#ifndef INTRODUCTION_H
#define INTRODUCTION_H
#include <string>
#include "Player.h"

using namespace std;

class Introduction
{
    public:
        Introduction();
        string chooseName();
        int chooseClass();
        void gameBegin(Player &playerObj);

    protected:

    private:
};

#endif // INTRODUCTION_H
