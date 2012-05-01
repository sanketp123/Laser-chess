#include "chess.h"

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
