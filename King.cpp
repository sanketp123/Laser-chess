#include "chess.h"

Piece * King::make_copy()
{
	int piece_id = getId();
	int team = getTeam();
	int value = getValue();
	King *T = new King(getName(), piece_id, team, value);
	return (Piece *) T;
}

void King::change_orientation()
{
	cout << "Invalid Operation! Cannot rotate the King\n";
}

void King::print_orientation(int id)
{
	cout << name << " " << id << " 0" << "\t";
}

char * King::get_orientation(int id)
{
	return NULL;	
}
