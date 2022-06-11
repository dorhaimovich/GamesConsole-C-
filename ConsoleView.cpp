#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView() {}

ConsoleView::~ConsoleView() {}

int ConsoleView::move(std::vector<char>* board)
{
	int index;
	while (true)
	{
		std::cin >> index;
		if (index < 0 || index > 9)
			std::cout << "Square not in range" << std::endl << "choose another square >> ";
		else if (board->at(index) != ' ')
			std::cout << "Unvalid square, already taken!" << std::endl << "Choose another square >> ";
		else return index;
	}

	return index;

}
