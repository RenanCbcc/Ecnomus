#pragma once
class Position
{
public:
	Position(int, int);
	int getRow();
	void setRow(int);
	int getColumn();
	void setColumn(int);
	void setCoordinatePosition(int, int);
	
	~Position();
private:
	int row;
	int column;
};

