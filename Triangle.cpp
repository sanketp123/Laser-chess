# include "chess.h"

Piece * Triangle::make_copy()
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Triangle * T = new Triangle(getName(), piece_id, team, value, oy, ox);
	return (Piece *) T;
	
}

void Triangle::change_orientation()
{
	if(oy == 'N' && ox == 'W')
	{
		ox = 'E';
	}
	else if(oy == 'N' && ox == 'E')
	{
		oy = 'S';
	}
	else if(oy == 'S' && ox == 'E')
	{
		ox = 'W'; 
	}
	else
	{
		oy = 'N';
	}
}

void Triangle::print_orientation(int id)
{
	cout << name << " " << id << " " << oy	<< " " << ox << "\t";
}

char * Triangle::get_orientation(int id)
{
	char * ret = new char(3);
	* ret = ox;
	* (ret + 1) = ' ';
	* (ret + 2) =  oy;
	return ret;
}

/*
 * returns thr direction in which the beam will be reflected.
 * If the piece has to be killed returns -1.
 * */
int Triangle::reflect(int dir)
{
	if(oy == 'N' && ox == 'W')
	{
		if(dir == 2)
		{
			return 4;
		}
		else if(dir == 3)
		{
			return 1;	
		}
		
	}
	else if(oy == 'N' && ox == 'E')
	{
		if(dir == 2)
		{
			return 3;
		}
		else if(dir == 4)
		{
			return 1;	
		}
	}
	else if(oy == 'S' && ox == 'W')
	{
		if(dir == 1)
		{
			return 4;
		}
		else if(dir == 3)
		{
			return 2;	
		}		
	}
	else if(oy == 'S' && ox == 'E')
	{
		if(dir == 1)
		{
			return 3;
		}
		else if(dir == 4)
		{
			return 2;	
		}		
	}
	
	return -1;	
	
}
