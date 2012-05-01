#include "chess.h"

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
