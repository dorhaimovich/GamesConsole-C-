#pragma once
#include "View.h"
#include <vector>

class ConsoleView : public View
{
public:
	ConsoleView();
	~ConsoleView();

	/* Methods */
	int move(std::vector<char>* board);

private:

};