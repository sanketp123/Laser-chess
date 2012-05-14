#include "chess.h"

Piece * Hypercube::make_copy()
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	Hypercube * T = new Hypercube(piece_id, team, value);
	return (Piece *) T;
	//entry = (Piece **) &T;
	//array[piece_id] = &T;
	//Piece * p = & T;
	//return p;
}

void Hypercube::change_orientation()
{
	cout << "Invalid Operation! Cannot rotate the Hypercube\n";
}

void Hypercube::print_orientation(int id)
{
	cout << id << " 0" << "\t";
}

char * Hypercube::get_orientation(int id)
{
	return NULL;	
}

