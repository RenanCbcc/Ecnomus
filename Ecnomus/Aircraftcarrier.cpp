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

string Aircraftcarrier::getName() {
	return "Aircraft carrier";
}
void Aircraftcarrier::initializePieces() {

	pieces ={	Piece(position.getRow(), position.getColumn()),
				Piece(position.getRow(), position.getColumn() + 1),
				Piece(position.getRow(), position.getColumn() + 2),
				Piece(position.getRow(), position.getColumn() + 3),
				Piece(position.getRow(), position.getColumn() + 4) };

}

void Aircraftcarrier::updatePositonPieces() {
	pieces[0].setCoordinatePosition(position.getRow(), position.getColumn());
	pieces[1].setCoordinatePosition(position.getRow(), position.getColumn() + 1);
	pieces[2].setCoordinatePosition(position.getRow(), position.getColumn() + 2);
	pieces[3].setCoordinatePosition(position.getRow(), position.getColumn() + 3);
	pieces[4].setCoordinatePosition(position.getRow(), position.getColumn() + 4);

}