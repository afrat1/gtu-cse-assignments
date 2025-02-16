#include "TetrisArray1D.h"
#include "tetramino.h"
#include "tetris.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std;

tetramino c('a');

TetrisArray1D::TetrisArray1D(int row_i, int column_j) : row(row_i) , column(column_j)
{   
    oneArray = new char[row_i*column_j];

    for(int i=0;i<row_i;i++){
        for(int j=0;j<column_j;j++)
            oneArray[i*column_j+j] = ' ';
    }
}

void TetrisArray1D::getArray(){
    gameOneArray = new char[row*column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            gameOneArray[i*column+j]= oneArray[i*column+j] ;
            
}

void TetrisArray1D::draw(){
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

void TetrisArray1D::readsFromFile(){
     
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

void TetrisArray1D::writeToFile(){
    std::ofstream output("output.txt");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            output << game_area[i][j] << " ";
        }
        output << std::endl;
    }
    output.close();
}

char TetrisArray1D::lastMove(){
    return 'a';
}

int TetrisArray1D::numberOfMoves(){
    return number_of_moves;
}

void TetrisArray1D::printArray(char* gameOneArray){
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<column+1 ; a++) //cout << "\033[0;34m" << board[i][j] << "\033[0m";
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;
    for (int i = 0; i <row; i++){
        cout << "\033[0;34m"<< "X" << "\033[0m";
		for (int j = 0; j < column; j++)
			cout << gameOneArray[i*getColumn()+j] << " ";
        cout << "\033[0;34m"<< "X " << "\033[0m";
		cout << '\n';
	}
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<column+1 ; a++)
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;

}

void TetrisArray1D::tetraminoAtTop(char* gameOneArray,char **tetramino){

    int index = (column/2-2); //J=3
    int holder_value[8];
    
    int a = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if(i==0 && j==index){
                for(int k=0;k<4;k++){
                    if(tetramino[i][k]!='*'){
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
    printArray(gameOneArray);
    
    for(int i=0;i<8;i++){
        
        gameOneArray[holder_value[i]*getColumn()+holder_value[i+1]] = ' ';
        i++;
    }
    
}

void TetrisArray1D::rotatedVersionAndMove(char* gameOneArray,char **tetramino,char moveDirection, int moveCount){

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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
                        gameOneArray[i*getColumn()+j+k] = tetramino[i][k];
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
        gameOneArray[holder_value[i]*getColumn()+holder_value[i+1]] = ' ';
        i++;
    }

    //sağa ya da sola kaydırma işlemini yaptı ve board'u yazdırdı
    if(moveDirection == 'R' || moveDirection == 'r'){
        for(int i=0;i<8;i++){
            gameOneArray[holder_value[i]*getColumn()+holder_value[i+1]+moveCount] = word_holder;
            i++;
        }
    }
    else if(moveDirection == 'L' || moveDirection == 'l'){
        for(int i=0;i<8;i++){
            gameOneArray[holder_value[i]*getColumn()+holder_value[i+1]-moveCount] = word_holder;
            i++;
        }
    }
    this_thread::sleep_for(std::chrono::milliseconds(75));
    cout << "\033[2J" << endl;
    printArray(gameOneArray);
    cout << endl;

    this_thread::sleep_for(chrono::milliseconds(10));

    //sağa sola hareket ettikten sonraki kısmı sildi
    for(int i=0;i<8;i++){
        if(moveDirection == 'R' || moveDirection == 'r'){
            gameOneArray[holder_value[i]*getColumn()+holder_value[i+1]+moveCount] = ' ';
            i++;
        }
        else if(moveDirection == 'L' || moveDirection == 'l'){
            gameOneArray[holder_value[i]*getColumn()+holder_value[i+1]-moveCount] = ' ';
            i++;
        }
    }
    
    bool flag = true;
    bool flag2 = true;
    bool flag4 = true;
    bool flag5 = true;
    int whichrow;
    flag4 = toCheckAnyTetramino(holder_value,gameOneArray,moveDirection,moveCount,word_holder); //aşağıda tetramino var onu biliyoruz
        whichrow = whichRow(holder_value,gameOneArray,moveDirection,moveCount,word_holder);
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
                    //gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]+moveCount]
                    gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]+moveCount] = word_holder;
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]-moveCount] = word_holder;
                    i++;
                }
            }
            else{
                if(whichrow==j+1){
                    flag5 = false;
                }
                if(moveDirection == 'R' || moveDirection == 'r'){
                    gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]+moveCount] = word_holder;
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]-moveCount]  = word_holder;
                    i++;
                }
            }     
        }
        this_thread::sleep_for(std::chrono::milliseconds(50));
        cout << "\033[2J" << endl;
        printArray(gameOneArray);
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
                    gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]+moveCount] = ' ';
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]-moveCount] = ' ';
                    i++;
                }
            }
        }
    }


    ofstream output("output.txt");

    output << "X";
    for(int a=0 ; a<column+1 ; a++) //cout << "\033[0;34m" << board[i][j] << "\033[0m";
        output << "X ";
    output << endl;
    for (int i = 0; i <row; i++){
        output << "X";
		for (int j = 0; j < column; j++)
			output << gameOneArray[i*getColumn()+j] << " ";
        output << "X ";
		output << '\n';
	}
    output << "X";
    for(int a=0 ; a<column+1 ; a++)
        output << "X ";
    output << endl;

    output.close();


}

bool TetrisArray1D::toCheckAnyTetramino(int *holder_value,char* gameOneArray,char moveDirection,int moveCount,char wordHolder){
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
                    if((gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]+moveCount])!=' '){flag2=false;}
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    if((gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]-moveCount])!=' '){flag2 = false;}
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

int TetrisArray1D::whichRow(int *holder_value,char* gameOneArray,char moveDirection,int moveCount,char wordHolder){
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
                    if((gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]+moveCount])!=' '){flag2=false;}
                    i++;
                }
                else if(moveDirection == 'L' || moveDirection == 'l'){
                    if((gameOneArray[(holder_value[i]+j)*getColumn()+holder_value[i+1]-moveCount])!=' '){flag2 = false;}
                    i++;
                }
            }
        }
        rowss = j;
    }
    return rowss;
}

void TetrisArray1D::rotate_suitable(char **tetramino,char rotationDirection, int rotationCount){
    if(rotationDirection == 'R' || rotationDirection == 'r'){
        if(rotationCount%4==0){}
        else if(rotationCount%4==1){c.rotate1Darray(tetramino);}
        else if(rotationCount%4==2){c.rotate1Darray(tetramino);c.rotate1Darray(tetramino);}
        else if(rotationCount%4==3){c.rotate1Darray(tetramino);c.rotate1Darray(tetramino);c.rotate1Darray(tetramino);}
    }
    else if(rotationDirection == 'L' || rotationDirection == 'l'){
        if(rotationCount%4==0){}
        else if(rotationCount%4==1){c.rotate1Darray(tetramino);c.rotate1Darray(tetramino);c.rotate1Darray(tetramino);}
        else if(rotationCount%4==2){c.rotate1Darray(tetramino);c.rotate1Darray(tetramino);}
        else if(rotationCount%4==3){c.rotate1Darray(tetramino);}
    }
    
}
