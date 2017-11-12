#pragma once
#include "Component.h"
class Cruiser :
	public Component
{
public:
	Cruiser();
	Cruiser(int,int);
	~Cruiser();

	string getName();
	void initializePieces();
	void updatePositonPieces();

};

