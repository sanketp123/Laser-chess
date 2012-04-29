all: Board

Board: Board.o Piece.o
	g++ -o Board Board.o Piece.o

Piece.o : Piece.cpp
	g++ -c Piece.cpp 

Board.o :  Board.cpp
	g++ -c Board.cpp

clean :
	rm *.o	
					
