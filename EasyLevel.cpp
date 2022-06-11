#include "EasyLevel.h"

EasyLevel::EasyLevel() {}

EasyLevel::~EasyLevel() {}

int EasyLevel::action(std::vector<char>& board)
{
	int index = rand() % 9;
	while (board.at(index) != ' ')
	{
		index = (index + 1) % 9;
	}

	return index;
}
