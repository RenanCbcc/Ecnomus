#pragma once
#include "Component.h"
class Aircraftcarrier :
	public Component
{
public:
	Aircraftcarrier();
	Aircraftcarrier(int, int);
	~Aircraftcarrier();
	std::string getName() override;
	void initializePieces()override;
	void updatePositonPieces()override;
};

