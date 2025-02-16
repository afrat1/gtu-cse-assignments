#include "TetrisArray1D.cpp"
#include "TetrisAdapter.cpp"
#include "tetris.cpp"
#include "tetramino.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    char tetramino_type;
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;
    
    TetrisArray1D *arr2 = new TetrisArray1D(row,column);
    TetrisAdapter<int> tetrisAdapter(row,column);
    tetris *arr = new tetris(row, column);
    TetrisArray1D *arr_ = new TetrisArray1D(row,column);

    arr->get_vector_values();  
    arr2->getArray();
    tetrisAdapter.getArray();

    
    bool flag2 = true;
arr_->getArray();
    while(flag2){
        cout << "Enter the type of the Tetris class (V for vector, 1 for array1D, or A for adaptor, Q for quit!): ";
        string tetris_class_type;
        cin >> tetris_class_type;

        if (tetris_class_type == "V" || tetris_class_type == "v"){

            bool flag = true;
            while(flag){      
                cout << "Enter the tetramino type! You can enter R for random tetramino, Q for quit!" << endl;
                cin >> tetramino_type;

                if(tetramino_type == 'Q' || tetramino_type == 'q'){
                    cout << "Exited the program!\n";
                    flag = false;
                }
                
                else if(tetramino_type == 'R' || tetramino_type == 'r'){
                    tetramino b('a');

                    int rand_ = rand() % 7 + 1; 
                    if(rand_ == 1){
                        tetramino_type = 'T';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 2){
                        tetramino_type = 'L';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 3){
                        tetramino_type = 'I';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 4){
                        tetramino_type = 'O';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 5){
                        tetramino_type = 'S';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 6){
                        tetramino_type = 'J';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 7){
                        tetramino_type = 'Z';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                }
                else{
                    tetramino b('a');
                    b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                cout << "Vector Class Board" << endl;
            }
        }

        else if(tetris_class_type == "1"){
            //for the TetrisArray1D.h
            bool flag = true;
            while(flag){      
                cout << "Enter the tetramino type! You can enter R for random tetramino, Q for quit!" << endl;
                cin >> tetramino_type;

                if(tetramino_type == 'Q' || tetramino_type == 'q'){
                    cout << "Exited the program!\n";
                    flag = false;
                }
                
                else if(tetramino_type == 'R'  || tetramino_type == 'r'){
                    tetramino b('a');

                    int rand_ = rand() % 7 + 1; 
                    if(rand_ == 1){
                        tetramino_type = 'T';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 2){
                        tetramino_type = 'L';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 3){
                        tetramino_type = 'I';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 4){
                        tetramino_type = 'O';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 5){
                        tetramino_type = 'S';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 6){
                        tetramino_type = 'J';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 7){
                        tetramino_type = 'Z';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                }
                else{
                    tetramino b('a');
                    b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        arr2->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        arr2->tetraminoAtTop(arr2->gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        arr2->rotatedVersionAndMove(arr2->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                cout << "1D Array Board" << endl;
            }
        }

        else if(tetris_class_type == "A" || tetris_class_type == "a"){
            //for the TetrisAdapter.h
            bool flag = true;
            while(flag){      
                cout << "Enter the tetramino type! You can enter R for random tetramino, Q for quit!" << endl;
                cin >> tetramino_type;

                if(tetramino_type == 'Q' || tetramino_type == 'q'){
                    cout << "Exited the program!\n";
                    flag = false;
                }
                
                else if(tetramino_type == 'R'  || tetramino_type == 'r'){
                    tetramino b('a');

                    int rand_ = rand() % 7 + 1; 
                    if(rand_ == 1){
                        tetramino_type = 'T';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 2){
                        tetramino_type = 'L';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 3){
                        tetramino_type = 'I';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 4){
                        tetramino_type = 'O';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 5){
                        tetramino_type = 'S';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 6){
                        tetramino_type = 'J';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                    else if(rand_ == 7){
                        tetramino_type = 'Z';
                        b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                    }
                }
                else{
                    tetramino b('a');
                    b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
                        cout << "here";

                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

                        char rotationDirection, moveDirection;
                        int rotationCount, moveCount;
                        cout << "Enter the rotation direction! (R for right(clockwise) or L for left(counterclockwise)): ";
                        cin >> rotationDirection;
                        cout << "Enter the rotation count!";
                        cin >> rotationCount;

                        tetrisAdapter.rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
                        tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,b.arrD);
                    
                        cout << "Enter the move direction! (R for right or L for left): ";
                        cin >> moveDirection;
                        cout << "Enter the move count!";
                        cin >> moveCount;
                        tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                cout << "Adapter Class Board" << endl;
            }
        }

        else if(tetris_class_type == "Q" || tetris_class_type == "q"){
                    cout << "Exited the program!\n";
                    flag2 = false;
        }
        
        else{
            cout << "Try again!" << endl;
        }
    }

    return 0;
}