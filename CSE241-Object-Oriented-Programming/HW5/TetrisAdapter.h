#include "abstractTetris.h"
#include "tetramino.h"
#include <iostream>
#include <vector>
using namespace std;

#ifndef TETRISADAPTER
#define TETRISADAPTER

template <typename T>
class TetrisAdapter : public abstractTetris{
public:
    
    void draw() override;
  	void readsFromFile() override;
  	void writeToFile() override;
	char lastMove() override;
    int numberOfMoves() override; 

    TetrisAdapter(int row_i,int column_j);
    T& operator()(int x,int y);
    void getArray();
	void printArray(char* gameOneArray);
	int getRow(){return row;}
	int getColumn(){return column;}
	void tetraminoAtTop(char* gameOneArray,char **tetramino);
	void rotatedVersionAndMove(char* gameOneArray,char **tetramino,char moveDirection, int moveCount);
	void rotate_suitable(char **tetramino,char rotationDirection, int rotationCount);
	bool toCheckAnyTetramino(int *holder_value,char* gameOneArray,char moveDirection,int moveCount,char wordHolder);
	int whichRow(int *holder_value,char* gameOneArray,char moveDirection,int moveCount,char wordHolder);
	char* gameOneArray;
    
	int number_of_moves;
private:
    int row;
    int column;
    char* oneArray;
};


#endif