#include "Component.h"



Component::Component():position(0, 0) {}

Component::Component(int row, int column):position(row, column){}

std::vector<Piece> Component::getPieces()
{
	return this->pieces;
}

Position Component::getPosition()
{
	return this->position;
}

int Component::getHeight()
{
	int height = 1, highest = 0;

	for (Piece piece : pieces) {
		if (piece.getPosition().getRow() >  highest) {
			highest = piece.getPosition().getRow();
			height++;
		}
	}
	return height;
}

int Component::getWidth()
{
	int width = 1, highest = 0;

	for (Piece piece : pieces) {
		if (piece.getPosition().getColumn() >  highest) {
			highest = piece.getPosition().getRow();
			width++;
		}
	}
	return width;
}


Component::~Component()
{
}
