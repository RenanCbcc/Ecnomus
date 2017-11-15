#include "Cruiser.h"



Cruiser::Cruiser()
	:Component()
{
	initializePieces();
}

Cruiser::Cruiser(int row, int column)
	: Component(row, column)
{

	initializePieces();
}


Cruiser::~Cruiser()
{
}


std::string Cruiser::getName() {
	return "Cruiser";
}
void Cruiser::initializePieces() {

	pieces = { Piece(position.getRow(), position.getColumn()),
		Piece(position.getRow(), position.getColumn() + 1),
		};

}

void Cruiser::updatePositonPieces() {
	pieces[0].setCoordinatePosition(position.getRow(), position.getColumn());
	pieces[1].setCoordinatePosition(position.getRow(), position.getColumn() + 1);

}