#include "BoardGame.h"
#include "TicTacToe.h"
#include "EasyLevel.h"
#include "MediumLevel.h"
#include <iostream>

TicTacToe::TicTacToe(Opponent* opponent)
{
	m_boardSize = 9;
	m_board = new std::vector<char>(m_boardSize,' ');
	m_opponent = opponent;
}

TicTacToe::~TicTacToe()
{
	delete m_board;
}

void TicTacToe::startGame()
{
	std::cout << std::endl << "Welcome to a TicTacToe Game!" << std::endl;
	EasyLevel* el = dynamic_cast<EasyLevel*>(m_opponent);
	if (el != nullptr)
		std::cout << "you choosed the easy level, you will be X" << std::endl;
	MediumLevel* ml = dynamic_cast<MediumLevel*>(m_opponent);
	if (ml != nullptr)
		std::cout << "you choosed the medium level, you will be X" << std::endl;
	std::cout << "For choosing a square to mark, here is an example of the numbers for each square." << std::endl << std::endl;
	std::cout << "  " << "2 | 1 | 0" << std::endl;
	printDivider();
	std::cout << "  " << "5 | 4 | 3" << std::endl;
	printDivider();
	std::cout << "  " << "8 | 7 | 6" << std::endl << std::endl;
	std::cout << "Remember the numbers and choose wisely, GOOD LUCK!" << std::endl << std::endl;

}

	

void TicTacToe::getPlayerMove()
{
	std::cout << std::endl << "Choose which square to mark:" << std::endl;
	std::cout << std::endl << ">>";
}

int TicTacToe::getOpponentMove()
{
	std::cout << std::endl << "Opponent turn:" << std::endl << std::endl;
	return m_opponent->action(*m_board);
}

void TicTacToe::printBoard() {
	
	auto it = m_board->begin();
	
	printLine(it);
	printDivider();
	printLine(it);
	printDivider();
	printLine(it);

}

bool TicTacToe::checkState(int index)
{
	printBoard();
	switch (index)
	{
	case 0:
		std::cout << std::endl << "Opponent won, Better luck next time!" << std::endl;
		return false;
	case 1:
		std::cout << std::endl << "You won, Good job!" << std::endl;
		return false;
	case 2:
		std::cout << std::endl << "Its a tie, Game end" << std::endl;
		return false;
	case 3:
		std::cout << std::endl << "Game still in progress..." << std::endl;
		return true;
	}
}

int TicTacToe::getState(int index, bool player)
{

	if (checkRows(index))
		return player;

	if (checkColumns(index))
	{
		return player;
	}

	if (checkSlant(index))
		return player;

	if (checkFullBoard(index))
	{
		return 2;
	}

	return 3;
}

std::vector<char>* TicTacToe::getBoard()
{
	return m_board;
}

int TicTacToe::setElementOnBoard(int index, bool player)
{
	if (true == player )
		m_board->at(index) = 'X';
	else
		m_board->at(index) = 'O';

	return index;
}

void TicTacToe::printDivider()
{
	std::cout << "  " << "--+---+--" << std::endl;
}

void TicTacToe::printLine(std::vector<char>::iterator& it)
{
	std::cout << "  " <<  *(it++) << " | " << *(it++) << " | " << *(it++) << std::endl;
}

bool TicTacToe::checkRows(int index)
{
	int counter = 0;
	if (index <= 5 && index >= 3)
		counter = 3;
	else if (index <= 8 && index >= 6)
		counter = 6;

	if (m_board->at(index) == m_board->at((index + 1) % 3 + counter) && m_board->at((index + 1) % 3 + counter) == m_board->at((index + 2) % 3 + counter))
		return true;

	return false;
}

bool TicTacToe::checkColumns(int index)
{
	if (m_board->at(index) == m_board->at((index + 3) % 9) && m_board->at((index + 3) % 9) == m_board->at((index + 6) % 9))
	{
		return true;
	}
	
	return false;
}

bool TicTacToe::checkSlant(int index)
{
	if ((index % 2) == 0)
	{
		if (m_board->at(2) == m_board->at(4) && m_board->at(4) == m_board->at(6) && m_board->at(2) != ' ')
		{
			return true;
		}
		if (m_board->at(0) == m_board->at(4) && m_board->at(4) == m_board->at(8) && m_board->at(0) != ' ')
		{
			return true;
		}
	}
	return false;
}

bool TicTacToe::checkFullBoard(int index)
{
	for (int i = 0; i < 9; i++)
	{
		if (m_board->at(i) == ' ')
			return false;
	}
	return true;
}
