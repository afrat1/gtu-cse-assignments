all: clean compile run

compile: main.cpp tetraminos.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ main.cpp -o test -std=c++11

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test