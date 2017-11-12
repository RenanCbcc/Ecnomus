#include "Board.h"
#include "Submarine.h"
#include "Seaplane.h"
#include "Cruiser.h"
#include "Battleship.h"
#include "Aircraftcarrier.h"

Board::Board()
{
}

void Board::shufflingPieces()
{
	components = { Submarine(), Submarine(), Submarine(), Submarine(),
					Seaplane(), Seaplane(),	Seaplane(),	Cruiser(), Cruiser(),
						Cruiser(), Battleship(), Battleship(), Aircraftcarrier() };
	
	/*
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	while (components.size() > 0) {
		int randomIndexList = ( rand.);
		int randomRow = (new Random()).nextInt(15);
		int randomColumn = (new Random()).nextInt(15);

		if (verifyAreaComponentSupport(components.get(randomIndexList), randomRow, randomColumn) && !verifyComponentArea(listComponents.get(randomIndexList), randomRow, randomColumn)) {
			Component component = listComponents.get(randomIndexList);
			component.getPosition().setCoordinatePosition(randomRow, randomColumn);
			component.updatePositonPieces();

			components.add(component);
			putComponentInBoard(component);

			listComponents.remove(randomIndexList);
		}
	}*/
}



Board::~Board()
{
}
