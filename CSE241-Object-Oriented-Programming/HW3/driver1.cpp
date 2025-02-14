#include "tetraminos.cpp"
#include "tetris.cpp"
#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

int main() {
    
    int x,y;
    cout << "The size of board is 9x6!" << endl;
    x = 6;
    y = 9;
    tetris t(y,x);
    t.get_vector_values();
    //t.print_board(t.board_elementss);

    char tetramino_type;

        cout << "The Tetramino type is S" << endl;
        tetramino_type = 'S';
        t.filling_array(tetramino_type,t.board_elementss,1);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is T" << endl;
        tetramino_type = 'T';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is I" << endl;
        tetramino_type = 'I';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is Z" << endl;
        tetramino_type = 'Z';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is O" << endl;
        tetramino_type = 'O';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is I" << endl;
        tetramino_type = 'I';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
       usleep(1000000);

        cout << "The Tetramino type is L" << endl;
        tetramino_type = 'L';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is S" << endl;
        tetramino_type = 'S';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);
    
        cout << "The Tetramino type is I" << endl;
        tetramino_type = 'I';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "The Tetramino type is J" << endl;
        tetramino_type = 'J';
        t.filling_array(tetramino_type,t.board_elementss,2);    
        t.print_board(t.board_elementss);
        usleep(1000000);

        cout << "Game Over!" << endl;

             
    return 0;
}