#include "Board.h"
Board::Board()
{
	for (int y = 0; y < BOARD_ROW; y++)
	{
		for (int x = 0; x < BOARD_COL; x++)
		{
			bs[y][x] = 0;
		}
	}
}
bool Board::IsCrash(block bl, int x, int y)
{
	for (int cx = 0; cx < DW; cx++)
	{
		for (int cy = 0; cy < DH; cy++)
		{
			if (bl[cy][cx])
			{
				if (((y + cy) >= BOARD_ROW) || ((x + cx) < 0) || (x + cx) >= BOARD_COL)
				{
					return true;
				}
				if (bs[y + cy][x + cx])
				{
					return true;
				}
			}			
		}
	}
	return false;
}
int Board::AddBlock(int bnum, block bl, int x, int y)
{
	for (int cx = 0; cx < DW; cx++)
	{
		for (int cy = 0; cy < DH; cy++)
		{
			if (bl[cy][cx])
			{
				bs[y + cy][x + cx] = bnum+1;			
			}
		}
	}
	return 0;
}
bs_arr Board::GetBoardSpace()
{
	return bs;
}
