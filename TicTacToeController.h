#pragma once
#include "GameController.h"
#include "TicTacToe.h"

class TTTcontroller : public GameController 
{
public:
	TTTcontroller(TicTacToe* board, View* view);
	~TTTcontroller();

	/* Getters & Setters */
	void setBoardGame(BoardGame* board);
	
	/* Methods */
	void play();

private:

};