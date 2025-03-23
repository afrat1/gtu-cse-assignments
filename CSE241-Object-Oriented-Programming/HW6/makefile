all: clean compile run

compile: main.cpp PFArray.cpp PFArray.h
	@g++ -o test1 main.cpp -std=c++11
run:
	./test1	
clean:
	@rm -f *.o