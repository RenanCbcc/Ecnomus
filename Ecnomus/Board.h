#pragma once
#include "Aircraftcarrier.h"
#include "Battleship.h"
#include "Component.h"
#include "Cruiser.h"
#include "Seaplane.h"
#include "Square.h"
#include "Submarine.h"
#include <random>

class Board
{
public:
	Board();
	void createCleanBoard();
	void shufflingPieces();
	void putComponentInBoard(Component *);
	void resetBoard();
	void setValueSquare(int , int, bool );
	void setSimbolSquare(int, int, char);
	void setStatusValuePieceComponent(int, int, bool);
	void immersePiece(int , int , bool);
	bool verifyComponentsSubmerged();
	bool getValueSquare(int, int);
	bool verifyAreaComponentSupport(Component* , int, int);
	bool verifyComponentArea(Component*, int, int);
	bool verifyComponentKill(Component*);
	Component* getComponent(int row, int column);
	std::vector<std::vector<Square*>> playerSquare;
	~Board();

private:
	std::vector<Component*> components;
	std::vector<std::vector<bool>> area;
};

