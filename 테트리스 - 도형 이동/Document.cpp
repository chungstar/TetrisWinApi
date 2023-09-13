#include "Document.h"
Document* Document::singleton;
Document* Document::GetSingleton()
{
	if (singleton == 0)
	{
		singleton = new Document();
	}
	return singleton;
}
void Document::MakeDiagram()
{
	now->SetPosition(SX, SY);//now ÁÂÇ¥¸¦ ½ÃÀÛ ÁÂÇ¥·Î ÀÌµ¿
}
bool Document::MoveLeft()
{
	if (MoveEnable(now, -1, 0))
	{
		now->Move(-1, 0);//nowÀÇ xÁÂÇ¥¸¦ 1 °¨¼Ò
		return true;
	}
	return false;
}
bool Document::MoveRight()
{
	if (MoveEnable(now,1,0))
	{
		now->Move(1, 0);//nowÀÇ xÁÂÇ¥¸¦ 1 Áõ°¡
		return true;
	}
	return false;
}
bool Document::MoveDown()
{
	if (MoveEnable(now,0,1))
	{
		now->Move(0, 1);//now yÁÂÇ¥¸¦ 1Áõ°¡
		return true;
	}
	MakeDiagram();
	return false;
}
Document::Document()
{
	now = new Diagram();
}
Diagram* Document::GetNow()
{
	return now;
}
bool Document::MoveEnable(Diagram* now, int cx, int cy)
{
	int x = now->GetX() + cx;
	int y = now->GetY() + cy;
	if (((x >= 0) && (x < BOARD_COL))&&((y>=0)&&(y<BOARD_ROW)))
	{
		return true;
	}
	return false;
}