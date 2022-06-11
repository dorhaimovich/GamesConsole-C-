#pragma once
#include "Opponent.h"
#include <vector>

class MediumLevel : public Opponent
{
public:
	MediumLevel();
	~MediumLevel();
	/* Methods */
	int action(std::vector<char>& board);

private:

	/* Methods */
	int checkRows(std::vector<char>& board, int index);
	int checkColumns(std::vector<char>& board, int index);
	int checkSlant(std::vector<char>& board, int index);

};