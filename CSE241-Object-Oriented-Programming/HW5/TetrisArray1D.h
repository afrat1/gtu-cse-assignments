#include "abstractTetris.h"
#include "tetramino.h"
#include <iostream>
#include <vector>
using namespace std;

#ifndef TETRISARRAY1D
#define TETRISARRAY1D


class TetrisArray1D : public abstractTetris{
public:

    void draw() override;
  	void readsFromFile() override;
  	void writeToFile() override;
	char lastMove() override;
    int numberOfMoves() override; 
	
    TetrisArray1D(int, int);

    void getArray();
	void printArray(char* gameOneArray);
	int getRow(){return row;}
	int getColumn(){return column;}
    char** game_area;
	void tetraminoAtTop(char* gameOneArray,char **tetramino);
	void rotatedVersionAndMove(char* gameOneArray,char **tetramino,char moveDirection, int moveCount);
	void rotate_suitable(char **tetramino,char rotationDirection, int rotationCount);
	bool toCheckAnyTetramino(int *holder_value,char* gameOneArray,char moveDirection,int moveCount,char wordHolder);
	int whichRow(int *holder_value,char* gameOneArray,char moveDirection,int moveCount,char wordHolder);

	char* gameOneArray;

	int number_of_moves;
	
	
private:
    char* oneArray;
    char** array;
	int row;
	int column;
};


#endif