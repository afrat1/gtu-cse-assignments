#include "tetraminos.h"

int main() {

    int num;
    char input_shapes;

    cout << "How many tetrominos?" << "\n";
    cin >> num;
    cout << "What are the types?"<<endl;

    vector<tetraminos>type;
    tetraminos gameScreen(1);

    for(int i = 0; i < num ; i++){
        cin >> input_shapes;
        
        tets a = static_cast<tets>(input_shapes);
        
        tetraminos tet(a);
        /*
        if(input_shapes == 'T'){
            tet.Rotate();
            tet.Rotate();
        }
        */
        type.push_back(tet);
    }

    /*i can reach the functions with type*/

    for (int i = 0; i < type.size(); i++) {
        type[i].Print(); //prints down
    }

    for (int i = 0; i < type.size(); i++) {
        //type[i].Rotate();
    }

    for (int i = 0; i < type.size(); i++) {
        gameScreen.canFit(type[i],1); //reaching the canFit function
    }
    
    cout << "\n\nThe Output:"<< endl;

    gameScreen.Print(); //doing the final printing part

    return 0;
}