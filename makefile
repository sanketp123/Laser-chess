OBJECT_FILES = Board.o utils.o Triangle.o Square.o Slantline.o Line.o Splitter.o King.o Hypercube.o Gun.o 
CC = g++

all: Board 

Board: $(OBJECT_FILES)
	$(CC) -o Board $(OBJECT_FILES)

Board.o :  Board.cpp
	$(CC) -c Board.cpp
	
utils.o: utils.cpp
	$(CC) -c utils.cpp
	
Triangle.o: Triangle.cpp
	$(CC) -c Triangle.cpp		

Square.o: Square.cpp
	$(CC) -c Square.cpp		

Slantline.o: Slantline.cpp
	$(CC) -c Slantline.cpp		

Line.o: Line.cpp
	$(CC) -c Line.cpp		

Splitter.o: Splitter.cpp
	$(CC) -c Splitter.cpp		

King.o: King.cpp
	$(CC) -c King.cpp		

Hypercube.o: Hypercube.cpp
	$(CC) -c Hypercube.cpp		

Gun.o: Gun.cpp
	$(CC) -c Gun.cpp		

clean:
	rm *.o	
					
