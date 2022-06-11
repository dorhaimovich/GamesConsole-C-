#pragma once
#include <vector>

class View
{
public:
	View() {}
	virtual ~View() {}

	/* Methods */
	virtual int move(std::vector<char>* board) = 0;

private:

};