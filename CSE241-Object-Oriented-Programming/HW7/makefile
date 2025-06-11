all: clean compile run

compile: Driver1.java Driver2.java Tetramino.java Tetris.java 
	@echo "Compiling"
	@javac Driver1.java


compileAuto: Driver2.java Tetramino.java Tetris.java 

	@javac Driver2.java
	@java Driver2

compileManual: Driver1.java Tetramino.java Tetris.java 
	@echo "Compiling"
	@javac Driver1.java
	@java Driver1

run:

	@java Driver1
	@echo "Completed tests...."
	@javac Driver2.java
	@java Driver2
	

clean:
	
