#include<iostream>
#include <string>
#include "BusinessLogic.h"
#include "Board.h"
#include <vector>
#include <cstdlib>

int main() {
	int x, y;
	BusinessLogic battleship;
	battleship.print();

	while (true) {
	std::cout << "[x : ";
	std::cin >> x;

	std::cout << "y] : ";
	std::cin >> y;
	battleship.onSendCoordinateSquare(x, y);
	battleship.print();
}
	return 0;
}