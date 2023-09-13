#include "Board.h"
#include <string.h>
#pragma warning(disable:4996)
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
	return LineCheck(y + 3);
}
bs_arr Board::GetBoardSpace()
{
	return bs;
}
int Board::LineCheck(int cy)
{
	int clc = 0; //clear line count
	for (int i = 0; i < DH; i++)
	{
		if (IsFull(cy))
		{
			MoveLine(cy);
			clc++;
		}
		else
		{
			cy--;
		}
	}
	return clc;
}
bool Board::IsFull(int cy)
{
	for (int x = 0; x < BOARD_COL; x++)
	{
		if (bs[cy][x]==0)
		{
			return false;
		}

	}
	return true;
}
void Board::MoveLine(int cy)
{
	memcpy(bs + 1, bs, sizeof(int) * BOARD_COL*cy);
}