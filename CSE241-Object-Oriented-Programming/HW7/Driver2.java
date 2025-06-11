

import java.util.Random;
import java.util.Scanner;

public class Driver2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the row and column dimensions of the array:\n");
        int row = sc.nextInt();
        int column = sc.nextInt();

        Tetris arr1 = new Tetris(row,column);
        arr1.getArray();

        boolean flag = true;

        Scanner sca = new Scanner(System.in);

        while (flag) {
            System.out.println("Enter the tetramino type! You can enter R for random tetramino, Q for quit!");
            char tetramino_type = sca.next().charAt(0);

            if (tetramino_type == 'Q' || tetramino_type == 'q') {
                System.out.println("Exited the program!\n");
                flag = false;
            }

            else if(tetramino_type == 'R' || tetramino_type == 'r') {
                Tetramino t = new Tetramino(1);
                Random rand = new Random();
                int rand_ = rand.nextInt(7) + 1;

                if(rand_ == 1){
                    tetramino_type = 'T';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);

                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                else if(rand_ == 2){
                    tetramino_type = 'L';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);

                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                else if(rand_ == 3){
                    tetramino_type = 'I';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);

                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                else if(rand_ == 4){
                    tetramino_type = 'O';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);

                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                else if(rand_ == 5){
                    tetramino_type = 'S';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);

                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                else if(rand_ == 6){
                    tetramino_type = 'Z';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);

                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }
                else if(rand_ == 7){
                    tetramino_type = 'J';
                    t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                    arr1.tetraminoAtTop(arr1.game_area,t.arr);

                    char rotationDirection;
                    if (Math.random() < 0.5) {
                        rotationDirection = 'R';
                    } else {
                        rotationDirection = 'L';
                    }
                    int rotationCount = (int)(Math.random() * 4 + 1);
                    arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                    arr1.tetraminoAtTop(arr1.game_area, t.arr);

                    char moveDirection;
                    if (Math.random() < 0.5) {
                        moveDirection = 'R';
                    } else {
                        moveDirection = 'L';
                    }
                    int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                    arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
                }


            }
            else{

                Tetramino t = new Tetramino(1);
                t.assign_tetraminos(tetramino_type); //tetraminoları oluşturuyor
                arr1.tetraminoAtTop(arr1.game_area, t.arr); //en üstteki tetraminoyu oluşturuyor

                char rotationDirection;
                if (Math.random() < 0.5) {
                    rotationDirection = 'R';
                } else {
                    rotationDirection = 'L';
                }
                int rotationCount = (int)(Math.random() * 4 + 1);

                arr1.rotate_suitable(t.arr, rotationDirection, rotationCount); //döndürme işlemini yaptı
                arr1.tetraminoAtTop(arr1.game_area, t.arr);

                char moveDirection;
                if (Math.random() < 0.5) {
                    moveDirection = 'R';
                } else {
                    moveDirection = 'L';
                }
                int moveCount = (int)(Math.random() * ((column/2)-2) + 1);
                arr1.rotatedVersionAndMove(arr1.game_area, t.arr, moveDirection, moveCount); //sağa veya sola ilerliyor hem de aşağıya gidiyor
            }
        }
    }
}
