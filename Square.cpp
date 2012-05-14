#include "chess.h"

Piece * Square::make_copy()
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Square * T = new Square(piece_id, team, value, o);
	return (Piece *) T;
	//entry = (Piece **) &T;
	//array[piece_id] = &T;
	//Piece * p = & T;
	//return p;
}

void Square::change_orientation()
{
	if(o == 'N')
	{
		o = 'E';
	}
	else if(o == 'E')
	{
		o = 'S';
	}
	else if(o == 'S')
	{
		o = 'W'; 
	}
	else
	{
		o = 'N';
	}
}

void Square::print_orientation(int id)
{
	cout << id << " " << o << "\t";
}

char * Square::get_orientation(int id)
{
	char * ret = &o;
	return ret;
}

/*
 * returns thr direction in which the beam will be reflected.
 * If the piece has to be killed returns -1.
 * */
int Square::reflect(int dir)
{
	if(o == 'N')
	{
		if(dir == 2)
		{
			return 1;
		}
	}
	else if(o == 'S')
	{
		if(dir == 1)
		{
			return 2;
		}
	}
	else if(o == 'W')
	{
		if(dir == 3)
		{
			return 4;
		}
	}
	else if(o == 'E')
	{
		if(dir == 4)
		{
			return 3;
		}
	}
	
	return -1;	
	
}
