#pragma once
#include "Opponent.h"
#include <vector>

class EasyLevel : public Opponent
{
public:
	EasyLevel();
	~EasyLevel();

	/* Methods */
	int action(std::vector<char>& board);
private:

};