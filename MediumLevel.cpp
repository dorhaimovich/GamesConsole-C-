#include "MediumLevel.h"

MediumLevel::MediumLevel() {}

MediumLevel::~MediumLevel() {}

int MediumLevel::action(std::vector<char>& board)
{
	int target = -1;

	if (board.at(4) == ' ')
		return 4;

	for (int i = 0; i < 9; i++)
	{
		if (board.at(i) == 'X')
		{
			target = checkRows(board, i);
			if (target == -1)
			{
				target = checkColumns(board, i);
				if (target == -1)
					target = checkSlant(board, i);
				else
					break;
			}
			else
				break;
			
		}
	}
	if (target == -1)
	{
		for (int i = 0; i < 9; i++)
		{
			if (board.at(i) == ' ')
			{
				target = i;
				break;
			}
		}
	}

	return target;
}

int MediumLevel::checkRows(std::vector<char>& board, int index)
{
	int counter = 0;
	if (index <= 5 && index >= 3)
		counter = 3;
	else if (index <= 8 && index >= 6)
		counter = 6;

	if (board.at(index) == board.at((index + 1) % 3 + counter) && board.at((index + 2) % 3 + counter) == ' ')
		return (index + 2) % 3 + counter;
	else if (board.at(index) == board.at((index + 2) % 3 + counter) && board.at((index + 1) % 3 + counter) == ' ')
		return (index + 1) % 3 + counter;
	else 
		return -1;
}

int MediumLevel::checkColumns(std::vector<char>& board, int index)
{
	if (board.at(index) == board.at((index + 3) % 9) && board.at((index + 6) % 9) == ' ')
		return (index + 6) % 9;
	else if (board.at(index) == board.at((index + 6) % 9) && board.at((index + 3) % 9) == ' ')
		return (index + 3) % 9;
	else
		return -1;	
}

int MediumLevel::checkSlant(std::vector<char>& board, int index)
{
	if ((index % 2) == 0)
	{
		if (board.at(2) == board.at(4) && board.at(2) == 'X' && board.at(6) == ' ')
			return 6;
		if (board.at(4) == board.at(6) && board.at(4) == 'X' && board.at(2) == ' ')
			return 2;
		if (board.at(0) == board.at(4) && board.at(0) == 'X' && board.at(8) == ' ')
			return 8;
		if (board.at(4) == board.at(8) && board.at(4) == 'X' && board.at(0) == ' ')
			return 0;
	}

	return -1;
}
