#pragma once

#include "Position.h"
#include "Piece.h"
#include <string>
#include <vector>
#include <list>
class Component
{
public:
	Component();
	Component(int, int);	
	
	virtual ~Component();
	
	virtual std::string getName() = 0;
	virtual void initializePieces() =0;
	virtual void updatePositonPieces() =0;

	std::vector<Piece*> &getPieces();
	Position getPosition();

	int getHeight();
	int getWidth();

protected:
	std::vector<Piece*>pieces;
	Position position;
};