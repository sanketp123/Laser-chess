# include "chess.h"
# include <stdlib.h>

int Board::check_validity(int id)
{
		pos p = get_position(id);
		if(p.x == -1)
		{
				return 0;
		}
		else
		{
				return 1;
		}
}	

void Board::draw()
{
		int i = 0, j =0;

		//
		// Draw the Board.
		//

		for(i = 0; i < 9; i ++)
		{
				for(j = 0; j < 9; j++)
				{
						if(matrix[i][j] != NULL)
						{
								if((matrix[i][j]->getId() / 10) == 0)
								{
										cout << " |  " << matrix[i][j]->getId() << " ";
								}	
								else
								{
										cout <<" | " << matrix[i][j]->getId() <<" ";
								}	
						}		
						else
						{
								cout <<" |    "; 
						}	
				}
				cout << " |" <<endl;
		}

		//
		// Print the Orientation of the Pieces.
		//
		
		cout << "\n";
		
		for(i = 1; i < 37; i ++)
		{
			if(Piece_array[i] != NULL)
			{
				Piece_array[i]->print_orientation(i);
			}
			else
			{
				cout << i << " 0\t"; 
			}
				if (i%4 == 0)	
				{
					cout << "\n";
				}
				
		}		

}

pos Board::get_position(int id)
{
		int i = 0, j = 0;
		pos p;
		p.x = -1;
		p.y = -1;

		for(i = 0; i < 9; i ++)
		{
				for(j = 0; j < 9; j++)
				{
						if(matrix[i][j] != NULL)
						{
								if(matrix[i][j]->getId() == id)
								{
										p.x = i;
										p.y = j;
										return p;
								}
						}
				}	
		}

		return p;
}

/*
 *  Moves the Piece in the specified direction
 *  Returns 1 if the move is invalid else returns 0
 */
int Board::make_move(int id, int mov_dir)
{
		pos p = get_position(id);
		int i = p.x;
		int j = p.y;

		switch(mov_dir)	
		{
				case 1:
						if(i > 0)
						{
								i--;
						}
						else
						{
								cout << "Invalid Move. Cannot move Up!\n";
								return 1;
						}
						break;
				case 2:
						if(i < 8)
						{
								i++;
						}
						else
						{
								cout << "Invalid Move. Cannot move Down!\n";
								return 1;
						}
						break;
				case 3:
						if(j < 8)
						{
								j++;
						}
						else
						{
								cout << "Invalid Move. Cannot move Right!\n";
								return 1;
						}
						break;
				case 4:
						if(j > 0 )
						{
								j--;
						}
						else
						{
								cout << "Invalid Move. Cannot move Left!\n";
								return 1;
						}

		}

		if((id == 35 || id == 36) && matrix[i][j] != NULL)
		{
			//
			// Hypercube move. 
			//
			int t_x;
			int t_y;

			srand(time(NULL));

			do
			{
				t_x = rand()%9;	
				t_y = rand()%9;
			}while(matrix[t_x][t_y] != NULL);

			matrix[t_x][t_y] = matrix[i][j];
		}

		if(matrix[i][j] != NULL)
		{
			//
			// Some piece will die. Remove it from the Piece_array as well
			//
			Piece_array[matrix[i][j]->getId()] = NULL;

		}

		matrix[i][j] = matrix[p.x][p.y];
		matrix[p.x][p.y] = NULL;

		return 0;
}

int Board::rotate(int id)
{
		pos p = get_position(id);			
		matrix[p.x][p.y]->change_orientation();
		if(id == 33 || id == 35)
		{
			return 1;
		}
		else
		{
			return 0;
		}

}

void Board::action(int id)
{
	//
	// Only Valid for the Gun piece.
	//
	
	Gun * g = (Gun *) Piece_array[id];
	g -> shoot(this, id);
}

/*
 * beam function shoots a beam on the Board.
 * i is ith row and j is jth column at which the beam currently is
 * dir = 1 => beam will travel northwards
 * dir = 2 => beam will travel southwards
 * dir = 3 => beam will travel eastwards
 * dir = 4 => beam will travel westwards
 * */
