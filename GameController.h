#pragma once
#include "ConsoleView.h"
#include "BoardGame.h"

class GameController
{
public:
	GameController()
		: m_boardGame(nullptr), m_view(nullptr)
	{}
	
	virtual ~GameController() = 0 {}

	/* Getters & Setters */
	virtual void setBoardGame(BoardGame* m_boardGame) = 0;
	
	/* Methods */
	virtual void play() = 0;

protected:

	View* m_view;
	BoardGame* m_boardGame;

};