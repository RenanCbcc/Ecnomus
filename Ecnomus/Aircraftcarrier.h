#pragma once
#include "Component.h"
class Aircraftcarrier :
	public Component
{
public:
	Aircraftcarrier();
	Aircraftcarrier(int, int);
	~Aircraftcarrier();
	string getName();
	void initializePieces();
	void updatePositonPieces();
};

