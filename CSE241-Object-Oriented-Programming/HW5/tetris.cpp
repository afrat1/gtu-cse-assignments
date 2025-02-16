#include "tetris.h"
#include "tetramino.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
using namespace std;

tetramino t(1);


tetris::tetris(int row_i, int column_j):row(row_i),column(column_j)
{
    for(auto i=0;i<row_i;i++){ //It puts space characters in the array.
        vector<char>temp_arr;
        for(auto j=0;j<column_j;j++){
            temp_arr.push_back(' ');
        }
        array.push_back(temp_arr);
    }
}

void tetris::get_vector_values(){
    for (int i = 0; i <getRow(); i++){
        game_area.push_back(array[i]);
	}
}

void tetris::printArray(vector<vector<char>>gameArea){
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<column+1 ; a++) //cout << "\033[0;34m" << board[i][j] << "\033[0m";
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;
    for (int i = 0; i <row; i++){
        cout << "\033[0;34m"<< "X" << "\033[0m";
		for (int j = 0; j < column; j++)
			cout << gameArea[i][j] << " ";
        cout << "\033[0;34m"<< "X " << "\033[0m";
		cout << '\n';
	}
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<column+1 ; a++)
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;

}

void tetris::tetraminoAtTop(vector<vector<char>>gameArea,vector<vector<char>>tetramino){

    int index = (column/2-2); //J=3
    int holder_value[8];
    
    int a = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if(i==0 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
            else if(i==1 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
            else if(i==2 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
            else if(i==3 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
        }
    }
this_thread::sleep_for(std::chrono::milliseconds(75));
    cout << "\033[2J" << endl;
    printArray(gameArea);
    
    for(int i=0;i<8;i++){
        gameArea[holder_value[i]][holder_value[i+1]] = ' ';
        i++;
    }
    
}


void tetris::rotatedVersionAndMove(vector<vector<char>>gameArea,vector<vector<char>>tetramino,char moveDirection, int moveCount){

    int index = (column/2-2); //J=3
    int holder_value[8];
    char word_holder;
    int a = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if(i==0 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        word_holder = tetramino[i][k];
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
            else if(i==1 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
            else if(i==2 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
            else if(i==3 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameArea[i][j+k] = tetramino[i][k];
                        holder_value[a]=i;
                        holder_value[a+1] = j+k;
                        a++;
                        a++;
                    }
                }
            }
        }
    }
    //holdervalue'da harfin konum değerleri mevcut.

    //en başta ortadaki tetraminoyu sildi
    for(int i=0;i<8;i++){
        gameArea[holder_value[i]][holder_value[i+1]] = ' ';
        i++;
    }

    //sağa ya da sola kaydırma işlemini yaptı ve board'u yazdırdı
    if(moveDirection == 'R' || moveDirection == 'r'){
        for(int i=0;i<8;i++){
            gameArea[holder_value[i]][holder_value[i+1]+moveCount] = word_holder;
            i++;
        }
    }
    else if(moveDirection == 'L' || moveDirection == 'l'){
        for(int i=0;i<8;i++){
            gameArea[holder_value[i]][holder_value[i+1]-moveCount] = word_holder;
            i++;
        }
    }
    this_thread::sleep_for(std::chrono::milliseconds(75));
    cout << "\033[2J" << endl;
    printArray(gameArea);
    cout << endl;

    this_thread::sleep_for(chrono::milliseconds(10));

    //sağa sola hareket ettikten sonraki kısmı sildi
    for(int i=0;i<8;i++){
        if(moveDirection == 'R' || moveDirection == 'r'){
            gameArea[holder_value[i]][holder_value[i+1]+moveCount] = ' ';
            i++;
        }
        else if(moveDirection == 'L' || moveDirection == 'l'){
            gameArea[holder_value[i]][holder_value[i+1]-moveCount] = ' ';
            i++;
        }
    }
    
    bool flag = true;
    bool flag2 = true;
    bool flag4 = true;
    bool flag5 = true;
    int whichrow;
    flag4 = toCheckAnyTetramino(holder_value,gameArea,moveDirection,moveCount,word_holder); //aşağıda tetramino var onu biliyoruz
        whichrow = whichRow(holder_value,gameArea,moveDirection,moveCount,word_holder);
    for(int j = 1; j < row && flag2 && flag5;j++){
        
        for(int i = 0; i < 8 && flag;i++){
            for(int k = 0; k < 8 && flag; k++){
                if((holder_value[k]+j)==row){
                    flag = false;
                }
                k++;
            }
            if(flag&&flag4){ 
                if(moveDirection == 'R' || moveDirection == 'r'){
                    gameArea[holder_value[i]+j][holder_value[i+1]+moveCount] = word_holder;
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    gameArea[holder_value[i]+j][holder_value[i+1]-moveCount] = word_holder;
                    i++;
                }
            }
            else{
                if(whichrow==j+1){
                    flag5 = false;
                }
                if(moveDirection == 'R' || moveDirection == 'r'){
                    gameArea[holder_value[i]+j][holder_value[i+1]+moveCount] = word_holder;
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    gameArea[holder_value[i]+j][holder_value[i+1]-moveCount] = word_holder;
                    i++;
                }
            }     
        }
        this_thread::sleep_for(std::chrono::milliseconds(50));
        cout << "\033[2J" << endl;
        printArray(gameArea);
        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(10));

        flag2 = true;
        for(int k = 0; k < 8 && flag; k++){
                if((holder_value[k]+j+1)==row){
                    flag2 = false;
                }
                k++;
            }
        if(flag2 && flag5){
            for(int i=0;i<8;i++){
                if(moveDirection == 'R' || moveDirection == 'r'){
                    gameArea[holder_value[i]+j][holder_value[i+1]+moveCount] = ' ';
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    gameArea[holder_value[i]+j][holder_value[i+1]-moveCount] = ' ';
                    i++;
                }
            }
        }
    }
}

