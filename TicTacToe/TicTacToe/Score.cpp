#include "Score.h"

GameState Score::getGameState(GameBoard &cGameBoard)
{

}

GameState Score::winChecking(char sign)
{
	bool playerWin = false;
	if (gridPos[1] == playerSign & gridPos[2] == playerSign & gridPos[3] == playerSign)
		return playerWin = true;
	if (gridPos[1] == playerSign &gridPos[4] == playerSign &gridPos[7] == playerSign)
		return playerWin = true;
	if (gridPos[4] == playerSign &gridPos[5] == playerSign &gridPos[6] == playerSign)
		return playerWin = true;
	if (gridPos[1] == playerSign &gridPos[5] == playerSign &gridPos[9] == playerSign)
		return playerWin = true;
	if (gridPos[2] == playerSign &gridPos[5] == playerSign &gridPos[8] == playerSign)
		return playerWin = true;
	if (gridPos[3] == playerSign &gridPos[5] == playerSign &gridPos[7] == playerSign)
		return playerWin = true;
	if (gridPos[7] == playerSign &gridPos[8] == playerSign &gridPos[9] == playerSign)
		return playerWin = true;
	if (gridPos[3] == playerSign &gridPos[6] == playerSign &gridPos[9] == playerSign)
		return playerWin = true;
}
Player_WIN;
