#pragma once

#include <stdlib.h>
#include <time.h>

#define MAX_DIAGRAM	7
#define MAX_TRUN	4
#define DIAGRAM_WIDTH	4
#define DIAGRAM_HEIGHT	4
#define DW	DIAGRAM_WIDTH
#define DH	DIAGRAM_HEIGHT
typedef const int(*block)[4];

class Diagram
{
	int dindex;
	int turn;
	int x;
	int y;
public:
	Diagram();
	void SetPosition(int x, int y);
	void SetPosition(Diagram*next);
	void Move(int cx, int cy);
	int GetX()const;
	int GetY()const;
	void Turn();
	block GetBlock(bool is_turn=false);
};

