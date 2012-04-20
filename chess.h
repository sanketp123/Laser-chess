// All includes
#include<iostream>
#include<conio.h>

// All Macros
#define RED 1
#define Green 0
#define RTRIANGLE1 1
#define RTRIANGLE2 2
#define RTRIANGLE3 3
#define RTRIANGLE4 4
#define RTRIANGLE5 5
#define RTRIANGLE6 6
#define GTRIANGLE1 7
#define GTRIANGLE2 8
#define GTRIANGLE3 9
#define GTRIANGLE4 10
#define GTRIANGLE5 11
#define GTRIANGLE6 12
#define RSQUARE1   13
#define RSQUARE2   14
#define RSQUARE3   15
#define RSQUARE4   16
#define GSQUARE1   17
#define GSQUARE2   18
#define GSQUARE3   19
#define GSQUARE4   20
#define RLINESLANT1 21
#define RLINESLANT2 22
#define RLINE1      23
#define RLINE2      24
#define GLINESLANT1 25
#define GLINESLANT2 26
#define GLINE1      27
#define GLINE2      28
#define RSPLITTER   29
#define GSPLITTER   30
#define RKING       31
#define GKING       32
#define RGUN        33
#define GGUN        34
#define RHYPERCUBE  35
#define GHYPERCUBE  36


//All class definitions

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

// Global declarations

Triangle triangle_r1(RTRIANGLE1, 1); 
Triangle triangle_r2(RTRIANGLE2, 1); 
Triangle triangle_r3(RTRIANGLE3, 1); 
Triangle triangle_r4(RTRIANGLE4, 1); 
Triangle triangle_r5(RTRIANGLE5, 1); 
Triangle triangle_r6(RTRIANGLE6, 1); 
Triangle triangle_g1(GTRIANGLE1, 0); 
Triangle triangle_g2(GTRIANGLE2, 0); 
Triangle triangle_g3(GTRIANGLE3, 0); 
Triangle triangle_g4(GTRIANGLE4, 0); 
Triangle triangle_g5(GTRIANGLE5, 0); 
Triangle triangle_g6(GTRIANGLE6, 0); 

Square square_r1(RSQUARE1, 1);
Square square_r2(RSQUARE2, 1);
Square square_r3(RSQUARE3, 1);
Square square_r4(RSQUARE4, 1);
Square square_g1(GSQUARE1, 0);
Square square_g2(GSQUARE2, 0);
Square square_g3(GSQUARE3, 0);
Square square_g4(GSQUARE4, 0);

Slantline sline_r1(RLINESLANT1, 1);
Slantline sline_r2(RLINESLANT2, 1);
Slantline sline_g1(GLINESLANT1, 0);
Slantline sline_g2(GLINESLANT2, 0);

Line line_r1(RLINE1, 1);
Line line_r2(RLINE2, 1);
Line line_g1(GLINE1, 0);
Line line_g2(GLINE2, 0);

Splitter splitter_r(RSPLITTER, 1);
Splitter splitter_g(GSPLITTER, 0);

King king_r(RKING, 1);
King king_g(GKING, 0);

Gun gun_r(RGUN, 1);
Gun gun_g(GGUN, 0);

Hypercube hypercube_r(RHYPERCUBE, 1);
Hypercube hypercube_g(GHYPERCUBE, 0);


using namespace std;
