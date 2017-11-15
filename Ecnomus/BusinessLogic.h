#pragma once
#include "Square.h"
#include <vector>
#include <string>
#include<iostream>


class BusinessLogic
{
public:
	BusinessLogic();
	void onSendCoordinateSquare(Square*);
	void increaseResponsePlay();
	void print();
	~BusinessLogic();

private:
	std::vector<std::vector<Square*>> adversarySquare;
	void createCleanBoard();
	int moves_sent;
	int responses_receiver;
	int NUMBER_MOVES;
	int NUMBER_RESPONSES;

	int const START = 10;
	int const XY_SQUARE = 20;
	int const RESPONSE_XY = 30;
	int const WIN_GAME = 40;
	int const LOST_PLAY = 50;


};

