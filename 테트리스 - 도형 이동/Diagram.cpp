#include "Diagram.h"
Diagram::Diagram()
{
	x = 0;
	y = 0;
}
void Diagram::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Diagram::Move(int cx, int cy)
{
	x += cx;
	y += cy;
}
int Diagram::GetX()const
{
	return x;
}
int Diagram::GetY()const
{
	return y;
}