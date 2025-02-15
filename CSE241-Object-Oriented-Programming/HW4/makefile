all: clean compile run

compile: main.cpp DayofYear.cpp DayofYear.h
	@g++ -o test1 main.cpp -std=c++11

run:
	./test1
	./test1>res.txt
	
clean:
	@rm -f *.o