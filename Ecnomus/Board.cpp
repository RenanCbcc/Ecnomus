#include "Board.h"

Board::Board()
{
	for (int x = 0; x < 15; x++) {
		std::vector <bool> temp;
		for (int y = 0; y < 15; y++)
		{
			temp.push_back(false);
		}
		area.push_back(temp);
	}

	createCleanBoard();
	shufflingPieces();
}

void Board::createCleanBoard()
{

	
	for (int x = 0; x < 15; x++) {
		std::vector <Square*> temp;
		for (int y = 0; y < 15; y++)
		{
			temp.push_back(new Square(x, y, '#', false, true));
		}
		playerSquare.push_back(temp);
	}

}

void Board::shufflingPieces()
{

	std::vector<Component*> componentsVector = { new Submarine(), new Submarine(), new Submarine(), new Submarine(),
		new Seaplane(), new Seaplane(),	new Seaplane(),	new Cruiser(), new Cruiser(),
		new Cruiser(), new Battleship(), new Battleship(), new Aircraftcarrier()
	};

	std::vector<Component*> Components;

	while (componentsVector.size()>0) {
		int randomIndexVector = (rand() % componentsVector.size());
		int randomRow = (rand() % 15);
		int randomColumn = (rand() % 15);

		if (verifyAreaComponentSupport(componentsVector.at(randomIndexVector), randomRow, randomColumn) && !verifyComponentArea(componentsVector.at(randomIndexVector), randomRow, randomColumn)) {
			Component *component = componentsVector.at(randomIndexVector);
			component->getPosition().setCoordinatePosition(randomRow, randomColumn);
			component->updatePositonPieces();


			components.push_back(component);
			putComponentInBoard(component);

			componentsVector.erase(componentsVector.begin() + randomIndexVector);

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
	for (Piece *piece : component->getPieces()) {
		if (area[piece->getPosition().getRow() + row][piece->getPosition().getColumn() + column]) {
			return true;
		}
	}
	return false;
}

bool Board::verifyComponentKill(Component * component)
{


	for (Piece *piece : component->getPieces()) {
		if (piece->isStatus()) {
			return false;
		}
	}

	return true;
}

void Board::putComponentInBoard(Component *component)
{
	for (Piece *piece : component->getPieces()) {
		area[piece->getPosition().getRow()][piece->getPosition().getColumn()] = true;
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

void Board::setValueSquare(int row, int column, bool value)
{
	if (row <= area.size() && column <= area.size()) {
		area[row][column] = value;
	}
}

void Board::setStatusValuePieceComponent(int row, int column, bool value)
{

	for (auto component : components) {
		for (auto piece : component->getPieces()) {
			//Because position was initialized with (0,0).
			if (piece->getPosition().getRow() == row && piece->getPosition().getColumn() == column) {
				piece->setStatus(value);
			}
		}
	}


}

void Board::immersePiece(int row, int column, bool value)
{
	setValueSquare(row, column, value);
	setStatusValuePieceComponent(row, column, value);
}

bool Board::verifyComponentsSubmerged()
{
	for (Component *component : components) {
		for (Piece *piece : component->getPieces()) {
			if (piece->isStatus()) {
				return true;
			}
		}
	}

	return false;

}

Component * Board::getComponent(int row, int column)
{

	for (auto component : components) {
		for (auto piece : component->getPieces()) {
			if (piece->getPosition().getRow() == row && piece->getPosition().getColumn() == column) {
				return component;
			}
		}
	}
	return nullptr;
}

Board::~Board()
{
}

void Board::setSimbolSquare(int row, int column, char simbol)
{
	if (row <= area.size() && column <= area.size()) {
		playerSquare[row][column]->setFill(true);
		playerSquare[row][column]->setSquareSimbol(simbol);

	}
}

bool Board::getValueSquare(int x, int y) {
	if (x <= area.size() && y <= area.size())
	{
		return area[x][y];
	}
	else {
		return false;
	}
}
