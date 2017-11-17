#include "Seaplane.h"


Seaplane::Seaplane()
	:Component()
{
	initializePieces();
}

Seaplane::Seaplane(int row, int column)
	: Component(row, column)
{

	initializePieces();
}

Seaplane::~Seaplane()
{

}

std::string Seaplane::getName() {
	return "Seaplane";
}
void Seaplane::initializePieces() {

	pieces = { new Piece(position.getRow(), position.getColumn() + 1),
		new Piece(position.getRow() + 1, position.getColumn()),
		new Piece(position.getRow() + 1, position.getColumn() + 2) };

}

void Seaplane::updatePositonPieces() {
	pieces[0]->setCoordinatePosition(position.getRow(), position.getColumn() + 1);
	pieces[1]->setCoordinatePosition(position.getRow() + 1, position.getColumn());
	pieces[2]->setCoordinatePosition(position.getRow() + 1, position.getColumn() + 2);

}