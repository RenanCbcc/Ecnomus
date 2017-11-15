#include "Board.h"

Board::Board()
{
	shufflingPieces();
}


void Board::shufflingPieces()
{

	components = { new Submarine(), new Submarine(), new Submarine(), new Submarine(),
		new Seaplane(), new Seaplane(),	new Seaplane(),	new Cruiser(), new Cruiser(),
		new Cruiser(), new Battleship(), new Battleship(), new Aircraftcarrier() };
	
	
	while (components.size() > 0) {
		int randomIndexVector = ( rand()% components.size());
		int randomRow = (rand()%15);
		int randomColumn = (rand()%15);

		if (verifyAreaComponentSupport(components.at(randomIndexVector), randomRow, randomColumn) && !verifyComponentArea(components.at(randomIndexVector), randomRow, randomColumn)) {
			Component *component = components.at(randomIndexVector);
			component->getPosition().setCoordinatePosition(randomRow, randomColumn);
			component->updatePositonPieces();

			
			components.push_back(component);
			putComponentInBoard(component);

			components.erase(components.begin()+randomIndexVector);

		}
	}
}

bool Board::verifyAreaComponentSupport(Component *component, int row, int column)
{
	if (component->getHeight() + row <= 15 && component->getWidth() + column <= 15) {
		return true;
	}
	else {
		return false;
	}
}

bool Board::verifyComponentArea(Component *component, int row, int column)
{
	for (Piece piece : component->getPieces()) {
		if (area[piece.getPosition().getRow() + row][piece.getPosition().getColumn() + column]) {
			return true;
		}
	}
	return false;
}

bool Board::verifyComponentKill(Component * component )
{
	
	
	for (Piece piece : component->getPieces()) {
		if (piece.isStatus()) {
			return false;
		}
	}

	return true;
}

void Board::putComponentInBoard(Component *component)
{
	for (Piece piece : component->getPieces()) {
		area[piece.getPosition().getRow()][piece.getPosition().getColumn()] = true;
	}
}

void Board::resetBoard()
{
	for (int row = 0; row < area.size(); row++) {
		for (int column = 0; column < area[row].size(); column++) {
			area[row][column] = false;
		}
	}
}

Component * Board::getComponent(int row, int column)
{

	for (auto component : components) {
		for (auto piece : component->getPieces()) {
			if (piece.getPosition().getRow() == row && piece.getPosition().getColumn() == column) {
				return component;
			}
		}
	}
	return nullptr;
}
