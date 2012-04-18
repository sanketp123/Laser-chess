// All includes
#include<iostream>


// All Macros
#define RTRIANGLEM1 1
#define RTRIANGLEM2 2
#define RTRIANGLEM3 3
#define RTRIANGLEM4 4
#define RTRIANGLEM5 5
#define RTRIANGLEM6 6
#define GTRIANGLEM1 7
#define GTRIANGLEM2 8
#define GTRIANGLEM3 9
#define GTRIANGLEM4 10
#define GTRIANGLEM5 11
#define GTRIANGLEM6 12
#define RSQUARE1    13
#define RSQUAR2     14
#define RSQUARE3    15
#define RSQUARE4    16
#define GSQUARE1    17
#define GSQUARE2    18
#define GSQUARE3    19
#define GSQUARE4    20
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

class SlantLine : public Piece
{
      public:
             SlantLine(int x, int y):Piece(x, y)
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

class Hypercube : public Piece
{
      public:
             Hypercube(int x, int y):Piece(x, y)
             {
             }
};

class Board
{
      int matrix[9][9];
  public:
         void init();
         void draw(); 
            
};

// Global declarations
Board b;

using namespace std;
