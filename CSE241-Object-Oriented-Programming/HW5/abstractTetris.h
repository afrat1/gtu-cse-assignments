#include <iostream>
#include <vector>
using namespace std;

#ifndef ABSTRACTTETRIS
#define ABSTRACTTETRIS

class abstractTetris{
public:
    virtual void draw() = 0;
    virtual void readsFromFile() = 0;
    virtual void writeToFile() = 0;
    virtual char lastMove() = 0;
    virtual int numberOfMoves() = 0; 
};  


#endif