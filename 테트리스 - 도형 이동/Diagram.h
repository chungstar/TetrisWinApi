#pragma once
class Diagram
{
	int x;
	int y;
public:
	Diagram();
	void SetPosition(int x, int y);
	void Move(int cx, int cy);
	int GetX()const;
	int GetY()const;
};

