#include "tetris.h"
#include "tetraminos.h"
#include <iostream>
#include <vector>
using namespace std;

tetris::tetris(int y, int x){
    x_size = x;
    y_size = y;
    vector<int>temp_arr;

    for(auto i=0;i<y;i++){ //It puts space characters in the array.
        vector<char>temp_arr;
        for(auto j=0;j<x;j++){
            temp_arr.push_back(' ');
        }
        board_size.push_back(temp_arr);
    }
}

void tetris::get_vector_values(){ //It access the elements of array at private

    for (int i = 0; i <y_size; i++){
        board_elementss.push_back(board_size[i]);
		for (int j = 0; j < x_size; j++){

        }
	}
}

void tetris::print_board(vector<vector<char>>board){ //it prints the board anytime it called
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<x_size+1 ; a++) //cout << "\033[0;34m" << board[i][j] << "\033[0m";
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;
    for (int i = 0; i <y_size; i++){
        cout << "\033[0;34m"<< "X" << "\033[0m";
		for (int j = 0; j < x_size; j++)
			cout << board[i][j] << " ";
        cout << "\033[0;34m"<< "X" << "\033[0m";
		cout << '\n';
	}
    cout << "\033[0;34m"<< "X" << "\033[0m";
    for(int a=0 ; a<x_size+1 ; a++)
        cout << "\033[0;34m"<< "X " << "\033[0m";
    cout << endl;
}

void tetris::T_shapes(vector<vector<char>>&board,int size){ //It accesses the T tetramino and does the rotation.
    bool flag = true;
    if(size==1){ //bu çalıştı
        for(int i = y_size-1; i > 1 && flag; i--){
            for(int j = 0; j < x_size-2 && flag; j++){
                if(board[i][j]==' ' && board[i][j+1] == ' ' && board[i][j+2] == ' ' && board[i-1][j+1] == ' '){
                    board[i][j]='T';
                    board[i][j+1] = 'T';
                    board[i][j+2] = 'T';
                    board[i-1][j+1] = 'T';
                    
                    flag = false;
                }
            }
        }    
    }

    else{
        int i_value = bosluk_check_i(board,0);
        int j_value = bosluk_check_j(board,0);
        int first_i_space = i_value; 
        int first_j_space = j_value;
        
        if(board[i_value][j_value]==' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value] == ' '){T_shapes_locate_1(board,i_value,j_value);}
        else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_2(board,i_value,j_value);}
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_3(board,i_value,j_value);}
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value-1] == ' '){T_shapes_locate_4(board,i_value,j_value);}
        else{
            i_value = bosluk_check_i(board,i_value);
            j_value = bosluk_check_j(board,j_value);
            int second_i_space = i_value; 
            int second_j_space = j_value;
            if(board[i_value][j_value]==' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value] == ' '){T_shapes_locate_1(board,i_value,j_value);}
            else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_2(board,i_value,j_value);}
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_3(board,i_value,j_value);}
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value-1] == ' '){T_shapes_locate_4(board,i_value,j_value);}
            else{
                i_value = bosluk_check_i_2(board,first_i_space,first_j_space,i_value,j_value);
                j_value = bosluk_check_j_2(board,first_i_space,first_j_space,i_value,j_value);
                int third_i_space = i_value;
                int third_j_space = j_value;
                if(board[i_value][j_value]==' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value] == ' '){T_shapes_locate_1(board,i_value,j_value);}
                else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_2(board,i_value,j_value);}
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_3(board,i_value,j_value);}
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value-1] == ' '){T_shapes_locate_4(board,i_value,j_value);}
                else{
                    i_value = bosluk_check_i_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    j_value = bosluk_check_j_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    int forth_i_space = i_value;
                    int forth_j_space = j_value;
                    if(board[i_value][j_value]==' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value] == ' '){T_shapes_locate_1(board,i_value,j_value);}
                    else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_2(board,i_value,j_value);}
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_3(board,i_value,j_value);}
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value-1] == ' '){T_shapes_locate_4(board,i_value,j_value);}
                    else{
                        i_value = bosluk_check_i_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        j_value = bosluk_check_j_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        if(board[i_value][j_value]==' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value] == ' '){T_shapes_locate_1(board,i_value,j_value);}
                        else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_2(board,i_value,j_value);}
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_3(board,i_value,j_value);}
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value-1] == ' '){T_shapes_locate_4(board,i_value,j_value);}
                        else{
                            i_value = bosluk_check_i_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            j_value = bosluk_check_j_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            if(board[i_value][j_value]==' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value] == ' '){T_shapes_locate_1(board,i_value,j_value);}
                            else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_2(board,i_value,j_value);}
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value+1] == ' '){T_shapes_locate_3(board,i_value,j_value);}
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-1][j_value-1] == ' '){T_shapes_locate_4(board,i_value,j_value);}
                        }
                    }
                }
            }
        }
    }    
}

