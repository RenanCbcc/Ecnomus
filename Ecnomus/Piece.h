#pragma once
#include"Position.h"
class Piece
{
public:
	Piece(int,int);
	bool isStatus();
	void setStatus(bool);
	Position getPosition();
	void setPosition(Position);
	void setCoordinatePosition(int, int);
	~Piece();
private:
	bool status;
	Position position;
};

