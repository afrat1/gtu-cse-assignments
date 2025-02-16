#include "tetramino.h"
#include <iostream>
#include <vector>
using namespace std;

tetramino::tetramino(int a){
    vector<int>temp_arr;
    for(auto i=0;i<4;i++){ //It puts space characters in the array.
        vector<char>temp_arr;
        for(auto j=0;j<4;j++){
            temp_arr.push_back('*');
        }
        arr.push_back(temp_arr);
    }
}


tetramino::tetramino(char b){ //it allows to reach the tetraminos
    arrD = new char*[4];
    for(int i = 0; i < 4 ; i++)
        arrD[i] = new char[4];

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            arrD[i][j]='*';
        
}


void tetramino::assign_tetraminos(char tetraminoType){
    if(tetraminoType == 'I' || tetraminoType == 'i'){
        arr[0][0] = 'I';
        arr[0][1] = 'I';
        arr[0][2] = 'I';
        arr[0][3] = 'I';
    }
    else if(tetraminoType == 'O' || tetraminoType == 'o'){
        arr[0][1] = 'O';
        arr[0][2] = 'O';
        arr[1][1] = 'O';
        arr[1][2] = 'O';
    }
    else if(tetraminoType == 'T' || tetraminoType == 't'){
        arr[0][1] = 'T';
        arr[0][2] = 'T';
        arr[0][3] = 'T';
        arr[1][2] = 'T';
    }
    else if(tetraminoType == 'J' || tetraminoType == 'j'){
        arr[0][2] = 'J';
        arr[1][2] = 'J';
        arr[2][2] = 'J';
        arr[2][1] = 'J';
    }
    else if(tetraminoType == 'L' || tetraminoType == 'l'){
        arr[0][1] = 'L';
        arr[1][1] = 'L';
        arr[2][1] = 'L';
        arr[2][2] = 'L';
    }
    else if(tetraminoType == 'S' || tetraminoType == 's'){
        arr[1][1] = 'S';
        arr[1][2] = 'S';
        arr[0][2] = 'S';
        arr[0][3] = 'S';
    }
    else if(tetraminoType == 'Z' || tetraminoType == 'z'){
        arr[0][3] = 'Z';
        arr[0][2] = 'Z';
        arr[1][2] = 'Z';
        arr[1][1] = 'Z';
    }
}

void tetramino::assign_tetraminos_1d(char tetraminoType){
    if(tetraminoType == 'I' || tetraminoType == 'i'){
        arrD[0][0] = 'I';
        arrD[0][1] = 'I';
        arrD[0][2] = 'I';
        arrD[0][3] = 'I';
    }
    else if(tetraminoType == 'O' || tetraminoType == 'o'){
        arrD[0][1] = 'O';
        arrD[0][2] = 'O';
        arrD[1][1] = 'O';
        arrD[1][2] = 'O';
    }
    else if(tetraminoType == 'T' || tetraminoType == 't'){
        arrD[0][1] = 'T';
        arrD[0][2] = 'T';
        arrD[0][3] = 'T';
        arrD[1][2] = 'T';
    }
    else if(tetraminoType == 'J' || tetraminoType == 'j'){
        arrD[0][2] = 'J';
        arrD[1][2] = 'J';
        arrD[2][2] = 'J';
        arrD[2][1] = 'J';
    }
    else if(tetraminoType == 'L' || tetraminoType == 'l'){
        arrD[0][1] = 'L';
        arrD[1][1] = 'L';
        arrD[2][1] = 'L';
        arrD[2][2] = 'L';
    }
    else if(tetraminoType == 'S' || tetraminoType == 's'){
        arrD[1][1] = 'S';
        arrD[1][2] = 'S';
        arrD[0][2] = 'S';
        arrD[0][3] = 'S';
    }
    else if(tetraminoType == 'Z' || tetraminoType == 'z'){
        arrD[0][3] = 'Z';
        arrD[0][2] = 'Z';
        arrD[1][2] = 'Z';
        arrD[1][1] = 'Z';
    }
}

void tetramino::rotate(vector<vector<char>>tetramino){ //rotating matrix by 90 degree in clockwise direction
    int size = 4;
    char temp;
	for (int a = 0; a < size / 2; a++) {
		for (int b = a; b < size - a - 1; b++) {
			temp = tetramino[a][b];
			tetramino[a][b] = tetramino[size - 1 - b][a];
			tetramino[size - 1 - b][a] = tetramino[size - 1 - a][size - 1 - b];
			tetramino[size - 1 - a][size - 1 - b] = tetramino[b][size - 1 - a];
			tetramino[b][size - 1 - a] = temp;
		}
	}

    int count2 = 0;
    
    for(int i=0;i<4;i++){
        int count = 0;
        for(int j=0;j<4;j++){
            if(tetramino[i][j]=='*'){count++;}
        }
        if(count==4){count2++;}
    }

    if(count2!=0){
        cout << count2 << endl;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tetramino[i][j]!='*' && (i-count2)>=0){
                    tetramino[i-count2][j] = tetramino[i][j];
                    tetramino[i][j] = '*';
                }
            }
        }
    }
    
}

void tetramino::rotate1Darray(char** tetramino){ //rotating matrix by 90 degree in clockwise direction
    int size = 4;
    char temp;
	for (int a = 0; a < size / 2; a++) {
		for (int b = a; b < size - a - 1; b++) {
			temp = tetramino[a][b];
			tetramino[a][b] = tetramino[size - 1 - b][a];
			tetramino[size - 1 - b][a] = tetramino[size - 1 - a][size - 1 - b];
			tetramino[size - 1 - a][size - 1 - b] = tetramino[b][size - 1 - a];
			tetramino[b][size - 1 - a] = temp;
		}
	}

    int count2 = 0;
    
    for(int i=0;i<4;i++){
        int count = 0;
        for(int j=0;j<4;j++){
            if(tetramino[i][j]=='*'){count++;}
        }
        if(count==4){count2++;}
    }

    if(count2!=0){
        cout << count2 << endl;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tetramino[i][j]!='*' && (i-count2)>=0){
                    tetramino[i-count2][j] = tetramino[i][j];
                    tetramino[i][j] = '*';
                }
            }
        }
    }
    
}