void tetris::L_shapes(vector<vector<char>>&board,int size){ //It accesses the L tetramino and does the rotation.
    bool flag = true;
    if(size == 1){
        for(int i = y_size-3; i > 1 && flag; i--){
            for(int j = 0; j < x_size-2 && flag; j++){
                    if(board[i][j]==' ' && board[i+1][j] == ' ' && board[i+2][j] == ' ' && board[i+2][j+1] == ' '){
                        board[i][j]='L';
                        board[i+1][j] = 'L';
                        board[i+2][j] = 'L';
                        board[i+2][j+1] = 'L';
                        flag = false;
                    }
            }
        }
    }
 
    else{
        int i_value = bosluk_check_i(board,0);
        int j_value = bosluk_check_j(board,0);
        int first_i_space = i_value; 
        int first_j_space = j_value;

        if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+2] == ' '){
            L_shapes_locate_1(board,i_value,j_value);
        }
        else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value-1] == ' '){
            L_shapes_locate_2(board,i_value,j_value);
        }
        
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value][j_value+1] == ' '){
            L_shapes_locate_3(board,i_value,j_value);
        }
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
            L_shapes_locate_4(board,i_value,j_value);
        }
        else{
            i_value = bosluk_check_i(board,i_value);
            j_value = bosluk_check_j(board,j_value);
            int second_i_space = i_value; 
            int second_j_space = j_value;

            if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+2] == ' '){
                L_shapes_locate_1(board,i_value,j_value);
            }
            else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value-1] == ' '){
                L_shapes_locate_2(board,i_value,j_value);
            }
        
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value][j_value+1] == ' '){
                L_shapes_locate_3(board,i_value,j_value);
            }
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                L_shapes_locate_4(board,i_value,j_value);
            }
            else{
                i_value = bosluk_check_i_2(board,first_i_space,first_j_space,i_value,j_value);
                j_value = bosluk_check_j_2(board,first_i_space,first_j_space,i_value,j_value);
                int third_i_space = i_value;
                int third_j_space = j_value;
                if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+2] == ' '){
                    L_shapes_locate_1(board,i_value,j_value);
                }
                else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value-1] == ' '){
                    L_shapes_locate_2(board,i_value,j_value);
                }
        
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value][j_value+1] == ' '){
                    L_shapes_locate_3(board,i_value,j_value);
                }
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                    L_shapes_locate_4(board,i_value,j_value);
                }
                else{
                    i_value = bosluk_check_i_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    j_value = bosluk_check_j_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    int forth_i_space = i_value;
                    int forth_j_space = j_value;
                    if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+2] == ' '){
                        L_shapes_locate_1(board,i_value,j_value);
                    }
                    else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value-1] == ' '){
                        L_shapes_locate_2(board,i_value,j_value);
                    }
        
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value][j_value+1] == ' '){
                        L_shapes_locate_3(board,i_value,j_value);
                    }   
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                        L_shapes_locate_4(board,i_value,j_value);
                    }
                    else{
                        i_value = bosluk_check_i_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        j_value = bosluk_check_j_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+2] == ' '){
                            L_shapes_locate_1(board,i_value,j_value);
                        }
                        else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value-1] == ' '){
                            L_shapes_locate_2(board,i_value,j_value);
                        }
        
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value][j_value+1] == ' '){
                            L_shapes_locate_3(board,i_value,j_value);
                        }   
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                            L_shapes_locate_4(board,i_value,j_value);
                        }
                        else{
                            i_value = bosluk_check_i_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            j_value = bosluk_check_j_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value-1][j_value+2] == ' '){
                                L_shapes_locate_1(board,i_value,j_value);
                            }
                            else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value-1] == ' '){
                                L_shapes_locate_2(board,i_value,j_value);
                            }
        
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value][j_value+1] == ' '){
                                L_shapes_locate_3(board,i_value,j_value);
                            }   
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                                L_shapes_locate_4(board,i_value,j_value);
                            }
                        }
                    }
                    
                }
            }
        }
    }
}

