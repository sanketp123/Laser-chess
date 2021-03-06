#include "chess.h"
# include <stdlib.h>

// Global declarations

Triangle triangle_r1("RedTriangle1", RTRIANGLE1, 1, 10, 'S', 'E'); 
Triangle triangle_r2("RedTriangle2", RTRIANGLE2, 1, 10, 'S', 'E'); 
Triangle triangle_r3("RedTriangle3", RTRIANGLE3, 1, 10, 'S', 'W'); 
Triangle triangle_r4("RedTriangle4", RTRIANGLE4, 1, 10, 'S', 'W'); 
Triangle triangle_r5("RedTriangle5", RTRIANGLE5, 1, 10, 'S', 'W'); 
Triangle triangle_r6("RedTriangle6", RTRIANGLE6, 1, 10, 'S', 'E'); 
Triangle triangle_g1("GreenTriangle1", GTRIANGLE1, 0, 10, 'N', 'E'); 
Triangle triangle_g2("GreenTriangle2", GTRIANGLE2, 0, 10, 'N', 'E'); 
Triangle triangle_g3("GreenTriangle3", GTRIANGLE3, 0, 10, 'N', 'W'); 
Triangle triangle_g4("GreenTriangle4", GTRIANGLE4, 0, 10, 'N', 'W'); 
Triangle triangle_g5("GreenTriangle5", GTRIANGLE5, 0, 10, 'N', 'W'); 
Triangle triangle_g6("GreenTriangle6", GTRIANGLE6, 0, 10, 'N', 'E'); 

Square square_r1("RedSquare1", RSQUARE1, 1, 10, 'S');
Square square_r2("RedSquare2", RSQUARE2, 1, 10, 'S');
Square square_r3("RedSquare3", RSQUARE3, 1, 10, 'S');
Square square_r4("RedSquare4", RSQUARE4, 1, 10, 'S');
Square square_g1("GreenSquare1", GSQUARE1, 0, 10, 'N');
Square square_g2("GreenSquare2", GSQUARE2, 0, 10, 'N');
Square square_g3("GreenSquare3", GSQUARE3, 0, 10, 'N');
Square square_g4("GreenSquare4", GSQUARE4, 0, 10, 'N');

Slantline sline_r1("RedSlantLine1", RLINESLANT1, 1, 5, '\\');
Slantline sline_r2("RedSlantLine2", RLINESLANT2, 1, 5, '/');
Slantline sline_g1("GreenSlantLine1", GLINESLANT1, 0, 5, '/');
Slantline sline_g2("GreenSlantLine2", GLINESLANT2, 0, 5, '\\');

Line line_r1("RedLine1", RLINE1, 1, 5, 'V');
Line line_r2("RedLine2", RLINE2, 1, 5, 'H');
Line line_g1("GreenLine1", GLINE1, 0, 5, 'H');
Line line_g2("GreenLine2", GLINE2, 0, 5, 'V');

Splitter splitter_r("RedSplitter", RSPLITTER, 1, 15, 'N');
Splitter splitter_g("GreenSplitter", GSPLITTER, 0, 15, 'S');

King king_r("RedKing",RKING, 1, 25);
King king_g("GreenKing", GKING, 0, 25);

Gun gun_r("RedGun", RGUN, 1, 15, 'S');
Gun gun_g("GreenGun", GGUN, 0, 15, 'N');

Hypercube hypercube_r("RedHypercube", RHYPERCUBE, 1, 5);
Hypercube hypercube_g("GreenHypercube", GHYPERCUBE, 0, 5);

Board::Board()
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			matrix[i][j] = NULL;
		}
	
	for(int i = 1; i <= 36; i++)
	{
		Piece_array[i] = NULL;
	}
}