bool tetris::toCheckAnyTetramino(int *holder_value,vector<vector<char>>gameArea,char moveDirection,int moveCount,char wordHolder){
    int i,j;
    bool flag = true;
    bool flag2 = true;
    for(j=1;j<row&&flag2&&flag;j++){
        for(i=0;i<8&&flag&&flag2;i++){
            for(int k = 0; k < 8 && flag; k++){
                if((holder_value[k]+j)==row){
                    flag = false;
                }
                k++;
            } 

            if(flag2&&flag){
                if(moveDirection == 'R' || moveDirection == 'r'){
                    if((gameArea[holder_value[i]+j][holder_value[i+1]+moveCount])!=' '){flag2=false;}
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    if((gameArea[holder_value[i]+j][holder_value[i+1]-moveCount])!=' '){flag2 = false;}
                    i++;
                }
            }
        }
    }
    if(flag2==true){
        return true;
    }
    else{
        return false;
    }
}

int tetris::whichRow(int *holder_value,vector<vector<char>>gameArea,char moveDirection,int moveCount,char wordHolder){
    int i,j;
    bool flag = true;
    bool flag2 = true;
    int rowss;
    for(j=1;j<row&&flag2&&flag;j++){
        for(i=0;i<8&&flag&&flag2;i++){
            for(int k = 0; k < 8 && flag; k++){
                if((holder_value[k]+j)==row){
                    flag = false;
                }
                k++;
            } 

            if(flag2&&flag){
                if(moveDirection == 'R' || moveDirection == 'r'){
                    if((gameArea[holder_value[i]+j][holder_value[i+1]+moveCount])!=' '){flag2=false;}
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    if((gameArea[holder_value[i]+j][holder_value[i+1]-moveCount])!=' '){flag2 = false;}
                    i++;
                }
            }
        }
        rowss = j;
    }
    return rowss;
}


void tetris::rotate_suitable(vector<vector<char>>tetramino,char rotationDirection, int rotationCount){
    if(rotationDirection == 'R' || rotationDirection == 'r'){
        if(rotationCount%4==0){}
        else if(rotationCount%4==1){t.rotate(tetramino);}
        else if(rotationCount%4==2){t.rotate(tetramino);t.rotate(tetramino);}
        else if(rotationCount%4==3){t.rotate(tetramino);t.rotate(tetramino);t.rotate(tetramino);}
    }
    else if(rotationDirection == 'L' || rotationDirection == 'l'){
        if(rotationCount%4==0){}
        else if(rotationCount%4==1){t.rotate(tetramino);t.rotate(tetramino);t.rotate(tetramino);}
        else if(rotationCount%4==2){t.rotate(tetramino);t.rotate(tetramino);}
        else if(rotationCount%4==3){t.rotate(tetramino);}
    }
    
}


void tetris::draw(){
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<column+1 ; a++) //cout << "\033[0;34m" << board[i][j] << "\033[0m";
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;
    for (int i = 0; i <row; i++){
        cout << "\033[0;34m"<< "X" << "\033[0m";
		for (int j = 0; j < column; j++)
			cout << game_area[i][j] << " ";
        cout << "\033[0;34m"<< "X " << "\033[0m";
		cout << '\n';
	}
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<column+1 ; a++)
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;
}

void tetris::readsFromFile(){
    
ifstream file("output.txt");
/*
    vector<vector<int>> arrayy;
  string line;
  while (getline(file, line)) {
    vector<int> row;
    stringstream ss(line);
    int element;
    while (ss >> element) {
      row.push_back(element);
    }
    arrayy.push_back(row);
  }
*/
  // Close the file
  file.close();
  
}

void tetris::writeToFile(){
    std::ofstream output("output.txt");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            output << game_area[i][j] << " ";
        }
        output << std::endl;
    }
    output.close();
}

char tetris::lastMove(){
    return 'a';
}

int tetris::numberOfMoves(){
    return number_of_moves;
}