void tetris::I_shapes(vector<vector<char>>&board,int size){ ////It accesses the I tetramino and does the rotation.
    bool flag = true;
    if(size ==1){
        for(int i = y_size-1; i > 2 && flag; i--){
            for(int j = 0; j < x_size && flag; j++){
                    if(board[i][j]==' ' && board[i-1][j] == ' ' && board[i-2][j] == ' ' && board[i-3][j] == ' '){
                        board[i][j]='I';
                        board[i-1][j] = 'I';
                        board[i-2][j] = 'I';
                        board[i-3][j] = 'I';
                        flag = false;
                    }
            }
        }
    }

    else{
        int i_value = bosluk_check_i(board,0);
        int j_value = bosluk_check_j(board,0);
        int first_i_space = i_value; 
        int first_j_space = j_value;

        if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value][j_value+3] == ' '){
            I_shapes_locate_1(board,i_value,j_value);
        }
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-3][j_value] == ' '){
            I_shapes_locate_2(board,i_value,j_value);
        }
        
        else{
            i_value = bosluk_check_i(board,i_value);
            j_value = bosluk_check_j(board,j_value);
            int second_i_space = i_value; 
            int second_j_space = j_value;
            if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value][j_value+3] == ' '){
                I_shapes_locate_1(board,i_value,j_value);
            }
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-3][j_value] == ' '){
                I_shapes_locate_2(board,i_value,j_value);
            }
            else{
                i_value = bosluk_check_i_2(board,first_i_space,first_j_space,i_value,j_value);
                j_value = bosluk_check_j_2(board,first_i_space,first_j_space,i_value,j_value);
                int third_i_space = i_value;
                int third_j_space = j_value;
                if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value][j_value+3] == ' '){
                    I_shapes_locate_1(board,i_value,j_value);
                }
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-3][j_value] == ' '){
                    I_shapes_locate_2(board,i_value,j_value);
                }
                else{
                    i_value = bosluk_check_i_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    j_value = bosluk_check_j_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    int forth_i_space = i_value;
                    int forth_j_space = j_value;
                    if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value][j_value+3] == ' '){
                        I_shapes_locate_1(board,i_value,j_value);
                    }
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-3][j_value] == ' '){
                        I_shapes_locate_2(board,i_value,j_value);
                    }
                    else{
                        i_value = bosluk_check_i_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        j_value = bosluk_check_j_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value][j_value+3] == ' '){
                            I_shapes_locate_1(board,i_value,j_value);
                        }
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-3][j_value] == ' '){
                            I_shapes_locate_2(board,i_value,j_value);
                        }
                        else{
                            i_value = bosluk_check_i_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            j_value = bosluk_check_j_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' ' && board[i_value][j_value+3] == ' '){
                                I_shapes_locate_1(board,i_value,j_value);
                            }
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-3][j_value] == ' '){
                                I_shapes_locate_2(board,i_value,j_value);
                            }
                        }
                    }
                }
            }
        }
    }
}

void tetris::O_shapes(vector<vector<char>>&board){ ////It accesses the O tetramino and does the rotation.
    bool flag = true;
    //zaten o yu ne kadar döndürürsem döndüreyim değişen bişey olmayacak
    for(int i = y_size-1; i > 1 && flag; i--){
        for(int j = 0; j < x_size-2 && flag; j++){
                if(board[i][j]==' ' && board[i][j+1] == ' ' && board[i-1][j] == ' ' && board[i-1][j+1] == ' '){
                    board[i][j]='O';
                    board[i][j+1] = 'O';
                    board[i-1][j] = 'O';
                    board[i-1][j+1] = 'O';
                    flag = false;
                }
        }
    }
}

