#ifndef INTRODUCTION_H
#define INTRODUCTION_H
#include <string>

using namespace std;

class Introduction
{
    public:
        Introduction();
        string getName();
        int chooseGender(string name);
        int chooseClass();

    protected:

    private:
};

#endif // INTRODUCTION_H
