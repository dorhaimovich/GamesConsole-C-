#pragma once
#include <vector>

class Opponent
{
public:
	Opponent() {}
	virtual ~Opponent() = 0 {};

	/* Methods */
	virtual int action(std::vector<char>& board) = 0;

private:
};