void tetris::S_shapes(vector<vector<char>>&board,int size){ ////It accesses the S tetramino and does the rotation.
    bool flag = true;
    if(size==1){
        for(int i = y_size-1; i > 1 && flag; i--){
            for(int j = 0; j < x_size-2 && flag; j++){
                    if(board[i][j]==' ' && board[i][j+1] == ' ' && board[i-1][j+1] == ' ' && board[i-1][j+2] == ' '){
                        board[i][j]='S';
                        board[i][j+1] = 'S';
                        board[i-1][j+1] = 'S';
                        board[i-1][j+2] = 'S';
                        flag = false;
                    }
            }
        }
    }

    else{
        int i_value = bosluk_check_i(board,0);
        int j_value = bosluk_check_j(board,0);
        int first_i_space = i_value; 
        int first_j_space = j_value;

        if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
            S_shapes_locate_1(board,i_value,j_value);
        }
        else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
            S_shapes_locate_2(board,i_value,j_value);
        }
        
        else{
            int i_value = bosluk_check_i(board,i_value);
            int j_value = bosluk_check_j(board,j_value);
            int second_i_space = i_value; 
            int second_j_space = j_value;

            if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                S_shapes_locate_1(board,i_value,j_value);
            }
            else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                S_shapes_locate_2(board,i_value,j_value);
            }
            else{
                i_value = bosluk_check_i_2(board,first_i_space,first_j_space,i_value,j_value);
                j_value = bosluk_check_j_2(board,first_i_space,first_j_space,i_value,j_value);
                int third_i_space = i_value;
                int third_j_space = j_value;
                if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                    S_shapes_locate_1(board,i_value,j_value);
                }
                else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                    S_shapes_locate_2(board,i_value,j_value);
                }
                else{
                    i_value = bosluk_check_i_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    j_value = bosluk_check_j_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    int forth_i_space = i_value;
                    int forth_j_space = j_value;
                    if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                        S_shapes_locate_1(board,i_value,j_value);
                    }
                    else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                        S_shapes_locate_2(board,i_value,j_value);
                    }
                    else{
                        i_value = bosluk_check_i_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        j_value = bosluk_check_j_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                            S_shapes_locate_1(board,i_value,j_value);
                        }
                        else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                            S_shapes_locate_2(board,i_value,j_value);
                        }
                        else{
                            i_value = bosluk_check_i_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            j_value = bosluk_check_j_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-1][j_value+2] == ' '){
                                S_shapes_locate_1(board,i_value,j_value);
                            }
                            else if(board[i_value][j_value]==' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                                S_shapes_locate_2(board,i_value,j_value);
                            }
                        }
                    }
                }
            }
        }
    }
}

void tetris::Z_shapes(vector<vector<char>>&board,int size){ ////It accesses the Z tetramino and does the rotation.
    bool flag = true;
    if(size == 1){
        for(int i = y_size-1; i > 2 && flag; i--){
            for(int j = 0; j < x_size-1 && flag; j++){
                    if(board[i][j]==' ' && board[i-1][j] == ' ' && board[i-1][j+1] == ' ' && board[i-2][j+1] == ' '){
                        board[i][j]='Z';
                        board[i-1][j] = 'Z';
                        board[i-1][j+1] = 'Z';
                        board[i-2][j+1] = 'Z';
                        flag = false;
                    }
            }
        }                
    }

    else{
        int i_value = bosluk_check_i(board,0);
        int j_value = bosluk_check_j(board,0);
        int first_i_space = i_value; 
        int first_j_space = j_value;

        if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
            Z_shapes_locate_1(board,i_value,j_value);
        }
        else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value+1][j_value+1] == ' ' && board[i_value+1][j_value+2] == ' '){
            Z_shapes_locate_2(board,i_value,j_value);
        }
        else{
            int i_value = bosluk_check_i(board,i_value);
            int j_value = bosluk_check_j(board,j_value);
            int second_i_space = i_value; 
            int second_j_space = j_value;
            
            if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                Z_shapes_locate_1(board,i_value,j_value);
            }
            else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value+1][j_value+1] == ' ' && board[i_value+1][j_value+2] == ' '){
                Z_shapes_locate_2(board,i_value,j_value);
            }
            else{
                i_value = bosluk_check_i_2(board,first_i_space,first_j_space,i_value,j_value);
                j_value = bosluk_check_j_2(board,first_i_space,first_j_space,i_value,j_value);
                int third_i_space = i_value;
                int third_j_space = j_value;

                if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                    Z_shapes_locate_1(board,i_value,j_value);
                }
                else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value+1][j_value+1] == ' ' && board[i_value+1][j_value+2] == ' '){
                    Z_shapes_locate_2(board,i_value,j_value);
                }
                else{
                    i_value = bosluk_check_i_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    j_value = bosluk_check_j_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    int forth_i_space = i_value;
                    int forth_j_space = j_value;
                    
                    if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                        Z_shapes_locate_1(board,i_value,j_value);
                    }
                    else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value+1][j_value+1] == ' ' && board[i_value+1][j_value+2] == ' '){
                        Z_shapes_locate_2(board,i_value,j_value);
                    }
                    else{
                        i_value = bosluk_check_i_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        j_value = bosluk_check_j_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                            Z_shapes_locate_1(board,i_value,j_value);
                        }
                        else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value+1][j_value+1] == ' ' && board[i_value+1][j_value+2] == ' '){
                            Z_shapes_locate_2(board,i_value,j_value);
                        }
                        else{
                            i_value = bosluk_check_i_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            j_value = bosluk_check_j_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                                Z_shapes_locate_1(board,i_value,j_value);
                            }
                            else if(board[i_value][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value+1][j_value+1] == ' ' && board[i_value+1][j_value+2] == ' '){
                                Z_shapes_locate_2(board,i_value,j_value);
                            }
                            else{
                                cout <<  "here\n";
                            }
                        }
                    }
                }
            }
        }
    }  
}

