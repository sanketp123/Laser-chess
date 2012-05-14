#include "chess.h"

void King::make_copy(Piece ** entry)
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	King *T = new King(piece_id, team, value);
	entry = (Piece **) &T;
	//array[piece_id] = &T;
	//Piece * p = & T;
	//return p;
}

void King::change_orientation()
{
	cout << "Invalid Operation! Cannot rotate the King\n";
}

void King::print_orientation(int id)
{
	cout << id << " 0" << "\t";
}

char * King::get_orientation(int id)
{
	return NULL;	
}
