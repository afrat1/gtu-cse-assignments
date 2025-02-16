#include <iostream>
#include <vector>
using namespace std;

#ifndef TETRAMINOS
#define TETRAMINOS

enum class tets{ //enum definition
    T, L, I, O, S, Z, J
};

class tetramino{
public:
    tetramino(int a);
    tetramino(char b);
    void assign_tetraminos(char tetraminoType);
    void assign_tetraminos_1d(char tetraminoType);
    void rotate(vector<vector<char>>tetramino);
    void rotate1Darray(char** tetramino);
    void printArray(char **gameArea);
    vector<vector<char>>arr;
    char** arrD;
private:
    vector<vector<char>>array;
    //char** array;    
};
#endif