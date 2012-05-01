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

		if(id == 35 && matrix[i][j] != NULL)
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






