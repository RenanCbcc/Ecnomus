#include "BusinessLogic.h"

BusinessLogic::BusinessLogic():board()
{
	moves_sent = 0;
	responses_receiver = 0;
	NUMBER_MOVES = 3;
	NUMBER_RESPONSES = 3;
}

void BusinessLogic::onSendCoordinateSquare(Square *square)
{
	increaseResponsePlay();
	if (moves_sent < NUMBER_MOVES && responses_receiver == 0)
	{
		
		if (!adversarySquare[square->getRow()][square->getColumn()]->isFill())
		{
			manageCommand(XY_SQUARE, square);
		}

		else {
			std::cout << "You wasted a move" << std::endl;
			manageCommand(LOST_PLAY);
		}

		moves_sent++;

	}
}


void BusinessLogic::print()
{
	for (int i = 0; i < adversarySquare.size(); i++)
	{
		for (int j = 0; j < adversarySquare[i].size(); j++)
		{
			std::cout << "| " << adversarySquare[i][j]->getSquareSimbol();
		}
		std::cout << "| " << std::endl;
	}

}

BusinessLogic::~BusinessLogic()
{
}

void BusinessLogic::createCleanBoard()
{
	for (int x = 0; x < 15; x++) {
		std::vector <Square*> temp;
		for (int y = 0; y < 15; y++)
		{
			temp.push_back(new Square(x, y, '#', false, true));
		}
		adversarySquare.push_back(temp);
	}

}

void BusinessLogic::manageCommand(int, Square *)
{

}

void BusinessLogic::manageCommand(int)
{

}

void BusinessLogic::increaseResponsePlay(){
responses_receiver++;

if (responses_receiver == NUMBER_RESPONSES) {
	std::cout << "Your turn to play"<< std::endl;
	moves_sent = 0;
	responses_receiver = 0;
}
}