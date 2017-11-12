#pragma once
#include<string>

class Interface
{
	virtual std::string getName() = 0;
	virtual void initializePieces() = 0;
	virtual void updatePositonPieces() = 0;

};