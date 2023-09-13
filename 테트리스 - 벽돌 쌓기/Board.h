#pragma once
#include "Diagram.h"

#define BOARD_COL	10
#define BOARD_ROW	18

typedef int(*bs_arr)[BOARD_COL];
class Board
{
	int bs[BOARD_ROW][BOARD_COL];
public:
	Board();
	bool IsCrash(block bl, int x, int y);
	int AddBlock(int bnum,block bl, int x,int y);
	bs_arr GetBoardSpace();
};

