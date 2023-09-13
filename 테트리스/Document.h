#pragma once
#include "Diagram.h"
#include "Board.h"


#define SX	3
#define SY	0
class Document
{
	Diagram* now;
	Diagram* next;
	static Document* singleton;
	Board* board;
	int score;
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
	int GetScore();
private:
	Document();
};

