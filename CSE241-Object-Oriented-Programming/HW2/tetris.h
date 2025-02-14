#include <iostream>
#include <vector>
using namespace std;

#ifndef TETRIS
#define TETRIS
class tetris{
public:
    tetris(int y, int x);
    vector<vector<char>>board_elementss;  
    void print_board(vector<vector<char>>board);
    void get_vector_values();
    void filling_array(char tetramino_type,vector<vector<char>>&board,int size);

    void T_shapes(vector<vector<char>>&board,int size);
    void T_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const;
    void T_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const;
    void T_shapes_locate_3(vector<vector<char>>&board,int i_value,int j_value) const;
    void T_shapes_locate_4(vector<vector<char>>&board,int i_value,int j_value) const;

    void L_shapes(vector<vector<char>>&board,int size);
    void L_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const;
    void L_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const;
    void L_shapes_locate_3(vector<vector<char>>&board,int i_value,int j_value) const; 
    void L_shapes_locate_4(vector<vector<char>>&board,int i_value,int j_value) const;

    void I_shapes(vector<vector<char>>&board,int size);
    void I_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const;
    void I_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const;

    void O_shapes(vector<vector<char>>&board);

    void S_shapes(vector<vector<char>>&board,int size);
    void S_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const; 
    void S_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const;

    void Z_shapes(vector<vector<char>>&board,int size);
    void Z_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const;
    void Z_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const;

    void J_shapes(vector<vector<char>>&board,int size);
    void J_shapes_locate_1(vector<vector<char>>&board,int i_value,int j_value) const;
    void J_shapes_locate_2(vector<vector<char>>&board,int i_value,int j_value) const;
    void J_shapes_locate_3(vector<vector<char>>&board,int i_value,int j_value) const;
    void J_shapes_locate_4(vector<vector<char>>&board,int i_value,int j_value) const;

    int bosluk_check_i(vector<vector<char>>&board,int invalid_i);
    int bosluk_check_i_2(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2);
    int bosluk_check_i_3(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3);
    int bosluk_check_i_4(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invali_j4);
    int bosluk_check_i_5(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invali_j4,int invalid_i5,int invali_j5);
    int bosluk_check_j(vector<vector<char>>&board,int invalid_j);
    int bosluk_check_j_2(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2);
    int bosluk_check_j_3(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3);
    int bosluk_check_j_4(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invalid_j4);
    int bosluk_check_j_5(vector<vector<char>>&board,int invalid_i,int invalid_j,int invalid_i2,int invalid_j2,int invalid_i3,int invalid_j3,int invalid_i4,int invalid_j4,int invalid_i5,int invali_j5);

    

private:
    int x_size; //en
    int y_size; //yükseklik
    vector<vector<char>>board_size; //dolu şu an
};

#endif