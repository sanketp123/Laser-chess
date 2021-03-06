#include "chess.h"

Piece * Gun::make_copy()
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Gun * T = new Gun(getName(), piece_id, team, value, o);
	return (Piece *) T;
}

void Gun::change_orientation()
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

void Gun::print_orientation(int id)
{
	cout << name << " " << id << " " << o << "\t";
}

char * Gun::get_orientation(int id)
{
	char * ret = &o;
	return ret;
}


void Gun::shoot(Board * b, int id)
{
	pos p = b->get_position(id);
	int i = p.x;
	int j = p.y;
	
	switch(o)
	{
		case 'N':
			b->beam(i, j, 1);
			break;
		case 'S':
			b->beam(i, j, 2);
			break;
		case 'E':
			b->beam(i, j, 3);
			break;
		case 'W':
			b->beam(i, j, 4);
			break;
	}	
}
