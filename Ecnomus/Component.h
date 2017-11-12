#pragma once
#include "Position.h"
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;
class Component
{
public:
	Component();
	Component(int, int);	
	virtual string getName() = 0;
	virtual void initializePieces() = 0;
	virtual void updatePositonPieces() = 0;

	vector<Piece> getPieces();
	Position getPosition();

	int getHeight();
	int getWidth();
	virtual ~Component();
protected:
	vector<Piece>pieces;
	Position position;
};

