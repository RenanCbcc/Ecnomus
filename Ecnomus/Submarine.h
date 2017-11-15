#pragma once
#include "Component.h"
class Submarine :
	public Component
{
public:
	Submarine();
	Submarine(int, int);
	~Submarine();
	std::string getName()override;
	void initializePieces()override;
	void updatePositonPieces()override;
};