void Board::beam(int i, int j, int dir)
{
	while(1)
	{
		switch(dir)
		{
			case 1:
				i--;
				break;
			case 2:
				i++;
				break;
			case 3:
				j++;
				break;
			case 4:
				j--;			
		}
		
		if( (i >= 0 && i < 9) && (j >= 0 && j < 9) )
		{
			if(matrix[i][j] != NULL)
			{
				if(can_kill(i, j, dir))
				{
					return;
				}
			
			}	
		}
		else
		{
			return;
		}		
	}
}

/*
 * can_kill function of class Board takes the row i and column j of the Board
 * and checks if the piece at the current position can be killed.
 * A piece cannot be killed it its a mirror with its face towards the beam.
 * dir gives the direction of the beam
 * */
int Board::can_kill(int i, int j, int &dir)
{
		int id = matrix[i][j]->getId();
		int ref;
		
		if(id >= 1 && id <=12)
		{
			//
			// Triangular mirror. Checking for reflection.
			//
			
			
			Triangle * t = (Triangle *) matrix[i][j];
			ref = t->reflect(dir);
			
			if(ref != -1)
			{
				//
				// Beam has to be reflected in the direction ref.
				//
				
				dir = ref;
				return 0;
				
			}	
		}
		else if(id >= 13 && id <= 20)
		{
			//
			// Square mirror. Checking for reflection.
			//
			
			Square * s = (Square *) matrix[i][j];
			ref = s->reflect(dir);
			
			if(ref != -1)
			{
				//
				// Beam has to be reflected in the direction ref.
				//
				
				dir = ref;
				return 0;
				
			}	
		}
		else if(id == 21 || id == 22 || id == 25 || id ==26)
		{
			//
			// Slant mirror. Find reflection.
			//
			
			Slantline * s = (Slantline *) matrix[i][j];
			ref = s->reflect(dir);
			dir = ref;
			return 0;			
		}
		else if(id == 23 || id == 24 || id == 27 || id == 28)
		{
			//
			// Horizontal or Vertical mirror. Find reflection.
			//
			
			Line * l = (Line *) matrix[i][j];
			ref = l->reflect(dir);
			dir = ref;
			return 0;			
		}
		else if(id == 29 || id == 30)
		{
			//
			// Beam Splitter. Find reflection.
			//
			
			Splitter * s = (Splitter *) matrix[i][j];
			ref = s->reflect(this, i, j, dir);
			dir = ref;
			return 0;			
		}
		else if(id == 35 || id == 36)
		{
				//
				// Hypercube. Kill Nothing.
				//
				
				return 0;
		}
		
		kill(i, j);
		return 1;
}

/*
 * kill function of class Board take the row i and column j of the Board
 * and kills the piece at that position
 * */
void Board::kill(int i, int j)
{
	Piece_array[matrix[i][j]->getId()] = NULL;
	matrix[i][j] = NULL;	
	
}

int Board::stateDifference(Board b2)
{
	int i =0;
	int value1 = 0, value2 = 0, sum1 = 0, sum2 = 0;
	for(i = 0; i < 38; i++)
	{
		if(Piece_array[i] != NULL)
		{
			if(Piece_array[i]->getTeam() == 1)
				sum1 += Piece_array[i]->getValue();
		}
	}
	
	for(i = 0; i < 38; i++)
	{
		if(b2.Piece_array[i] != NULL)
		{
			if(b2.Piece_array[i]->getTeam() == 1)
				sum2 += b2.Piece_array[i]->getValue();
		}
	}
	
	value1 = sum1 + sum2;
	sum1 = 0, sum2 = 0;	

	for(i = 0; i < 38; i++)
	{
		if(Piece_array[i] != NULL)
		{
			if(Piece_array[i]->getTeam() == 0)
				sum1 += Piece_array[i]->getValue();
		}
	}
	
	for(i = 0; i < 38; i++)
	{
		if(b2.Piece_array[i] != NULL)
		{
			if(b2.Piece_array[i]->getTeam() == 0)
				sum2 += b2.Piece_array[i]->getValue();
		}
	}

	value2 = sum1 + sum2;	

	return (value2 - value1);
}
