#include "chess.h"

void Board::draw()
{
     int i = 0, j =0;
     for(i = 0; i < 9; i ++)
           for(j = 9; j < 9; j++)
           {
                 cout <<" | \t" << matrix[i][j] <<" \t";
           }
           cout << " |" <<endl;
}

int main()
{
    
    return 0;
}

