#include "BusinessLogic.h"

BusinessLogic::BusinessLogic():board()
{
	moves_sent = 0;
	NUMBER_MOVES = 3;
	
}

std::string BusinessLogic::onSendCoordinateSquare(int row, int column)
{
	std::string response;
	if (!( row >>15 && row <0 ) && !(column >> 15 && column <0))
	{
		
		if (!board.playerSquare[row][column]->isFill())
		{
			manageCommand(XY_SQUARE, board.playerSquare[row][column]);
		}

		else {
			//std::cout << "You wasted a move" << std::endl;
			response= "You wasted a move";
			manageCommand(LOST_PLAY,nullptr);
		}

		moves_sent++;

	}
	else {
		response = "Out of range";
		//std::cout << "Out of range"<<std::endl;
	}
	return response;
}


void BusinessLogic::print()
{
	for (int i = 0; i < board.playerSquare.size(); i++)
	{
		for (int j = 0; j < board.playerSquare[i].size(); j++)
		{
			std::cout<< "| " << board.playerSquare[i][j]->getSquareSimbol();
		}
		std::cout<< "| " << std::endl;
	}

}

BusinessLogic::~BusinessLogic()
{
}


std::string BusinessLogic::manageCommand(int actionCommand, Square *square)
{
	std::string response;
	increaseResponsePlay();
	if (actionCommand == XY_SQUARE) 
	{
		if (board.getValueSquare(square->getRow(), square->getColumn())) 
		{
			Component *component = board.getComponent(square->getRow(), square->getColumn());

			board.immersePiece(square->getRow(), square->getColumn(), false);
			board.setSimbolSquare(square->getRow(), square->getColumn(), 'X');

			if (board.verifyComponentsSubmerged()) 
			{
				if (board.verifyComponentKill(component))
				{
					//std::cout << "You sank :" + component->getName() << std::endl;
					response = "You sank :" + component->getName();
				}else 
				{
					//std::cout <<  "You hit :" + component->getName() << std::endl;
					response = "You hit : " + component->getName();
				}
			}else
			{
				//std::cout << "You lost the game. Search a new opponent." << std::endl;
				response = "You lost the game. Search a new opponent.";
			}

		}else
		{
			board.setSimbolSquare(square->getRow(), square->getColumn(), ' ');
			response = "Water";
		}
		
		}
	return response;
}


void BusinessLogic::increaseResponsePlay(){
responses_receiver++;

if (responses_receiver == NUMBER_RESPONSES) {
	std::cout << "Your turn to play"<< std::endl;
	moves_sent = 0;
	responses_receiver = 0;
}
}