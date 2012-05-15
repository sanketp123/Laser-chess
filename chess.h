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
#define RSQUARE5   35
#define GSQUARE1   17
#define GSQUARE2   18
#define GSQUARE3   19
#define GSQUARE4   20
#define GSQUARE5   36
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
								int value;
								char name[50];
				public:
								Piece()
								{
												piece_id = -1;
												team = -1;
												value = -1;	
								}
								
								Piece(int x, int y, int z)
								{
												piece_id = x;
												team = y;
												value = z;
								}

								int getId()
								{
												return piece_id;
								}
								int getTeam()
								{
												return team;
								}
								int getValue()
								{
												return value;
								}

								virtual Piece * make_copy(){}
		
								virtual void change_orientation(){}			
								virtual void print_orientation(int){}										   
								virtual char * get_orientation(int){}			
};

class Board
{
				Piece *matrix[9][9];
				Piece * Piece_array[37];
				public:
				Board();
				void initialize(Board * b);
				void first_init();				
				void draw();
				int check_validity(int);
				int make_move(int, int);
				int rotate(int);
				void action(int);
				pos get_position(int);   
				void kill(int, int);
				int can_kill(int, int, int &);
				void beam(int, int, int);
				int stateDifference(Board, int);
				Board computeMoves(int);
				int computeGreenMoves(Board [], int, int []);
				int computeRedMoves(Board [], int, int []);
				void computePieceMove(int, int, int, int[], Board [], int);
				void computeNextLevelMoves(int, int, int, int, int, Board [], int[]);
				int find_cpu_state(int, int, int, int[]);
};

class Triangle : public Piece
{	
	char ox;
	char oy;
	
	public:
				Triangle(int x, int y, int z, char o1, char o2):Piece(x, y, z)
				{
					oy = o1;
					ox = o2;
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
			  char * get_orientation(int);			
				int reflect(int);			
				
};

class Square : public Piece
{
	char o;
	public:
				Square(int x, int y, int z, char o1):Piece(x, y, z)
				{
				o = o1;
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
			    char * get_orientation(int);
			    int reflect(int);						

};

class Slantline : public Piece
{
	char o;	
	public:
				Slantline(int x, int y, int z, char o1):Piece(x, y, z)
				{
					o = o1;
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
			    char * get_orientation(int);
			    int reflect(int);						
};

class Line : public Piece
{
	char o;
	public:

	Line(int x, int y, int z, char o1):Piece(x, y, z)
	{
		o = o1;
	}
	Piece *  make_copy();
	void change_orientation();
	void print_orientation(int);
	char * get_orientation(int);			
	int reflect(int);			
};

class Splitter : public Piece
{
	char o;
	public:
				Splitter(int x, int y, int z, char o1):Piece(x, y, z)
				{
					o = o1;
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
			    char * get_orientation(int);
				int reflect(Board *, int, int, int);					
};

class Gun : public Piece
{
	char o;
	public:
				Gun(int x, int y, int z, char o1):Piece(x, y, z)
				{
					o = o1;
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
				void shoot(Board * , int);
			    char * get_orientation(int);			
};

class King : public Piece
{
	public:
				King(int x, int y, int z):Piece(x, y, z)
				{
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
			    char * get_orientation(int);			
};

class Hypercube : public Piece
{
	public:
				Hypercube(int x, int y, int z):Piece(x, y, z)
				{
				}
				Piece *  make_copy();
				void change_orientation();
				void print_orientation(int);
			    char * get_orientation(int);			
};


using namespace std;
