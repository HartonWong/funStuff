#include <iostream>
#include "GameBoard.h"


//constructor
GameBoard::GameBoard(int nRow,int nCol,char chPlayerSign='X',char chComputerSign='O')
{
    m_nRow=nRow;
    m_nCol=nCol;
    m_nSize=nRow*nCol;
    m_chPlayerSign=chPlayerSign;
    m_chComputerSign=chComputerSign;
    pnArray= new char[m_nSize+1];

    char count = 49; //ASCII number 1 start at char 49
    for (int iii = 1; iii <=m_nSize; iii++)
    {
        pnArray[iii] = count;
        count++;
        /*
        if(count<=57)
        {
            pnArray[iii] = count;
            count++;
        }
        else
        {

        }
        */
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
    using namespace std;
    if (playerPos < 1 | playerPos > m_nSize)
    {
        cout << "Your position should be within 1 and "<<m_nSize<<" \n";
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

//return false if computer position collide with occupied position
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
    int index=1;
    printLine();
    for(int row=1;row<=m_nRow;++row)
    {
        printNum(index);
        printLine();
    }
}

void GameBoard::printLine()
{
    using namespace std;
    for(int col=1;col<m_nCol;++col)
    {
        cout<<"---+";
    }
    cout << "---\n";
}
void GameBoard::printNum(int &index)
{
    using namespace std;
    cout<<" ";
    for(int col=1;col<m_nCol;++col)
    {
        cout<< pnArray[index]<<" | ";
        ++index;
    }
    cout<< pnArray[index]<<"\n";
    ++index;
}
std::string GameBoard::intToString(int integer)
{
    using namespace std;
    string name("John");
    return name;
}
