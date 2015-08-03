#include <iostream>
#include "GameBoard.h"
#include <sstream>      //for ostringstream used in int conversion


//constructor
GameBoard::GameBoard(int nRow,int nCol,std::string chPlayerSign,std::string chComputerSign)
{
    m_nRow=nRow;
    m_nCol=nCol;
    m_nSize=nRow*nCol;
    m_chPlayerSign=chPlayerSign;
    m_chComputerSign=chComputerSign;
    pnArray= new std::string[m_nSize+1];

    for (int iii = 1; iii <=m_nSize; iii++)
    {
        pnArray[iii]=intToString(iii);
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
    if(playerPos>9)
        pnArray[playerPos]+=" ";
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


std::string GameBoard::getGridChar(int pos)
{
    return pnArray[pos];
}
std::string GameBoard::getPlayerSign()
{
    return m_chPlayerSign;
}
std::string GameBoard::getComputerSign()
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
        if(index<=9)             //1 digit number
        cout<< pnArray[index]<<" | ";
        else                    //2 digit number, delete one space
        cout<< pnArray[index]<<"| ";
        ++index;
    }
    cout<< pnArray[index]<<"\n";
    ++index;
}
std::string GameBoard::intToString(int integer)
{
    using namespace std;
    ostringstream convert;  // stream used for the conversion
    convert<<integer;
    return  convert.str();  //return the contents of the stream
}
