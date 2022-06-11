#pragma once
#include "BoardGame.h"
#include <vector>

class TicTacToe : public BoardGame
{
public:
	TicTacToe(Opponent* opponent);
	~TicTacToe();

	/* Getters & Setters */
	std::vector<char>* getBoard();
	int setElementOnBoard(int index, bool player);
	int getState(int index, bool player);
	
	/* Methods */
	void startGame();
	void getPlayerMove();
	int getOpponentMove();
	void printBoard();
	bool checkState(int index);

protected:
	
	/* Methods */
	void printDivider();
	void printLine(std::vector<char>::iterator& it);
	
	bool checkRows(int index);
	bool checkColumns(int index);
	bool checkSlant(int index);
	bool checkFullBoard(int index);
};