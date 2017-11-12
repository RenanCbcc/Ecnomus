#pragma once
#include "Component.h"
class Seaplane :
	public Component
{
public:
	Seaplane();
	Seaplane(int, int);
	~Seaplane();
	string getName()override;
	void initializePieces()override;
	void updatePositonPieces()override;
};

