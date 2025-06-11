
import java.lang.InterruptedException;
import java.util.concurrent.TimeUnit;

public class Tetris {
    Tetramino t = new Tetramino(1);
    private char [][] array;
    public char[][] game_area;
    private final int row;
    private int column;

    public int getRow(){return row;}
    public int getColumn(){return column;}
    public Tetris(int row_i, int column_j){
        this.row = row_i;
        this.column = column_j;
        array = new char[row_i][column_j];
        for(int i=0;i<row_i;i++)
            for(int j=0;j<column_j;j++)
                array[i][j]=' ';
    }
    public void getArray(){
        array = new char[row][column];
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                array[i][j]=' ';
        game_area = array;
        /*
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                game_area[i][j] = array[i][j];
         */
    }

    public void printArray(char [][]gameArea){


        System.out.printf("X");
        for(int a = 0; a<column+1;a++)
            System.out.printf("X ");
        System.out.printf("\n");
        for(int i = 0;i<row;i++){
            System.out.printf("X");
            for(int j = 0;j<column;j++)
                System.out.printf(gameArea[i][j] + " ");
            System.out.printf("X ");
            System.out.printf("\n");
        }
        System.out.printf("X");
        for(int a = 0; a < column+1; a++)
            System.out.printf("X ");
        System.out.printf("\n");


    }