void tetris::J_shapes(vector<vector<char>>&board,int size){//It accesses the J tetramino and does the rotation.
    bool flag = true;
    if(size == 1){
        for(int i = y_size-1; i > 1 && flag; i--){
            for(int j = 0; j < x_size-2 && flag; j++){
                    if(board[i][j]==' ' && board[i-1][j] == ' ' && board[i][j+1] == ' ' && board[i][j+2] == ' '){
                        board[i][j]='J';
                        board[i-1][j] = 'J';
                        board[i][j+1] = 'J';
                        board[i][j+2] = 'J';
                        flag = false;
                }
            }
        }
    }

    else{
        int i_value = bosluk_check_i(board,0);
        int j_value = bosluk_check_j(board,0);
        int first_i_space = i_value; 
        int first_j_space = j_value;
 
        if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' '){
            J_shapes_locate_1(board,i_value,j_value);
        }
        else if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
            J_shapes_locate_2(board,i_value,j_value);
        }
        
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value+1] == ' '){
            J_shapes_locate_3(board,i_value,j_value);
        }
        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value-2] == ' '){
            J_shapes_locate_4(board,i_value,j_value);
        }
        else{
            i_value = bosluk_check_i(board,i_value);
            j_value = bosluk_check_j(board,j_value);
            int second_i_space = i_value; 
            int second_j_space = j_value;
            if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' '){
                J_shapes_locate_1(board,i_value,j_value);
            }
            else if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                J_shapes_locate_2(board,i_value,j_value);
            }
        
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value+1] == ' '){
                J_shapes_locate_3(board,i_value,j_value);
            }
            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value-2] == ' '){
                J_shapes_locate_4(board,i_value,j_value);
            }
            else{
                i_value = bosluk_check_i_2(board,first_i_space,first_j_space,i_value,j_value);
                j_value = bosluk_check_j_2(board,first_i_space,first_j_space,i_value,j_value);
                int third_i_space = i_value;
                int third_j_space = j_value;
                if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' '){
                    J_shapes_locate_1(board,i_value,j_value);
                }
                else if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                    J_shapes_locate_2(board,i_value,j_value);
                }
        
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value+1] == ' '){
                    J_shapes_locate_3(board,i_value,j_value);
                }
                else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value-2] == ' '){
                    J_shapes_locate_4(board,i_value,j_value);
                }
                else{
                    i_value = bosluk_check_i_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    j_value = bosluk_check_j_3(board,first_i_space,first_j_space,second_i_space,second_j_space,i_value,j_value);
                    int forth_i_space = i_value;
                    int forth_j_space = j_value;
                    if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' '){
                        J_shapes_locate_1(board,i_value,j_value);
                    }
                    else if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                        J_shapes_locate_2(board,i_value,j_value);
                    }
        
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value+1] == ' '){
                        J_shapes_locate_3(board,i_value,j_value);
                    }
                    else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value-2] == ' '){
                        J_shapes_locate_4(board,i_value,j_value);
                    }
                    else{
                        i_value = bosluk_check_i_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        j_value = bosluk_check_j_4(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,i_value,j_value);
                        if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' '){
                            J_shapes_locate_1(board,i_value,j_value);
                        }
                        else if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                            J_shapes_locate_2(board,i_value,j_value);
                        }
        
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value+1] == ' '){
                            J_shapes_locate_3(board,i_value,j_value);
                        }
                        else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value-2] == ' '){
                            J_shapes_locate_4(board,i_value,j_value);
                        }
                        else{
                            i_value = bosluk_check_i_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            j_value = bosluk_check_j_5(board,first_i_space,first_j_space,second_i_space,second_j_space,third_i_space,third_j_space,forth_i_space,forth_j_space,i_value,j_value);
                            if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value][j_value+1] == ' ' && board[i_value][j_value+2] == ' '){
                                J_shapes_locate_1(board,i_value,j_value);
                            }
                            else if(board[i_value][j_value]==' ' && board[i_value][j_value+1] == ' ' && board[i_value-1][j_value+1] == ' ' && board[i_value-2][j_value+1] == ' '){
                                J_shapes_locate_2(board,i_value,j_value);
                            }
        
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-2][j_value] == ' ' && board[i_value-2][j_value+1] == ' '){
                                J_shapes_locate_3(board,i_value,j_value);
                            }
                            else if(board[i_value][j_value] == ' ' && board[i_value-1][j_value] == ' ' && board[i_value-1][j_value-1] == ' ' && board[i_value-1][j_value-2] == ' '){
                                J_shapes_locate_4(board,i_value,j_value);
                            }
                        }
                    }
                }
            }
        }
    }    
}

