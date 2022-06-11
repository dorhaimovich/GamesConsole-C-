#pragma once
#include "Opponent.h"

class BoardGame
{
public:
	BoardGame()
		: m_board(nullptr), m_boardSize(0), m_opponent(nullptr)
	{}

	virtual ~BoardGame() = 0 {};
	
	/* Getters & Setters */
	virtual std::vector<char>* getBoard() = 0;
	virtual int getState(int index, bool player) = 0;
	virtual int setElementOnBoard(int index, bool player) = 0;

	/* Methods */
	virtual void startGame() = 0;
	virtual void getPlayerMove() = 0;
	virtual int getOpponentMove() = 0;
	virtual void printBoard() = 0;
	virtual bool checkState(int index) = 0;

protected:

	int m_boardSize;
	std::vector<char>* m_board;
	Opponent* m_opponent;

};

