#include "Document.h"
Document* Document::singleton;
Document* Document::GetSingleton()
{
	if (singleton == 0)
	{
		srand((unsigned)time(0));//랜덤 seed 설정
		singleton = new Document();
	}
	return singleton;
}
void Document::MakeDiagram()
{
	next->SetPosition(SX, SY);//next벽돌 설정
	now->SetPosition(SX,SY);//now벽돌 설정
	
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
bool Document::MoveDown(bool* is_end)
{
	*is_end = false;

	if (MoveEnable(now,0,1))
	{
		now->Move(0, 1);//now y좌표를 1증가
		return true;
	}
	else
	{
		int bnum = now->GetBNum();
		block bl = now->GetBlock();
		int x = now->GetX();
		int y = now->GetY();
		board->AddBlock(bnum, bl, x, y);
	}
	ChangeDiagram();
	int bnum = now->GetBNum();
	block bl = now->GetBlock();
	int x = now->GetX();
	int y = now->GetY();
	if (board->IsCrash(bl, x, y))
	{
		*is_end = true;
	}
	return false;
}
Document::Document()
{
	now = new Diagram();
	next = new Diagram();
	board = new Board();
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
	return board->IsCrash(bl, x, y)==false;
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
bs_arr Document::GetBoard()
{
	return board->GetBoardSpace();
}