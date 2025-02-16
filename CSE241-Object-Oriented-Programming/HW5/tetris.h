#include <iostream>
#include <vector>
#include "abstractTetris.h"
using namespace std;

#ifndef TETRIS
#define TETRIS
class tetris : public abstractTetris{
public:

	int getRow(){return row;}
	int getColumn(){return column;}
	int number_of_moves;
	void draw() override;
  	void readsFromFile() override;
  	void writeToFile() override;
	char lastMove() override;
    int numberOfMoves() override; 
	vector<vector<char>>game_area;
    tetris(int,int);
	void get_vector_values();
	void printArray(vector<vector<char>>gameArea);
	void tetraminoAtTop(vector<vector<char>>gameArea,vector<vector<char>>tetramino);
	void rotatedVersionAndMove(vector<vector<char>>gameArea,vector<vector<char>>tetramino,char moveDirection, int moveCount);
    void rotate_suitable(vector<vector<char>>tetramino,char rotationDirection, int rotationCount);
	bool toCheckAnyTetramino(int *holder_value,vector<vector<char>>gameArea,char moveDirection,int moveCount,char wordHolder);
	int whichRow(int *holder_value,vector<vector<char>>gameArea,char moveDirection,int moveCount,char wordHolder);
private:
	vector<vector<char>>array;
	int row;
	int column;

};


#endif