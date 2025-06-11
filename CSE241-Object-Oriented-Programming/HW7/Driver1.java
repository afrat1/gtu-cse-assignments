

public class Driver1 {
    public static void main(String[] args) {
        int row,column;
        row = 9;
        column = 9;

        Tetris arr1 = new Tetris(row,column);
        arr1.getArray();
        char rotationDirection, moveDirection;
        int rotationCount, moveCount;

        char tetramino_type;
        //#######################################
        Tetramino t = new Tetramino(1);
        tetramino_type = 'T';

        t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,t.arr);

        rotationDirection = 'R';
        rotationCount = 2;

        arr1.rotate_suitable(t.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,t.arr);

        moveDirection = 'R';
        moveCount = 3;
        arr1.rotatedVersionAndMove(arr1.game_area,t.arr,moveDirection,moveCount);

        //#######################################
        Tetramino a = new Tetramino(1);
        tetramino_type = 'I';

        a.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,a.arr);

        rotationDirection = 'R';
        rotationCount = 1;

        arr1.rotate_suitable(a.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,a.arr);

        moveDirection = 'R';
        moveCount = 3;
        arr1.rotatedVersionAndMove(arr1.game_area,a.arr,moveDirection,moveCount);

        //#######################################
        Tetramino c = new Tetramino(1);
        tetramino_type = 'O';

        c.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,c.arr);

        rotationDirection = 'L';
        rotationCount = 4;

        arr1.rotate_suitable(c.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,c.arr);

        moveDirection = 'L';
        moveCount = 3;
        arr1.rotatedVersionAndMove(arr1.game_area,c.arr,moveDirection,moveCount);

        //#######################################
        Tetramino e = new Tetramino(1);
        tetramino_type = 'T';

        e.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,e.arr);

        rotationDirection = 'L';
        rotationCount = 2;

        arr1.rotate_suitable(e.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,e.arr);

        moveDirection = 'L';
        moveCount = 1;
        arr1.rotatedVersionAndMove(arr1.game_area,e.arr,moveDirection,moveCount);

        //#######################################
        Tetramino f = new Tetramino(1);
        tetramino_type = 'I';

        f.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,f.arr);

        rotationDirection = 'L';
        rotationCount = 1;

        arr1.rotate_suitable(f.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,f.arr);

        moveDirection = 'R';
        moveCount = 0;
        arr1.rotatedVersionAndMove(arr1.game_area,f.arr,moveDirection,moveCount);

        //#######################################
        Tetramino b = new Tetramino(1);
        tetramino_type = 'L';

        b.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,b.arr);

        rotationDirection = 'L';
        rotationCount = 3;

        arr1.rotate_suitable(b.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,b.arr);

        moveDirection = 'L';
        moveCount = 3;
        arr1.rotatedVersionAndMove(arr1.game_area,b.arr,moveDirection,moveCount);

        //#######################################
        Tetramino g = new Tetramino(1);
        tetramino_type = 'S';

        g.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,g.arr);

        rotationDirection = 'L';
        rotationCount = 3;

        arr1.rotate_suitable(g.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,g.arr);

        moveDirection = 'L';
        moveCount = 4;
        arr1.rotatedVersionAndMove(arr1.game_area,g.arr,moveDirection,moveCount);

        //#######################################
        Tetramino k = new Tetramino(1);
        tetramino_type = 'O';

        k.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,k.arr);

        rotationDirection = 'L';
        rotationCount = 4;

        arr1.rotate_suitable(k.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,k.arr);

        moveDirection = 'R';
        moveCount = 0;
        arr1.rotatedVersionAndMove(arr1.game_area,k.arr,moveDirection,moveCount);

        //#######################################
        Tetramino s = new Tetramino(1);
        tetramino_type = 'S';

        s.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,s.arr);

        rotationDirection = 'R';
        rotationCount = 1;

        arr1.rotate_suitable(s.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,s.arr);

        moveDirection = 'R';
        moveCount = 2;
        arr1.rotatedVersionAndMove(arr1.game_area,k.arr,moveDirection,moveCount);

        //###############################
        Tetramino sa = new Tetramino(1);
        tetramino_type = 'J';

        sa.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,sa.arr);

        rotationDirection = 'R';
        rotationCount = 1;

        arr1.rotate_suitable(sa.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,sa.arr);

        moveDirection = 'L';
        moveCount = 1;
        arr1.rotatedVersionAndMove(arr1.game_area,sa.arr,moveDirection,moveCount);

        //###############################
        Tetramino saS = new Tetramino(1);
        tetramino_type = 'T';

        saS.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,saS.arr);

        rotationDirection = 'R';
        rotationCount = 4;

        arr1.rotate_suitable(saS.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,saS.arr);

        moveDirection = 'R';
        moveCount = 1;
        arr1.rotatedVersionAndMove(arr1.game_area,saS.arr,moveDirection,moveCount);

        //###############################
        Tetramino S = new Tetramino(1);
        tetramino_type = 'J';

        S.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
        arr1.tetraminoAtTop(arr1.game_area,S.arr);

        rotationDirection = 'R';
        rotationCount = 3;

        arr1.rotate_suitable(S.arr,rotationDirection,rotationCount);
        arr1.tetraminoAtTop(arr1.game_area,S.arr);

        moveDirection = 'L';
        moveCount = 2;
        arr1.rotatedVersionAndMove(arr1.game_area,S.arr,moveDirection,moveCount);

    }
}

