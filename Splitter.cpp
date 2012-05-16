#include "chess.h"

Piece * Splitter::make_copy()
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Splitter * T = new Splitter(getName(), piece_id, team, value, o);
	return (Piece *) T;
}

void Splitter::change_orientation()
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

void Splitter::print_orientation(int id)
{
	cout << name << " " << id << " " << o << "\t";
}

char * Splitter::get_orientation(int id)
{
	char * ret = &o;
	return ret;
}

/*
 * returns thr direction in which the beam will be reflected.
 * If the piece has to be killed returns -1.
 * */
int Splitter::reflect(Board * b, int i, int j, int dir)
{
	if(o == 'N')
	{
		if(dir == 2)
		{
			//
			// Split the beam. One in E, other in W.
			//
			
			b->beam(i, j, 3);
			return 4;
		}
		else if(dir == 3 || dir == 4)
		{
			return 1;
		}		
	}
	else if(o == 'S')
	{
		if(dir == 1)
		{
			//
			// Split the beam. One in E, other in W.
			//
			
			b->beam(i, j, 3);
			return 4;
		}
		else if(dir == 3 || dir == 4)
		{
			return 2;
		}		
	}
	else if(o == 'W')
	{
		if(dir == 3)
		{
			//
			// Split the beam. One in N, other in S.
			//
			
			b->beam(i, j, 1);
			return 2;
		}
		else if(dir == 1 || dir == 2)
		{
			return 4;
		}		
	}
	else if(o == 'E')
	{
		if(dir == 4)
		{
			//
			// Split the beam. One in N, other in S.
			//
			
			b->beam(i, j, 1);
			return 2;
		}
		else if(dir == 1 || dir == 2)
		{
			return 3;
		}		
	}
	
	return -1;	
	
}

