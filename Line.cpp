#include "chess.h"

void Line::make_copy(Piece ** entry)
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Line  * T = new Line(piece_id, team, value, o);
	entry = (Piece **) &T;
	//array[piece_id] = &T;
	//Piece * p = & T;
	//return p;
}

void Line::change_orientation()
{
	if(o == 'V')
	{
		o = 'H';
	}
	else
	{
		o = 'V';
	}
	
}

void Line::print_orientation(int id)
{
	cout << id << " " << o << "\t";
}

char * Line::get_orientation(int id)
{
	char * ret = &o;
	return ret;
}

/*
 * returns thr direction in which the beam will be reflected.
 * */
int Line::reflect(int dir)
{
	if(o == 'V')
	{
		if(dir == 1)
		{
			return 1;
		}
		else if(dir == 2)
		{
			return 2;
		}
		else if(dir == 3)
		{
			return 4;
		}
		else
		{
			return 3;
		}
	}
	else 
	{
		if(dir == 1)
		{
			return 2;
		}
		else if(dir == 2)
		{
			return 1;
		}
		else if(dir == 3)
		{
			return 3;
		}
		else
		{
			return 4;
		}
	}
}
