# include "chess.h"

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
