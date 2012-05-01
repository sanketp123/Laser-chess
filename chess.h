// All includes
#include<iostream>

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
typedef struct
{
				int x;
				int y;
}pos;


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
								virtual void change_orientation(){}			
} ;

class Triangle : public Piece
{	
	char ox;
	char oy;
	
	public:
				Triangle(int x, int y, char o1, char o2):Piece(x, y)
				{
					oy = o1;
					ox = o2;
				}
				void change_orientation();
};

class Square : public Piece
{
	char o;
	public:
				Square(int x, int y, char o1):Piece(x, y)
				{
				o = o1;
				}
				void change_orientation();

};

class Slantline : public Piece
{
	char o;	
	public:
				Slantline(int x, int y, char o1):Piece(x, y)
				{
					o = o1;
				}
				void change_orientation();
};

class Line : public Piece
{
	char o;
	public:

	Line(int x, int y, char o1):Piece(x, y)
	{
		o = o1;
	}
	void change_orientation();
};

class Splitter : public Piece
{
	char o;
	public:
				Splitter(int x, int y, char o1):Piece(x, y)
				{
					o = o1;
				}
				void change_orientation();
};

class Gun : public Piece
{
	char o;
	public:
				Gun(int x, int y, char o1):Piece(x, y)
				{
					o = o1;
				}
				void change_orientation();
};

class King : public Piece
{
	public:
				King(int x, int y):Piece(x, y)
				{
				}
				void change_orientation();
};

class Hypercube : public Piece
{
	public:
				Hypercube(int x, int y):Piece(x, y)
				{
				}
				void change_orientation();
};

class Board
{
				Piece *matrix[9][9];
				public:
				Board();
				void draw();
				int check_validity(int);
				int make_move(int, int);
				int rotate(int);
				pos get_position(int);   
};

// Global declarations

Triangle triangle_r1(RTRIANGLE1, 1, 'S', 'E'); 
Triangle triangle_r2(RTRIANGLE2, 1, 'S', 'E'); 
Triangle triangle_r3(RTRIANGLE3, 1, 'S', 'W'); 
Triangle triangle_r4(RTRIANGLE4, 1, 'S', 'W'); 
Triangle triangle_r5(RTRIANGLE5, 1, 'S', 'W'); 
Triangle triangle_r6(RTRIANGLE6, 1, 'S', 'E'); 
Triangle triangle_g1(GTRIANGLE1, 0, 'N', 'E'); 
Triangle triangle_g2(GTRIANGLE2, 0, 'N', 'E'); 
Triangle triangle_g3(GTRIANGLE3, 0, 'N', 'W'); 
Triangle triangle_g4(GTRIANGLE4, 0, 'N', 'W'); 
Triangle triangle_g5(GTRIANGLE5, 0, 'N', 'W'); 
Triangle triangle_g6(GTRIANGLE6, 0, 'N', 'E'); 

Square square_r1(RSQUARE1, 1, 'S');
Square square_r2(RSQUARE2, 1, 'S');
Square square_r3(RSQUARE3, 1, 'S');
Square square_r4(RSQUARE4, 1, 'S');
Square square_g1(GSQUARE1, 0, 'N');
Square square_g2(GSQUARE2, 0, 'N');
Square square_g3(GSQUARE3, 0, 'N');
Square square_g4(GSQUARE4, 0, 'N');

Slantline sline_r1(RLINESLANT1, 1, '\\');
Slantline sline_r2(RLINESLANT2, 1, '/');
Slantline sline_g1(GLINESLANT1, 0, '/');
Slantline sline_g2(GLINESLANT2, 0, '\\');

Line line_r1(RLINE1, 1, 'V');
Line line_r2(RLINE2, 1, 'H');
Line line_g1(GLINE1, 0, 'H');
Line line_g2(GLINE2, 0, 'V');

Splitter splitter_r(RSPLITTER, 1, 'N');
Splitter splitter_g(GSPLITTER, 0, 'S');

King king_r(RKING, 1);
King king_g(GKING, 0);

Gun gun_r(RGUN, 1, 'S');
Gun gun_g(GGUN, 0, 'N');

Hypercube hypercube_r(RHYPERCUBE, 1);
Hypercube hypercube_g(GHYPERCUBE, 0);


using namespace std;
