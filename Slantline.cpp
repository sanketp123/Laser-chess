#include "chess.h"

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
