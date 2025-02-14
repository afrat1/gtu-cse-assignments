#include "tetraminos.cpp"
#include "tetris.cpp"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    
    int x,y;
    cout << "Enter the size of board? "<< endl;
    cin >> y;
    cin >> x;
    tetris t(y,x);
    t.get_vector_values();
    //t.print_board(t.board_elementss);

    char tetramino_type;

    vector<char>type_holder;
    bool flag = true;
    int size;
    while(flag){
        cout << "Enter the tetramino type! You can enter R for random tetramino, Q for quit!" << endl;
        cin >> tetramino_type;

        if(tetramino_type == 'Q'){
            cout << "Exited the program!\n";
            flag = false;
        }
        
        else if(tetramino_type == 'R'){
            int rand_ = rand() % 7 + 1; 
            if(rand_ == 1){
                tetramino_type = 'T';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
            else if(rand_ == 2){
                tetramino_type = 'L';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
            else if(rand_ == 3){
                tetramino_type = 'I';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
            else if(rand_ == 4){
                tetramino_type = 'O';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
            else if(rand_ == 5){
                tetramino_type = 'S';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
            else if(rand_ == 6){
                tetramino_type = 'Z';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
            else if(rand_ == 7){
                tetramino_type = 'J';
                type_holder.push_back(tetramino_type);
                size = type_holder.size(); 

                t.filling_array(tetramino_type,t.board_elementss,size);    
                t.print_board(t.board_elementss);
            }
        }
        
        else{
            type_holder.push_back(tetramino_type);
            size = type_holder.size(); 

            t.filling_array(tetramino_type,t.board_elementss,size);    
            t.print_board(t.board_elementss);
        }
    }
        
    return 0;
}