#include <iostream>
#include <vector>
using namespace std;

enum class tets{ //enum definition
    T, L, I, O, S, Z, J
};

class tetraminos{
public:
    vector<vector<char>> arr;
    tetraminos(tets t);
    tetraminos(int a);
    //main functions
    void Rotate(); 
    void Print();
    bool canFit(tetraminos x, int location); 
private:
    
};

tetraminos::tetraminos(int a){
    arr = {{' '},{' '},{' '},{' '}};
}

tetraminos::tetraminos(tets t){
    if(static_cast<char>(t) == 'T'){
        arr = {
            {' ',' ', ' ', ' '},
            {' ',' ', ' ', ' '},
            {' ',' ', 'T', ' '},
            {' ','T', 'T', 'T'}
        };
    }
    else if(static_cast<char>(t) == 'L'){
        arr = {
            {' ',' ', ' ', ' '},
            {' ',' ', 'L', ' '},
            {' ',' ', 'L', ' '},
            {' ',' ', 'L', 'L'}
        };
    }
    else if(static_cast<char>(t) == 'I'){
        arr = {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'I', 'I', 'I', 'I'}
        };
    }
    else if(static_cast<char>(t) == 'O'){
        arr = {
            {' ',' ', ' ', ' '},
            {' ',' ', ' ', ' '},
            {' ',' ', 'O', 'O'},
            {' ',' ', 'O', 'O'}
        };
    }
    else if(static_cast<char>(t) == 'S'){
        arr = {
            {' ',' ', ' ', ' '},
            {' ',' ', ' ', ' '},
            {' ',' ', 'S', 'S'},
            {' ','S', 'S', ' '}
        };
    }
    else if(static_cast<char>(t) == 'Z'){
        arr = {
            {' ',' ', ' ', ' '},
            {' ',' ', ' ', ' '},
            {' ','Z', 'Z', ' '},
            {' ',' ', 'Z', 'Z'}
        };
    }
    else if(static_cast<char>(t) == 'J'){
        arr = {
            {' ',' ', ' ', ' '},
            {' ',' ', ' ', 'J'},
            {' ',' ', ' ', 'J'},
            {' ',' ', 'J', 'J'}
        };
    }
}

void tetraminos::Rotate(){ //rotating matrix by 90 degree in clockwise direction
    int size = arr.size();
    char temp;
	for (int a = 0; a < size / 2; a++) {
		for (int b = a; b < size - a - 1; b++) {
			temp = arr[a][b];
			arr[a][b] = arr[size - 1 - b][a];
			arr[size - 1 - b][a] = arr[size - 1 - a][size - 1 - b];
			arr[size - 1 - a][size - 1 - b] = arr[b][size - 1 - a];
			arr[b][size - 1 - a] = temp;
		}
	}
    /*
    for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
    */
}

void tetraminos::Print(){ //printing part
    int size = arr.size();
    for (int i = 0; i < size; i++){
		for (int j = 0; j < arr[i].size(); j++)
                if(i==0&&j==0){}
                else if(i==1&&j==0){}
                else if(i==2&&j==0){}
                else if(i==3&&j==0){}
                else{
                    cout << arr[i][j];
                }
                
		cout << '\n';
	}
}

bool tetraminos::canFit(tetraminos tet, int location){
	for(int i = 0; i < 4; i++){
		 for (int j = 0; j < 4; j++){
				arr[i].push_back(tet.arr[i][j]); //to add one after of the tetraminos
		    }    
		}

    /*
    int size = arr.size();

    for (int i = 0; i < size; i++){
		for (int j = 0; j < arr[i].size(); j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
    */
   return 0;
}