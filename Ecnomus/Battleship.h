#pragma once
#include "Component.h"
class Battleship :
	public Component
{
public:
	Battleship();
	Battleship(int,int);
	~Battleship();
	string getName()override;
	void initializePieces()override;
	void updatePositonPieces()override;
};

