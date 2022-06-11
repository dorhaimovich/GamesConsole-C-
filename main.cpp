#include "TicTacToe.h"
#include "TicTacToeController.h"
#include "EasyLevel.h"
#include "MediumLevel.h"
#include "ConsoleView.h"

int main()
{
	EasyLevel easy;
	MediumLevel med;

	TicTacToe game[2] = { TicTacToe(&easy), TicTacToe(&med) };
	ConsoleView view;
	
	GameController* controler = new TTTcontroller(&game[0], &view);

	controler->play();
	
	controler->setBoardGame(&game[1]);

	controler->play();

	delete controler;
}