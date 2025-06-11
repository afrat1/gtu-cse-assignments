

public class Tetramino {
    public static char[][] arr;

    public Tetramino(int a){
        arr = new char[4][4];
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                arr[i][j]='*';
    }

    public void assign_tetraminos(char tetraminoType){
        if(tetraminoType == 'I'){
            arr[0][0] = 'I';
            arr[0][1] = 'I';
            arr[0][2] = 'I';
            arr[0][3] = 'I';
        }
        else if(tetraminoType == 'O'){
            arr[0][1] = 'O';
            arr[0][2] = 'O';
            arr[1][1] = 'O';
            arr[1][2] = 'O';
        }
        else if(tetraminoType == 'T'){
            arr[0][1] = 'T';
            arr[0][2] = 'T';
            arr[0][3] = 'T';
            arr[1][2] = 'T';
        }
        else if(tetraminoType == 'J'){
            arr[0][2] = 'J';
            arr[1][2] = 'J';
            arr[2][2] = 'J';
            arr[2][1] = 'J';
        }
        else if(tetraminoType == 'L'){
            arr[0][1] = 'L';
            arr[1][1] = 'L';
            arr[2][1] = 'L';
            arr[2][2] = 'L';
        }
        else if(tetraminoType == 'S'){
            arr[1][1] = 'S';
            arr[1][2] = 'S';
            arr[0][2] = 'S';
            arr[0][3] = 'S';
        }
        else if(tetraminoType == 'Z'){
            arr[0][3] = 'Z';
            arr[0][2] = 'Z';
            arr[1][2] = 'Z';
            arr[1][1] = 'Z';
        }
    }
    public void rotate(char tetramino[][]){
        int size = 4;
        char temp;
        for (int a = 0; a < size / 2; a++) {
            for (int b = a; b < size - a - 1; b++) {
                temp = tetramino[a][b];
                tetramino[a][b] = tetramino[size - 1 - b][a];
                tetramino[size - 1 - b][a] = tetramino[size - 1 - a][size - 1 - b];
                tetramino[size - 1 - a][size - 1 - b] = tetramino[b][size - 1 - a];
                tetramino[b][size - 1 - a] = temp;
            }
        }

        int count2 = 0;

        for(int i=0;i<4;i++){
            int count = 0;
            for(int j=0;j<4;j++){
                if(tetramino[i][j]=='*'){count++;}
            }
            if(count==4){count2++;}
        }

        if(count2!=0){
            System.out.printf("%d\n",count2);
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(tetramino[i][j]!='*' && (i-count2)>=0){
                        tetramino[i-count2][j] = tetramino[i][j];
                        tetramino[i][j] = '*';
                    }
                }
            }
        }
    }
}
