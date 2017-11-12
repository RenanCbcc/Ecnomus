#include "Piece.h"

Piece::Piece(int row, int column)
	:position(row,column)
{
	this->status = true;
}

bool Piece::isStatus()
{
	return this->status;
}

void Piece::setStatus(bool status) {
	this->status = status;
}


Position Piece::getPosition()
{
	return this->position;
}

void Piece::setPosition(Position position)
{
	this->position = position;
}

void Piece::setCoordinatePosition(int row, int column) {
	this->position.setRow(row);
	this->position.setColumn(column);
}


Piece::~Piece()
{
}
