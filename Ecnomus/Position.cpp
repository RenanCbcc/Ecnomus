#include "Position.h"



Position::Position(int row, int column) {
	this->row = row;
	this->column = column;
}


int Position::getRow()
{
	return this->row;
}

void Position::setRow(int row)
{
	this->row = row;
}

int Position::getColumn()
{
	return this->column;
}

void Position::setColumn(int column)
{
	this->column = column;
}

void Position::setCoordinatePosition(int, int)
{
}

Position::~Position()
{
}
