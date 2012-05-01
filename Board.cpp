#include "chess.h"

Board::Board()
{
	//matrix = new Piece*[9];
	//for(int i = 0; i < 9 ; i++)
	//	matrix[i] = new Piece[9];
	
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			matrix[i][j] = NULL;
	
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
}



int main()
{
    Board b;
	
	//
	//Sit in an infinite for loop, asking user the next move.
	//
	
	while(1)
	{
		int id;
		int mov_rot;
		int invalid = 0;
    
		b.draw();

		cout << "Enter Piece no:- \n";
		cin >> id;

		if(!b.check_validity(id))
		{
			cout << "Piece doesn't exist \n";
			continue;
		}
		
		cout << "Enter: \n1 to move \n2 to rotate \n3 to fire (only for laser)  \nthe selected Piece\n";
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
		}
		else
		{
			cout << "Invalid Choice\n";
			invalid = 1;
		}

		if(invalid)
		{
			continue;
		}

		//
		// CPU move.
		//

	}

    return 0;
}

