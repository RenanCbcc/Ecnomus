#pragma once
#include "Component.h"
#include <random>
class Board
{
public:
	Board();
	void shufflingPieces();
	bool verifyAreaComponentSupport(Component *, int, int);
	~Board();
private:
	list<Component> components;
	vector<vector<bool>> area;
};

