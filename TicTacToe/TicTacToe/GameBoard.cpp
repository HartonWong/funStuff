#include <iostream>
#include "GameBoard.h"
using namespace std;

GameBoard::GameBoard(int nSize,char chPlayerSign='X',char chComputerSign='O')
{
    m_nSize=nSize;
    m_chPlayerSign=chPlayerSign;
    m_chComputerSign=chComputerSign;
    pnArray= new char[m_nSize];

    char count = 49; //ASCII number 1 start at char 49
    for (int iii = 1; iii <10; iii++)
    {
        pnArray[iii] = count;
        count++;
    }
    printBoard();
}

//destory the dynamic array to avoid memory leak
GameBoard::~GameBoard()
{
    if(pnArray)
    {
        delete[] pnArray;
        pnArray=0;
    }
}

bool GameBoard::setPlayerPos(int playerPos)
{
    if (playerPos < 1 | playerPos > 9)
    {
        cout << "Your position should be within 1 and 9 \n";
        return false;
    }
    if (pnArray[playerPos]== m_chPlayerSign)
    {
        cout << "You cannot replace where you have placed \n";
        return false;
    }
    if (pnArray[playerPos] == m_chComputerSign)
    {
        cout << "You cannot replace where I have placed \n";
        return false;
    }
    pnArray[playerPos]=m_chPlayerSign;
    printBoard();
    return true;
}
bool GameBoard::setComputerPos(int computerPos)
{
    if (pnArray[computerPos] == m_chPlayerSign | pnArray[computerPos] == m_chComputerSign)
        return false;
    else
    {
        pnArray[computerPos]=m_chComputerSign;
        printBoard();
        return true;
    }
}


char GameBoard::getGridChar(int pos)
{
    return pnArray[pos];
}
char GameBoard::getPlayerSign()
{
    return m_chPlayerSign;
}
char GameBoard::getComputerSign()
{
    return m_chComputerSign;
}


//print the game board based on the stored char in pnArray
void GameBoard::printBoard()
{
    using namespace std;
    cout << " " << pnArray[1] <<" | "<<pnArray[2]<<" | "<<pnArray[3]<<" " << "\n";
	cout << "---+---+---" << "\n";
	cout << " " << pnArray[4] << " | " << pnArray[5] << " | " << pnArray[6] << " " << "\n";
	cout << "---+---+---" << "\n";
	cout << " " << pnArray[7] << " | " << pnArray[8] << " | " << pnArray[9] << " " << "\n";;
}
