#pragma once
#include "Component.h"
class Submarine :
	public Component
{
public:
	Submarine();
	Submarine(int, int);
	~Submarine();
	string getName();
	void initializePieces();
	void updatePositonPieces();
};

