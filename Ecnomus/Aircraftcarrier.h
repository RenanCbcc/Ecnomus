#pragma once
#include "Component.h"
class Aircraftcarrier :
	public Component
{
public:
	Aircraftcarrier();
	Aircraftcarrier(int, int);
	~Aircraftcarrier();
	string getName() override;
	void initializePieces()override;
	void updatePositonPieces()override;
};

