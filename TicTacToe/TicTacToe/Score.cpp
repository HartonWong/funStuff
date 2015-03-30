#include "GameBoard.h"
#include "Score.h"


bool Score::winChecking(char sign,const GameBoard &cGameBoard)
{
	if ((cGameBoard.pnArray[1] == sign) & (cGameBoard.pnArray[2] == sign) & (cGameBoard.pnArray[3] == sign))
		return true;
	if ((cGameBoard.pnArray[1] == sign) &(cGameBoard.pnArray[4] == sign) &(cGameBoard.pnArray[7] == sign))
		return true;
	if ((cGameBoard.pnArray[4] == sign) &(cGameBoard.pnArray[5] == sign) &(cGameBoard.pnArray[6] == sign))
		return true;
	if ((cGameBoard.pnArray[1] == sign) &(cGameBoard.pnArray[5] == sign) &(cGameBoard.pnArray[9] == sign))
		return true;
	if ((cGameBoard.pnArray[2] == sign) &(cGameBoard.pnArray[5] == sign) &(cGameBoard.pnArray[8] == sign))
		return true;
	if ((cGameBoard.pnArray[3] == sign) &(cGameBoard.pnArray[5] == sign) &(cGameBoard.pnArray[7] == sign))
		return true;
	if ((cGameBoard.pnArray[7] == sign) &(cGameBoard.pnArray[8] == sign) &(cGameBoard.pnArray[9] == sign))
		return true;
	if ((cGameBoard.pnArray[3] == sign) &(cGameBoard.pnArray[6] == sign) &(cGameBoard.pnArray[9] == sign))
		return true;
    return false;
}
Score::GameState Score::getGameState(const GameBoard &cGameBoard)
{
    if  (winChecking(cGameBoard.m_chPlayerSign,cGameBoard)==true)
        return PLAYER_WIN;
    if  (winChecking(cGameBoard.m_chComputerSign,cGameBoard)==true)
        return COMPUTER_WIN;
    return PLAYING;
}
