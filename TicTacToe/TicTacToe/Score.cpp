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
	bool flagConsecutiveHorz = false;
	bool flagConsecutiveVert = false;
	if (check(cGameBoard, sign, "Horizontal", flagConsecutiveHorz) | check(cGameBoard, sign, "Vertical", flagConsecutiveVert))
        return true;
    else
        return false;
}

bool Score::check(const GameBoard &cGameBoard, std::string sign, std::string mode, bool& flagConsecutive)
{
	int defaultHitCount = 1;
	int hitCount = defaultHitCount;
	int firstBoundary=0;
	int secondBoundary=0;

	if (mode == "Horizontal")
	{
		firstBoundary = cGameBoard.m_nRow;
		secondBoundary = cGameBoard.m_nCol;
	}
	else if (mode == "Vertical")
	{
		firstBoundary = cGameBoard.m_nCol;
		secondBoundary = cGameBoard.m_nRow;
	}

	for (int iii = 1; iii<firstBoundary; iii++)
    {
		for (int jjj = 1; jjj<secondBoundary; jjj++)      //for every row
        {

			if (arrayCheck(cGameBoard,mode,iii,jjj,sign))
			{
				if (flagConsecutive)
				hitCount++;
				else
					hitCount = defaultHitCount;

				flagConsecutive=true;
			}
			else
			{
				flagConsecutive=false;
			}
			if(hitCount>=cGameBoard.m_nLinks)         //number of consecutive sign is greater than the required number of links
			{
				return true;
			}
        }
    }
    
    if(hitCount<cGameBoard.m_nLinks)         //number of consecutive sign is greater than the required number of links
   {
      return false;
   }
}


bool Score::arrayCheck(const GameBoard &cGameBoard, const std::string mode, const int iii, const int jjj, const std::string sign)
{
	if (mode == "Horizontal")
	{
		return cGameBoard.pnArray[iii][jjj] == sign;
	}
	else if (mode == "Vertical")
	{
		return cGameBoard.pnArray[jjj][iii] == sign;
	}
}


