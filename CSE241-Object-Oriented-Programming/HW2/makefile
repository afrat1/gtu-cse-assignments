all: clean compile run

compile: driver1.cpp driver2.cpp tetris.cpp tetris.h tetraminos.h tetraminos.cpp
	@g++ -o test1 driver1.cpp -std=c++11
	@g++ -o test2 driver2.cpp -std=c++11

run:
	./test1
	./test2
	
clean:
	@rm -f *.o