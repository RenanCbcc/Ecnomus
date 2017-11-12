#include "Battleship.h"



Battleship::Battleship()
	:Component()
{
}

Battleship::Battleship(int row, int column)
	: Component(row,column)
{
	initializePieces();
}


Battleship::~Battleship()
{
}

string Battleship::getName()
{
	return "Battleship";
}

void Battleship::initializePieces()
{
	pieces = { Piece(position.getRow(), position.getColumn()),
		Piece(position.getRow(), position.getColumn() + 1),
		Piece(position.getRow(), position.getColumn() + 2),
		Piece(position.getRow(), position.getColumn() + 3)};

}

void Battleship::updatePositonPieces()
{
	pieces[0].setCoordinatePosition(position.getRow(), position.getColumn());
	pieces[1].setCoordinatePosition(position.getRow(), position.getColumn() + 1);
	pieces[2].setCoordinatePosition(position.getRow(), position.getColumn() + 2);
	pieces[3].setCoordinatePosition(position.getRow(), position.getColumn() + 3);

}
