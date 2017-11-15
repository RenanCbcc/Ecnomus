#pragma once
#include "Aircraftcarrier.h"
#include "Battleship.h"
#include "Component.h"
#include "Cruiser.h"
#include "Seaplane.h"
#include "Submarine.h"
#include <random>

class Board
{
public:
	Board();
	void shufflingPieces();
	bool verifyAreaComponentSupport(Component* , int, int);
	bool verifyComponentArea(Component*, int, int);
	bool verifyComponentKill(Component*);
	void putComponentInBoard(Component *);	
	void resetBoard();
	Component* getComponent(int row, int column);
	
	~Board();

private:
	std::vector<Component*> components;
	std::vector<std::vector<bool>> area;
};

