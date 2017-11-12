#pragma once
#include "Component.h"
class Battleship :
	public Component
{
public:
	Battleship();
	Battleship(int,int);
	~Battleship();
	string getName();
	void initializePieces();
	void updatePositonPieces();
};