void tetris::filling_array(char tetramino_type,vector<vector<char>> & board,int size){

    //tetraminos t(tetramino_type);

    if(tetramino_type == 'T'){
        T_shapes(board,size);
    }

    if(tetramino_type == 'L'){
        L_shapes(board,size);
    }
    
    if(tetramino_type == 'I'){
        I_shapes(board,size);
    }
    
    if(tetramino_type == 'O'){
        O_shapes(board);
    }

    if(tetramino_type == 'S'){
        S_shapes(board,size);
    }

    if(tetramino_type == 'Z'){
        Z_shapes(board,size);
    }

    if(tetramino_type == 'J'){
        J_shapes(board,size);
    }
    
}

int tetris::bosluk_check_i(vector<vector<char>>&board,int invalid_i){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;

    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i){

                    }
                    else{
                        value = i;
                        flag = false; 
                    }
                }
            }
        }
    }

    
    return value;
}

int tetris::bosluk_check_i_2(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else{
                        value = i;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_i_3(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else if(invalid_i3 == i && invalid_j3 == j){

                    }
                    else{
                        value = i;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_i_4(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invalid_j4){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else if(invalid_i3 == i && invalid_j3 == j){

                    }
                    else if(invalid_i4 == i && invalid_j4 == j){

                    }
                    else{
                        value = i;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_i_5(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invalid_j4,int invalid_i5,int invalid_j5){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else if(invalid_i3 == i && invalid_j3 == j){

                    }
                    else if(invalid_i4 == i && invalid_j4 == j){

                    }
                    else if(invalid_i5 == i && invalid_j5 == j){

                    }
                    else{
                        value = i;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_j(vector<vector<char>>&board,int invalid_j){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;

    if(invalid_j == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = j;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_j == i){

                    }
                    else{
                        value = j;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_j_2(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;

    if(invalid_j == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else{
                        value = j;
                        flag = false; 
                    }
                }
            }
        }
    }

    
    return value;
}

int tetris::bosluk_check_j_3(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else if(invalid_i3 == i && invalid_j3 == j){

                    }
                    else{
                        value = j;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_j_4(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invalid_j4){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else if(invalid_i3 == i && invalid_j3 == j){

                    }
                    else if(invalid_i4 == i && invalid_j4 == j){

                    }
                    else{
                        value = j;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

int tetris::bosluk_check_j_5(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invalid_j4,int invalid_i5,int invalid_j5){ //It controls the gaps and ensures that it becomes fit.
    int value;
    bool flag = true;
    if(invalid_i == 0){
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    value = i;
                    flag = false;  
                }
            }
        }
    }
    else{
        for(int i = y_size-1 ; i > 1 && flag ; i--){
            for(int j = 0 ; j < x_size && flag ; j++){
                if(board[i][j] == ' '){
                    if(invalid_i == i && invalid_j == j){

                    }
                    else if(invalid_i2 == i && invalid_j2 == j){

                    }
                    else if(invalid_i3 == i && invalid_j3 == j){

                    }
                    else if(invalid_i4 == i && invalid_j4 == j){

                    }
                    else if(invalid_i5 == i && invalid_j5 == j){
                        
                    }
                    else{
                        value = j;
                        flag = false; 
                    }
                }
            }
        }
    }

    return value;
}

void tetris::T_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'T';
    board[i_value-1][j_value+1] = 'T';
    board[i_value-1][j_value-1] = 'T';
    board[i_value-1][j_value] = 'T';
}

void tetris::T_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'T';
    board[i_value][j_value+1] = 'T';
    board[i_value][j_value+2] = 'T';
    board[i_value-1][j_value+1] = 'T';
}

void tetris::T_shapes_locate_3(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'T';
    board[i_value-1][j_value] = 'T';
    board[i_value-2][j_value] = 'T';
    board[i_value-1][j_value+1] = 'T';
}

void tetris::T_shapes_locate_4(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'T';
    board[i_value-1][j_value] = 'T';
    board[i_value-2][j_value] = 'T';
    board[i_value-1][j_value-1] = 'T';
}

void tetris::L_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'L';
    board[i_value][j_value+1] = 'L';
    board[i_value][j_value+2] = 'L';
    board[i_value-1][j_value+2] = 'L';
}

void tetris::L_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'L';
    board[i_value-1][j_value] = 'L';
    board[i_value-2][j_value] = 'L';
    board[i_value-2][j_value-1] = 'L';
}

void tetris::L_shapes_locate_3(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'L';
    board[i_value-1][j_value] = 'L';
    board[i_value-2][j_value] = 'L';
    board[i_value][j_value+1] = 'L';
}

void tetris::L_shapes_locate_4(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'L';
    board[i_value-1][j_value] = 'L';
    board[i_value-1][j_value+1] = 'L';
    board[i_value-1][j_value+2] = 'L';
}

void tetris::I_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'I';
    board[i_value][j_value+1] = 'I';
    board[i_value][j_value+2] = 'I';
    board[i_value][j_value+3] = 'I';
}

void tetris::I_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'I';
    board[i_value-1][j_value] = 'I';
    board[i_value-2][j_value] = 'I';
    board[i_value-3][j_value] = 'I';
}

void tetris::S_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'S';
    board[i_value][j_value+1] = 'S';
    board[i_value-1][j_value+1] = 'S';
    board[i_value-1][j_value+2] = 'S';
}

void tetris::S_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'S';
    board[i_value-1][j_value] = 'S';
    board[i_value-1][j_value+1] = 'S';
    board[i_value-2][j_value+1] = 'S';
}

