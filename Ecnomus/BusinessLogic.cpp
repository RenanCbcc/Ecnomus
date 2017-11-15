#include "BusinessLogic.h"



BusinessLogic::BusinessLogic()
{
	moves_sent = 0;
	responses_receiver = 0;
	NUMBER_MOVES = 3;
}

void BusinessLogic::onSendCoordinateSquare(Square *square)
{
	if (moves_sent < NUMBER_MOVES && responses_receiver == 0 
	{
		if (!adversarySquare[row][column].isFill())
		{
			sendCommand(XY_SQUARE, square->getRow(), square->getColumn());
		}
		void BusinessLogic::increaseResponsePlay()
		{
		}
		else {
			std::cout << "You wasted a move" << endl;
			sendCommand(LOST_PLAY, new byte[]{ 0 }));
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

void BusinessLogic::increaseResponsePlay(){
responses_receiver++;

if (responses_receiver == NUMBER_RESPONSES) {
	std::cout << "Your turn to play"<< std::endl;
	moves_sent = 0;
	responses_receiver = 0;
}
}