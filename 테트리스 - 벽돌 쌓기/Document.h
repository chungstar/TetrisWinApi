#pragma once
#include "Diagram.h"
#include "Board.h"

#define BOARD_SX	70
#define BOARD_SY	50
#define MY_WIDTH	15
#define MY_HEIGHT	15



#define MY_RX(x)    (BOARD_SX+(x)*MY_WIDTH)
#define MY_RY(y)    (BOARD_SY+(y)*MY_HEIGHT)
#define NEXT_SX		270
#define MY_NRX(x)   (NEXT_SX+(x)*MY_WIDTH)
#define MY_NRY(y)	MY_RY(y)



#define SX	3
#define SY	0
class Document
{
	Diagram* now;
	Diagram* next;
	static Document* singleton;
	Board* board;
public:
	static Document* GetSingleton();
	void MakeDiagram();
	void ChangeDiagram();
	bool MoveLeft();
	bool MoveRight();
	bool MoveDown(bool *is_end);
	bool MoveTurn();
	Diagram* GetNow();
	Diagram* GetNext();
	bool MoveEnable(Diagram* now, int cx, int cy,bool is_turn=false);
	bs_arr GetBoard();
private:
	Document();
};

