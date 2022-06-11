#include "TicTacToeController.h"

TTTcontroller::TTTcontroller(TicTacToe* board, View* view)
{
	m_boardGame = board;
	m_view = view;
}

TTTcontroller::~TTTcontroller() {}

void TTTcontroller::setBoardGame(BoardGame* board)
{
	m_boardGame = board;
}

void TTTcontroller::play()
{
	m_boardGame->startGame();
	m_boardGame->printBoard();
	bool gameProgress = true;
	while (gameProgress)
	{
		m_boardGame->getPlayerMove();
		gameProgress = m_boardGame->checkState(m_boardGame->getState(m_boardGame->setElementOnBoard(m_view->move(m_boardGame->getBoard()), true), true));
		if (gameProgress == false)
			break;
		gameProgress = m_boardGame->checkState(m_boardGame->getState(m_boardGame->setElementOnBoard(m_boardGame->getOpponentMove(), false), false));
	}

}
