#pragma once
#include "Diagram.h"

#define BOARD_SX	70
#define BOARD_SY	50
#define MY_WIDTH	15
#define MY_HEIGHT	15

#define DIAGRAM_WIDTH	4
#define DIAGRAM_HEIGHT	4
#define DW	DIAGRAM_WIDTH
#define DH	DIAGRAM_HEIGHT

#define MY_RX(x)    (BOARD_SX+(x)*MY_WIDTH)
#define MY_RY(y)    (BOARD_SY+(y)*MY_HEIGHT)
#define NEXT_SX		270
#define MY_NRX(x)   (NEXT_SX+(x)*MY_WIDTH)
#define MY_NRY(y)	MY_RY(y)

#define BOARD_COL	10
#define BOARD_ROW	18

#define SX	3
#define SY	0
class Document
{
	Diagram* now;
	static Document* singleton;
public:
	static Document* GetSingleton();
	void MakeDiagram();
	bool MoveLeft();
	bool MoveRight();
	bool MoveDown();
	Diagram* GetNow();
	bool MoveEnable(Diagram* now, int cx, int cy);
private:
	Document();
};

