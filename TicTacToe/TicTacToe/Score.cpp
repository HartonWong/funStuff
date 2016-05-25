#include "stdafx.h"	
#include "GameBoard.h"
#include "Score.h"
#include <iostream>		/*cout,cin*/

int count = 0;
Score::GameState Score::getGameState(const GameBoard &cGameBoard,const std::string sign)
{
	count++;
	int minRound = cGameBoard.m_nLinks * 2 - 1;
	//if the game just start and hasn't go for the minimum round to win, skip the checking process and just return PLAYING STATE
	if (count < minRound)
		return PLAYING;


	if (winChecking(sign, cGameBoard) == true)
	{
		if (sign == cGameBoard.m_chPlayerSign)
		{
			std::cout << " You Win!! :)" << "\n";
			return PLAYER_WIN;
		}
		else if (sign == cGameBoard.m_chComputerSign)
		{
			std::cout << " I Win!! :)" << "\n";
			return COMPUTER_WIN;
		}
	}

	//if no one win, return as playing state
	return PLAYING;
}

bool Score::winChecking(std::string sign,const GameBoard &cGameBoard)
{
	if (checkHori(cGameBoard, sign) | checkVert(cGameBoard, sign))
        return true;
    else
        return false;
}

bool Score::checkHori(const GameBoard &cGameBoard, std::string sign)
{
	int hitCount, defaultHitCount = 1;
	bool flagConsecutive = false;

	for (int iii = 1; iii<cGameBoard.m_nRow; iii++)
    {
		for (int jjj = 1; jjj<cGameBoard.m_nCol; jjj++)      //for every row
        {
			bool condition = cGameBoard.pnArray[iii][jjj] == sign;
			if (isConsecutive(condition, flagConsecutive, hitCount, cGameBoard.m_nLinks, defaultHitCount))
				return true;
        }
    }
    return false;
}

bool Score::checkHori(const GameBoard &cGameBoard, std::string sign)
{
	int hitCount, defaultHitCount = 1;
	bool flagConsecutive = false;

	for (int iii = 1; iii<cGameBoard.m_nRow; iii++)
	{
		for (int jjj = 1; jjj<cGameBoard.m_nCol; jjj++)      //for every row
		{
			bool condition = cGameBoard.pnArray[iii][jjj] == sign;
			if (isConsecutive(condition, flagConsecutive, hitCount, cGameBoard.m_nLinks, defaultHitCount))
				return true;
		}
	}
	return false;
}
bool Score::checkVert(const GameBoard &cGameBoard, std::string sign)
{
	int hitCount, defaultHitCount = 1;
	bool flagConsecutive = false;

	for (int iii = 1; iii<cGameBoard.m_nCol; iii++)
	{
		for (int jjj = 1; jjj<cGameBoard.m_nRow; jjj++)      //for every row
		{
			bool condition = cGameBoard.pnArray[jjj][iii] == sign;
			if (isConsecutive(condition, flagConsecutive, hitCount, cGameBoard.m_nLinks, defaultHitCount))
				return true;
		}
	}
	return false;
}
bool Score::isConsecutive(const bool &conditionMet, bool &flagConsecutive, int &hitCount, const int &links,const int &defaultHitCount)
{
	if (conditionMet)
	{
		if (flagConsecutive)
			hitCount++;
		else
			hitCount = defaultHitCount;

		flagConsecutive = true;
	}
	else
	{
		flagConsecutive = false;
	}
	if (hitCount >= links)         //number of consecutive sign is greater than the required number of links
	{
		return true;
	}
	else
		return false;
}
