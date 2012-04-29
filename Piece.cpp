#include "chess.h"

class Piece
{
      protected:
                int piece_id;
                int team;
      
      public:
             Piece(int x, int y)
             {
                  piece_id = x;
                  team = y;
             }
             int getId()
             {
                 return piece_id;
             }
             int getTeam()
             {
                 return team;
             }
} ;

class Triangle : public Piece
{
      public:
             Triangle(int x, int y):Piece(x, y)
             {
             }
};

class Square : public Piece
{
      public:
             Square(int x, int y):Piece(x, y)
             {
             }
};

class Slantline : public Piece
{
      public:
             Slantline(int x, int y):Piece(x, y)
             {
             }
};

class Line : public Piece
{
	public:

             Line(int x, int y):Piece(x, y)
             {
             }
};

class Splitter : public Piece
{
      public:
             Splitter(int x, int y):Piece(x, y)
             {
             }
};

class Gun : public Piece
{
      public:
             Gun(int x, int y):Piece(x, y)
             {
             }
};

class King : public Piece
{
      public:
             King(int x, int y):Piece(x, y)
             {
             }
};

class Hypercube : public Piece
{
      public:
             Hypercube(int x, int y):Piece(x, y)
             {
             }
};

class Board
{
      Piece *matrix[9][9];
  public:
         Board();
         void draw(); 
            
};