void
Board::first_init()
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			matrix[i][j] = NULL;
		}
	//
	// Test set
	//
	
	matrix[0][0] = &triangle_r1;
	matrix[0][1] = &triangle_r2;
	matrix[0][2] = &sline_r1; 
	matrix[0][3] = &hypercube_r;
	matrix[0][4] = &king_r;
	matrix[0][5] = &gun_r;
	matrix[0][6] = &sline_r2;
	matrix[0][7] = &triangle_r3;
	matrix[0][8] = &triangle_r4;
	matrix[1][0] = &triangle_r5;
	matrix[1][1] = &square_r1;
	matrix[1][2] = &square_r2;
	matrix[1][3] = &line_r1;
	matrix[1][4] = &line_r2;
	matrix[1][5] = &splitter_r;
	matrix[1][6] = &square_r3;
	matrix[1][7] = &square_r4;
	matrix[1][8] = &triangle_r6;

	matrix[7][0] = &triangle_g5;
	matrix[7][1] = &square_g1;
	matrix[7][2] = &square_g2;
	matrix[7][3] = &splitter_g;
	matrix[7][4] = &line_g1;
	matrix[7][5] = &line_g2;
	matrix[7][6] = &square_g3;
	matrix[7][7] = &square_g4;
	matrix[7][8] = &triangle_g6;
	matrix[8][0] = &triangle_g1;
	matrix[8][1] = &triangle_g2;
	matrix[8][2] = &sline_g1;
	matrix[8][3] = &gun_g;
	matrix[8][4] = &king_g;
	matrix[8][5] = &hypercube_g;
	matrix[8][6] = &sline_g2;
	matrix[8][7] = &triangle_g3;
	matrix[8][8] = &triangle_g4;
	//
	// Initialize the Piece_array to contain the Piece Information.
	//

	Piece_array[1] = &triangle_r1;
	Piece_array[2] = &triangle_r2;
	Piece_array[21] = &sline_r1; 
	Piece_array[35] = &hypercube_r;
	Piece_array[31] = &king_r;
	Piece_array[33] = &gun_r;
	Piece_array[22] = &sline_r2;
	Piece_array[3] = &triangle_r3;
	Piece_array[4] = &triangle_r4;
	Piece_array[5] = &triangle_r5;
	Piece_array[13] = &square_r1;
	Piece_array[14] = &square_r2;
	Piece_array[23] = &line_r1;
	Piece_array[24] = &line_r2;
	Piece_array[29] = &splitter_r;
	Piece_array[15] = &square_r3;
	Piece_array[16] = &square_r4;
	Piece_array[6] = &triangle_r6;

	Piece_array[11] = &triangle_g5;
	Piece_array[17] = &square_g1;
	Piece_array[18] = &square_g2;
	Piece_array[30] = &splitter_g;
	Piece_array[27] = &line_g1;
	Piece_array[28] = &line_g2;
	Piece_array[19] = &square_g3;
	Piece_array[20] = &square_g4;
	Piece_array[12] = &triangle_g6;
	Piece_array[7] = &triangle_g1;
	Piece_array[8] = &triangle_g2;
	Piece_array[25] = &sline_g1;
	Piece_array[34] = &gun_g;
	Piece_array[32] = &king_g;
	Piece_array[36] = &hypercube_g;
	Piece_array[26] = &sline_g2;
	Piece_array[9] = &triangle_g3;
	Piece_array[10] = &triangle_g4;

}

void
Board::initialize(Board * b)
{
	int i;
	int j;
	for ( i = 0; i < 9; i++)
	{
		for( j = 0; j < 9; j++)
		{
			if(b->matrix[i][j] != NULL)
			{
				matrix[i][j] = new Piece();
				matrix[i][j] = b-> matrix[i][j]->make_copy();
				Piece_array[matrix[i][j]->getId()] = matrix[i][j];
			}
			else
			{
				matrix[i][j] = NULL;
			}
		}
	}
}

int main()
{
        Board b;
	b.first_init();
	//
	//Sit in an infinite for loop, asking user the next move.
	//
	
	while(1)
	{
		
		int id;
		int mov_rot;
		int invalid = 0;
   
		//
		// Check if Player / CPU won the game
		//

		if(!b.check_validity(31))
		{
			cout << "King killed. Game over. CPU wins\n";
			break;
		}
		
		if(!b.check_validity(32))
		{
			cout << "King killed. Game over. Player wins\n";
			break;
		}

		cout << "In Main\n";	
		b.draw();

		cout << "\n-----------------------------------------------------------------------------------";
		cout << "\nEnter Piece no:- \n";
		cin >> id;

		if(!b.check_validity(id))
		{
			cout << "Piece doesn't exist \n";
			continue;
		}
		
		cout << "Enter: \n1 to move \n2 to rotate \n3 to fire (only for laser) the selected Piece\n";
		cin >> mov_rot;

		if(mov_rot == 1)	
		{
			int mov_dir;

			cout << "Enter Move Direction: \n1 Up \n2 Down \n3 Right  \n4 Left  \n";
			cin >> mov_dir;

			invalid = b.make_move(id, mov_dir);

		}
		else if(mov_rot == 2)
		{
			invalid = b.rotate(id);
		}
		else if(mov_rot == 3)
		{
			if(id == 33 || id == 34)
			{
				b.action(id);
			
			}
			else
			{
				cout << "Invalid Operation.\n";
				invalid = 1;
			}

		}
		else
		{
			cout << "Invalid Choice\n";
			invalid = 1;
		}

		if(invalid)
		{
			//
			// Player made an invalid move. Player's turn again.
			//

			continue;
		}

		//
		//
		// Check if Player / CPU won the game
		//

		if(!b.check_validity(31))
		{
			cout << "King killed. Game over. CPU wins\n";
			break;
		}
		
		if(!b.check_validity(32))
		{
			cout << "King killed. Game over. Player wins\n";
			break;
		}

		//
		// CPU move.
		//
		b.draw();
		b = b.computeMoves(2);
	}

    return 0;
}

