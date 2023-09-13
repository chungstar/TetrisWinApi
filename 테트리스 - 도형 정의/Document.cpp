#include "Document.h"
Document* Document::singleton;
Document* Document::GetSingleton()
{
	if (singleton == 0)
	{
		srand((unsigned)time(0));
		singleton = new Document();
	}
	return singleton;
}
void Document::MakeDiagram()
{
	next->SetPosition(SX, SY);//next 벽돌 설정
	now->SetPosition(SX, SY);//now 벽돌 설정
}
bool Document::MoveLeft()
{
	if (MoveEnable(now, -1, 0))
	{
		now->Move(-1, 0);//now의 x좌표를 1 감소
		return true;
	}
	return false;
}
bool Document::MoveRight()
{
	if (MoveEnable(now,1,0))
	{
		now->Move(1, 0);//now의 x좌표를 1 증가
		return true;
	}
	return false;
}
bool Document::MoveDown()
{
	if (MoveEnable(now,0,1))
	{
		now->Move(0, 1);//now y좌표를 1증가
		return true;
	}
	ChangeDiagram();
	return false;
}
Document::Document()
{
	now = new Diagram();
	next = new Diagram();
	MakeDiagram();
}
Diagram* Document::GetNow()
{
	return now;
}
bool Document::MoveEnable(Diagram* now, int cx, int cy, bool is_turn)
{
	block bl = now->GetBlock(is_turn);

	int x = now->GetX() + cx;
	int y = now->GetY() + cy;
	for (int xi = 0; xi < DW; xi++)
	{
		for (int yi = 0; yi < DH; yi++)
		{
			if ((x + xi < 0) || ((x+xi)>=BOARD_COL)||((y + yi) >= BOARD_ROW))
			{
				if (bl[yi][xi] == 1)
				{
					return false;
				}
			}
		}
	}
	return true;
}
void Document::ChangeDiagram()
{
	now->SetPosition(next);
	next->SetPosition(SX, SY);
}
bool Document::MoveTurn()
{
	if (MoveEnable(now, 0, 0, true))
	{
		now->Turn();
		return true;
	}
	return false;
}
Diagram* Document::GetNext()
{
	return next;
}