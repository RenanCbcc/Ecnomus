#include "Aircraftcarrier.h"



Aircraftcarrier::Aircraftcarrier()
	:Component()
{
	initializePieces();
}

Aircraftcarrier::Aircraftcarrier(int row, int column) 
	: Component(row,column)
{

	initializePieces();
}

Aircraftcarrier::~Aircraftcarrier()
{

}

std::string Aircraftcarrier::getName() {
	return "Aircraft carrier";
}
void Aircraftcarrier::initializePieces() {

	pieces = {	new Piece(position.getRow(), position.getColumn()),
		new Piece(position.getRow(), position.getColumn() + 1),
		new 	Piece(position.getRow(), position.getColumn() + 2),
		new 	Piece(position.getRow(), position.getColumn() + 3),
		new 	Piece(position.getRow(), position.getColumn() + 4) };

}

void Aircraftcarrier::updatePositonPieces() {
	pieces[0]->setCoordinatePosition(position.getRow(), position.getColumn());
	pieces[1]->setCoordinatePosition(position.getRow(), position.getColumn() + 1);
	pieces[2]->setCoordinatePosition(position.getRow(), position.getColumn() + 2);
	pieces[3]->setCoordinatePosition(position.getRow(), position.getColumn() + 3);
	pieces[4]->setCoordinatePosition(position.getRow(), position.getColumn() + 4);

}