#pragma once
#include "Component.h"
class Submarine :
	public Component
{
public:
	Submarine();
	Submarine(int, int);
	~Submarine();
	string getName()override;
	void initializePieces()override;
	void updatePositonPieces()override;
};

