#include "Submarine.h"



Submarine::Submarine()
	:Component()
{
	initializePieces();
}

Submarine::Submarine(int row, int column)
	: Component(row, column)
{

	initializePieces();
}

Submarine::~Submarine()
{

}

std::string Submarine::getName() {
	return "Submarine";
}
void Submarine::initializePieces() {

	pieces = { Piece(position.getRow(), position.getColumn())};

}

void Submarine::updatePositonPieces() {
	pieces[0].setCoordinatePosition(position.getRow(), position.getColumn());
}