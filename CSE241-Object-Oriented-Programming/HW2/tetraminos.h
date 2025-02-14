#include <iostream>
#include <vector>
using namespace std;

#ifndef TETRAMINOS
#define TETRAMINOS

enum class tets{ //enum definition
    T, L, I, O, S, Z, J
};

class tetraminos{
public:

    vector<vector<char>>arr;

    tetraminos(char tetramino_type);

    tetraminos(tets t);//constructors
    tetraminos(int a);//constructors

    void Rotate(); 
    void Print();
    bool canFit(tetraminos x, int location); 
private:
    
};
#endif