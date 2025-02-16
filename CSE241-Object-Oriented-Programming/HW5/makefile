all: clean compile run

compile: driver1.cpp driver2.cpp abstractTetris.h TetrisArray1D.cpp TetrisAdapter.cpp TetrisAdapter.h TetrisArray1D.h tetris.cpp tetris.h tetramino.h tetramino.cpp
	@g++ -o test1 driver1.cpp -std=c++11
	@g++ -o test2 driver2.cpp -std=c++11

run:
	./test1
	./test2
	
clean:
	@rm -f *.o