#include "TetrisArray1D.cpp"
#include "TetrisAdapter.cpp"
#include "tetris.cpp"
#include "tetramino.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

int main(){
    int row,column;
    //cout << "The size of board is 9x9!:\n";
    row = 9;
    column = 9;
    
    TetrisArray1D *arr2 = new TetrisArray1D(row,column);
    TetrisAdapter<int> tetrisAdapter(column,row);
    TetrisArray1D *arr_ = new TetrisArray1D(row,column);
    tetris *arr = new tetris(row, column);

    arr_->getArray();
    arr->get_vector_values();  
    arr2->getArray();
    tetrisAdapter.getArray();

    char rotationDirection, moveDirection;
    int rotationCount, moveCount;

    char tetramino_type;


    tetramino t('a');
    tetramino_type = 'T';
    t.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr_->tetraminoAtTop(arr_->gameOneArray,t.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'R';
    rotationCount = 1;

    arr_->rotate_suitable(t.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr_->tetraminoAtTop(arr_->gameOneArray,t.arrD);
            
    moveDirection = 'R';
    moveCount = 1;
    arr_->rotatedVersionAndMove(arr_->gameOneArray,t.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino a('a');
    tetramino_type = 'S';
    a.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr_->tetraminoAtTop(arr_->gameOneArray,a.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 1;

    arr_->rotate_suitable(a.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr_->tetraminoAtTop(arr_->gameOneArray,a.arrD);
            
    moveDirection = 'L';
    moveCount = 1;
    arr_->rotatedVersionAndMove(arr_->gameOneArray,a.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino b('a');
    tetramino_type = 'O';
    b.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 1;

    arr_->rotate_suitable(b.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr_->tetraminoAtTop(arr_->gameOneArray,b.arrD);
            
    moveDirection = 'L';
    moveCount = 3;
    arr_->rotatedVersionAndMove(arr_->gameOneArray,b.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino c('a');
    tetramino_type = 'O';
    c.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr_->tetraminoAtTop(arr_->gameOneArray,c.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 1;

    arr_->rotate_suitable(c.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr_->tetraminoAtTop(arr_->gameOneArray,c.arrD);
            
    moveDirection = 'L';
    moveCount = 3;
    arr_->rotatedVersionAndMove(arr_->gameOneArray,c.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino cA('a');
    tetramino_type = 'L';
    cA.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr_->tetraminoAtTop(arr_->gameOneArray,cA.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'R';
    rotationCount = 2;

    arr_->rotate_suitable(cA.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr_->tetraminoAtTop(arr_->gameOneArray,cA.arrD);
            
    moveDirection = 'R';
    moveCount = 3;
    arr_->rotatedVersionAndMove(arr_->gameOneArray,cA.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));

    cout << "Vector Class Board" << endl;

    this_thread::sleep_for(chrono::milliseconds(1000));
    
    tetramino d('a');
    tetramino_type = 'O';
    d.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr2->tetraminoAtTop(arr2->gameOneArray,d.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 1;

    arr2->rotate_suitable(d.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr2->tetraminoAtTop(arr2->gameOneArray,d.arrD);
            
    moveDirection = 'L';
    moveCount = 3;
    arr2->rotatedVersionAndMove(arr2->gameOneArray,d.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));

    
    tetramino e('a');
    tetramino_type = 'L';
    e.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr2->tetraminoAtTop(arr2->gameOneArray,e.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 1;

    arr2->rotate_suitable(e.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr2->tetraminoAtTop(arr2->gameOneArray,e.arrD);
            
    moveDirection = 'R';
    moveCount = 2;
    arr2->rotatedVersionAndMove(arr2->gameOneArray,e.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino f('a');
    tetramino_type = 'I';
    f.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr2->tetraminoAtTop(arr2->gameOneArray,f.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 1;

    arr2->rotate_suitable(f.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr2->tetraminoAtTop(arr2->gameOneArray,f.arrD);
            
    moveDirection = 'R';
    moveCount = 3;
    arr2->rotatedVersionAndMove(arr2->gameOneArray,f.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino g('a');
    tetramino_type = 'J';
    g.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr2->tetraminoAtTop(arr2->gameOneArray,g.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 2;

    arr2->rotate_suitable(g.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr2->tetraminoAtTop(arr2->gameOneArray,g.arrD);
            
    moveDirection = 'L';
    moveCount = 1;
    arr2->rotatedVersionAndMove(arr2->gameOneArray,g.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino gA('a');
    tetramino_type = 'T';
    gA.assign_tetraminos_1d(tetramino_type); //tetraminoları oluşturuyor
    arr2->tetraminoAtTop(arr2->gameOneArray,gA.arrD); //en üstteki tetraminoyu oluşturuyor

    rotationDirection = 'L';
    rotationCount = 2;

    arr2->rotate_suitable(gA.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    arr2->tetraminoAtTop(arr2->gameOneArray,gA.arrD);
            
    moveDirection = 'R';
    moveCount = 2;
    arr2->rotatedVersionAndMove(arr2->gameOneArray,gA.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor

    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "1D Array Board" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));


    tetramino aA('a');
    tetramino_type = 'T';
    aA.assign_tetraminos_1d(tetramino_type);
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,aA.arrD); //en üstteki tetraminoyu oluşturuyor
    
    rotationDirection = 'L';
    rotationCount = 2;
    tetrisAdapter.rotate_suitable(aA.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,aA.arrD);

    moveDirection = 'R';
    moveCount = 3;
                    
    tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,aA.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino j('a');
    tetramino_type = 'Z';
    j.assign_tetraminos_1d(tetramino_type);
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,j.arrD); //en üstteki tetraminoyu oluşturuyor
    
    rotationDirection = 'L';
    rotationCount = 2;
    tetrisAdapter.rotate_suitable(j.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,j.arrD);

    moveDirection = 'L';
    moveCount = 3;
                    
    tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,j.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino ja('a');
    tetramino_type = 'S';
    ja.assign_tetraminos_1d(tetramino_type);
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,ja.arrD); //en üstteki tetraminoyu oluşturuyor
    
    rotationDirection = 'R';
    rotationCount = 3;
    tetrisAdapter.rotate_suitable(ja.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,ja.arrD);

    moveDirection = 'R';
    moveCount = 0;
                    
    tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,ja.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino jb('a');
    tetramino_type = 'I';
    jb.assign_tetraminos_1d(tetramino_type);
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,jb.arrD); //en üstteki tetraminoyu oluşturuyor
    
    rotationDirection = 'R';
    rotationCount = 3;
    tetrisAdapter.rotate_suitable(jb.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,jb.arrD);

    moveDirection = 'L';
    moveCount = 2;
                    
    tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,jb.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
    this_thread::sleep_for(chrono::milliseconds(50));


    tetramino jAa('a');
    tetramino_type = 'S';
    jAa.assign_tetraminos_1d(tetramino_type);
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,jAa.arrD); //en üstteki tetraminoyu oluşturuyor
    
    rotationDirection = 'R';
    rotationCount = 3;
    tetrisAdapter.rotate_suitable(jAa.arrD,rotationDirection,rotationCount); //döndürme işlemini yaptı
    tetrisAdapter.tetraminoAtTop(tetrisAdapter.gameOneArray,jAa.arrD);

    moveDirection = 'R';
    moveCount = 3;
                    
    tetrisAdapter.rotatedVersionAndMove(tetrisAdapter.gameOneArray,jAa.arrD,moveDirection,moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "Adapter Class Board" << endl;
}