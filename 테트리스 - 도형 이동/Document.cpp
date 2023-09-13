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
	now->SetPosition(SX, SY);//now ��ǥ�� ���� ��ǥ�� �̵�
}
bool Document::MoveLeft()
{
	if (MoveEnable(now, -1, 0))
	{
		now->Move(-1, 0);//now�� x��ǥ�� 1 ����
		return true;
	}
	return false;
}
bool Document::MoveRight()
{
	if (MoveEnable(now,1,0))
	{
		now->Move(1, 0);//now�� x��ǥ�� 1 ����
		return true;
	}
	return false;
}
bool Document::MoveDown()
{
	if (MoveEnable(now,0,1))
	{
		now->Move(0, 1);//now y��ǥ�� 1����
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