    public void tetraminoAtTop(char [][]gameArea,char [][]tetramino){
        int index = (column/2-2); //J=3
        int holder_value[] = new int [8];

        int a = 0;

        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if(i==0 && j==index){
                    for(int k=0;k<4;k++){
                        if(tetramino[i][k]!='*'){
                            gameArea[i][j+k] = tetramino[i][k];
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
                            gameArea[i][j+k] = tetramino[i][k];
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
                            gameArea[i][j+k] = tetramino[i][k];
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
                            gameArea[i][j+k] = tetramino[i][k];
                            holder_value[a]=i;
                            holder_value[a+1] = j+k;
                            a++;
                            a++;
                        }
                    }
                }
            }
        }
        try {
            TimeUnit.MILLISECONDS.sleep(75);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        //cout << "\033[2J" << endl;
        System.out.print("\033[H\033[2J");
        System.out.flush();
        printArray(gameArea);

        for(int i=0;i<8;i++){
            gameArea[holder_value[i]][holder_value[i+1]] = ' ';
            i++;
        }
    }

    public void rotatedVersionAndMove(char [][]gameArea,char [][]tetramino, char moveDirection, int moveCount){
        int index = (column/2-2); //J=3
        int holder_value[] = new int [8];
        char word_holder = 'a';
        int a = 0;

        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if(i==0 && j==index){
                    for(int k=0;k<4;k++){
                        if(tetramino[i][k]!='*'){
                            word_holder = tetramino[i][k];
                            gameArea[i][j+k] = tetramino[i][k];
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
                            gameArea[i][j+k] = tetramino[i][k];
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
                            gameArea[i][j+k] = tetramino[i][k];
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
                            gameArea[i][j+k] = tetramino[i][k];
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
            gameArea[holder_value[i]][holder_value[i+1]] = ' ';
            i++;
        }

        //sağa ya da sola kaydırma işlemini yaptı ve board'u yazdırdı
        if(moveDirection == 'R' || moveDirection == 'r'){
            for(int i=0;i<8;i++){
                gameArea[holder_value[i]][holder_value[i+1]+moveCount] = word_holder;
                i++;
            }
        }
        else if(moveDirection == 'L' || moveDirection == 'l'){
            for(int i=0;i<8;i++){
                gameArea[holder_value[i]][holder_value[i+1]-moveCount] = word_holder;
                i++;
            }
        }

        try {
            TimeUnit.MILLISECONDS.sleep(75);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        //cout << "\033[2J" << endl;
        System.out.print("\033[H\033[2J");
        System.out.flush();
        printArray(gameArea);
        System.out.printf("\n");

        try {
            TimeUnit.MILLISECONDS.sleep(75);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        //sağa sola hareket ettikten sonraki kısmı sildi
        for(int i=0;i<8;i++){
            if(moveDirection == 'R' || moveDirection == 'r'){
                gameArea[holder_value[i]][holder_value[i+1]+moveCount] = ' ';
                i++;
            }
            else if(moveDirection == 'L' || moveDirection == 'l'){
                gameArea[holder_value[i]][holder_value[i+1]-moveCount] = ' ';
                i++;
            }
        }

        boolean flag = true;
        boolean flag2 = true;
        boolean flag4 = true;
        boolean flag5 = true;
        int whichrow;
        flag4 = toCheckAnyTetramino(holder_value,gameArea,moveDirection,moveCount,word_holder); //aşağıda tetramino var onu biliyoruz
        whichrow = whichRow(holder_value,gameArea,moveDirection,moveCount,word_holder);
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
                        gameArea[holder_value[i]+j][holder_value[i+1]+moveCount] = word_holder;
                        i++;
                    }
                    else if(moveDirection == 'L' || moveDirection == 'l'){
                        gameArea[holder_value[i]+j][holder_value[i+1]-moveCount] = word_holder;
                        i++;
                    }
                }
                else{
                    if(whichrow==j+1){
                        flag5 = false;
                    }
                    if(moveDirection == 'R' || moveDirection == 'r'){
                        gameArea[holder_value[i]+j][holder_value[i+1]+moveCount] = word_holder;
                        i++;
                    }
                    else if(moveDirection == 'L' || moveDirection == 'l'){
                        gameArea[holder_value[i]+j][holder_value[i+1]-moveCount] = word_holder;
                        i++;
                    }
                }
            }
            try {
                TimeUnit.MILLISECONDS.sleep(75);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            //cout << "\033[2J" << endl;
            System.out.print("\033[H\033[2J");
            System.out.flush();
            printArray(gameArea);
            System.out.printf("\n");

            try {
                TimeUnit.MILLISECONDS.sleep(75);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

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
                        gameArea[holder_value[i]+j][holder_value[i+1]+moveCount] = ' ';
                        i++;
                    }
                    else if(moveDirection == 'L' || moveDirection == 'l'){
                        gameArea[holder_value[i]+j][holder_value[i+1]-moveCount] = ' ';
                        i++;
                    }
                }
            }
        }
    }

    public boolean toCheckAnyTetramino(int []holder_value,char [][]gameArea, char moveDirection, int moveCount,char wordHolder){
        int i,j;
        boolean flag = true;
        boolean flag2 = true;
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
                        if((gameArea[holder_value[i]+j][holder_value[i+1]+moveCount])!=' '){flag2=false;}
                        i++;
                    }
                    else if(moveDirection == 'L' || moveDirection == 'l'){
                        if((gameArea[holder_value[i]+j][holder_value[i+1]-moveCount])!=' '){flag2 = false;}
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

    public int whichRow(int []holder_value,char [][]gameArea, char moveDirection, int moveCount,char wordHolder){
        int i,j;
        boolean flag = true;
        boolean flag2 = true;
        int rowss = 1;
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
                        if((gameArea[holder_value[i]+j][holder_value[i+1]+moveCount])!=' '){flag2=false;}
                        i++;
                    }
                    else if(moveDirection == 'L' || moveDirection == 'l'){
                        if((gameArea[holder_value[i]+j][holder_value[i+1]-moveCount])!=' '){flag2 = false;}
                        i++;
                    }
                }
            }
            rowss = j;
        }
        return rowss;
    }

    public void rotate_suitable(char [][]tetramino, char rotationDirection, int rotationCount){
        if(rotationDirection == 'R' || rotationDirection == 'r'){
            if(rotationCount%4==0){}
            else if(rotationCount%4==1){t.rotate(tetramino);}
            else if(rotationCount%4==2){t.rotate(tetramino);t.rotate(tetramino);}
            else if(rotationCount%4==3){t.rotate(tetramino);t.rotate(tetramino);t.rotate(tetramino);}
        }
        else if(rotationDirection == 'L' || rotationDirection == 'l'){
            if(rotationCount%4==0){}
            else if(rotationCount%4==1){t.rotate(tetramino);t.rotate(tetramino);t.rotate(tetramino);}
            else if(rotationCount%4==2){t.rotate(tetramino);t.rotate(tetramino);}
            else if(rotationCount%4==3){t.rotate(tetramino);}
        }

    }

}
