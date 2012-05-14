#include "chess.h"

void Slantline::make_copy(Piece ** entry)
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Slantline  * T = new Slantline(piece_id, team, value, o);
	entry = (Piece **) &T;
	//array[piece_id] = &T;
	//Piece * p = & T;
	//return p;
}

void Slantline::change_orientation()
{
	if(o == '\\')
	{
		o = '/';
	}
	else
	{
		o = '\\';
	}
}

void Slantline::print_orientation(int id)
{
	cout << id << " " << o << "\t";
}

char * Slantline::get_orientation(int id)
{
	char * ret = &o;
	return ret;
}

/*
 * returns thr direction in which the beam will be reflected.
 * */
int Slantline::reflect(int dir)
{
	if(o == '\\')
	{
		if(dir == 1)
		{
			return 4;
		}
		else if(dir == 2)
		{
			return 3;
		}
		else if(dir == 3)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else 
	{
		if(dir == 1)
		{
			return 3;
		}
		else if(dir == 2)
		{
			return 4;
		}
		else if(dir == 3)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}