void tetris::Z_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const{ 
    board[i_value][j_value] = 'Z';
    board[i_value-1][j_value] = 'Z';
    board[i_value-1][j_value+1] = 'Z';
    board[i_value-2][j_value+1] = 'Z';
}

void tetris::Z_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'Z';
    board[i_value][j_value+1] = 'Z';
    board[i_value+1][j_value+1] = 'Z';
    board[i_value+1][j_value+2] = 'Z';
}

void tetris::J_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'J';
    board[i_value-1][j_value] = 'J';
    board[i_value][j_value+1] = 'J';
    board[i_value][j_value+2] = 'J';
}

void tetris::J_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'J';
    board[i_value][j_value+1] = 'J';
    board[i_value-1][j_value+1] = 'J';
    board[i_value-2][j_value+1] = 'J';
}

void tetris::J_shapes_locate_3(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'J';
    board[i_value-1][j_value] = 'J';
    board[i_value-2][j_value] = 'J';
    board[i_value-2][j_value+1] = 'J';
}

void tetris::J_shapes_locate_4(vector<vector<char>>&board,int i_value,int j_value) const{
    board[i_value][j_value] = 'J';
    board[i_value-1][j_value] = 'J';
    board[i_value-1][j_value-1] = 'J';
    board[i_value-1][j_value-2] = 'J';
}
