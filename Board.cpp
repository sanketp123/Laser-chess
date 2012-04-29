#include "files.h"

// Global declarations

Triangle triangle_r1(RTRIANGLE1, 1); 
Triangle triangle_r2(RTRIANGLE2, 1); 
Triangle triangle_r3(RTRIANGLE3, 1); 
Triangle triangle_r4(RTRIANGLE4, 1); 
Triangle triangle_r5(RTRIANGLE5, 1); 
Triangle triangle_r6(RTRIANGLE6, 1); 
Triangle triangle_g1(GTRIANGLE1, 0); 
Triangle triangle_g2(GTRIANGLE2, 0); 
Triangle triangle_g3(GTRIANGLE3, 0); 
Triangle triangle_g4(GTRIANGLE4, 0); 
Triangle triangle_g5(GTRIANGLE5, 0); 
Triangle triangle_g6(GTRIANGLE6, 0); 

Square square_r1(RSQUARE1, 1);
Square square_r2(RSQUARE2, 1);
Square square_r3(RSQUARE3, 1);
Square square_r4(RSQUARE4, 1);
Square square_g1(GSQUARE1, 0);
Square square_g2(GSQUARE2, 0);
Square square_g3(GSQUARE3, 0);
Square square_g4(GSQUARE4, 0);

Slantline sline_r1(RLINESLANT1, 1);
Slantline sline_r2(RLINESLANT2, 1);
Slantline sline_g1(GLINESLANT1, 0);
Slantline sline_g2(GLINESLANT2, 0);

Line line_r1(RLINE1, 1);
Line line_r2(RLINE2, 1);
Line line_g1(GLINE1, 0);
Line line_g2(GLINE2, 0);

Splitter splitter_r(RSPLITTER, 1);
Splitter splitter_g(GSPLITTER, 0);

King king_r(RKING, 1);
King king_g(GKING, 0);

Gun gun_r(RGUN, 1);
Gun gun_g(GGUN, 0);

Hypercube hypercube_r(RHYPERCUBE, 1);
Hypercube hypercube_g(GHYPERCUBE, 0);
 

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
	matrix[0][3] = &gun_r;
	matrix[0][4] = &king_r;
	matrix[0][5] = &hypercube_r;
	matrix[0][6] = &sline_r2;
	matrix[0][7] = &triangle_r3;
	matrix[0][8] = &triangle_r4;
	matrix[1][0] = &triangle_r5;
	matrix[1][1] = &square_r1;
	matrix[1][2] = &square_r2;
	matrix[1][3] = &splitter_r;
	matrix[1][4] = &line_r1;
	matrix[1][5] = &line_r2;
	matrix[1][6] = &square_r3;
	matrix[1][7] = &square_r4;
	matrix[1][8] = &triangle_r6;

	matrix[7][0] = &triangle_g5;
	matrix[7][1] = &square_g1;
	matrix[7][2] = &square_g2;
	matrix[7][3] = &line_g1;
	matrix[7][4] = &line_g2;
	matrix[7][5] = &splitter_g;
	matrix[7][6] = &square_g3;
	matrix[7][7] = &square_g4;
	matrix[7][8] = &triangle_g6;
	matrix[8][0] = &triangle_g1;
	matrix[8][1] = &triangle_g2;
	matrix[8][2] = &sline_g1;
	matrix[8][3] = &hypercube_g;
	matrix[8][4] = &king_g;
	matrix[8][5] = &gun_g;
	matrix[8][6] = &sline_g2;
	matrix[8][7] = &triangle_g3;
	matrix[8][8] = &triangle_g4;
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

int main()
{
    Board b;

	

    b.draw();
    return 0;
}

