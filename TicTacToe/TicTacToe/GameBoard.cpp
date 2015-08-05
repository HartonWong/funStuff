#include <iostream>
#include "GameBoard.h"
#include <sstream>      //for ostringstream used in int conversion


//constructor
GameBoard::GameBoard(int nRow,int nCol,std::string chPlayerSign,std::string chComputerSign,int chLinks)
{
    m_nRow=nRow;
    m_nCol=nCol;
    m_nSize=nRow*nCol;
    m_chPlayerSign=chPlayerSign;
    m_chComputerSign=chComputerSign;
    m_nLinks=chLinks;
    //initialize 2D dynamic array
    pnArray= new std::string*[m_nRow+1];
    for(int row=1;row<=m_nRow;row++)
    {
        pnArray[row]=new std::string[m_nCol+1];
    }

    //pnArray= new std::string[m_nSize+1];
    //allocate 2D array with number from 1 to boardsize
    int index=1;
    for (int iii = 1; iii <=m_nRow; iii++)
    {
        for(int jjj=1;jjj<=m_nCol;jjj++)
        {
            pnArray[iii][jjj]=intToString(index);
            index++;
        }
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
    int row=positionToRow(playerPos);
    int col=positionToCol(playerPos);
    cout<<row<<"row \n";
    cout<<col<<"col \n";
    if (playerPos < 1 | playerPos > m_nSize)
    {
        cout << "Your position should be within 1 and "<<m_nSize<<" \n";
        return false;
    }

    if (pnArray[row][col]==m_chPlayerSign)
    {
        cout << "You cannot replace where you have placed \n";
        return false;
    }
    if (pnArray[row][col]==m_chComputerSign)
    {
        cout << "You cannot replace where I have placed \n";
        return false;
    }

    pnArray[row][col]=m_chPlayerSign;
    printBoard();
    return true;
}

//return false if computer position collide with occupied position
bool GameBoard::setComputerPos(int computerPos)
{
    int row=positionToRow(computerPos);
    int col=positionToCol(computerPos);

    if ((pnArray[row][col]==m_chPlayerSign) | (pnArray[row][col]==m_chComputerSign))
        return false;
    else
    {
        pnArray[row][col]=m_chComputerSign;
        printBoard();
        return true;
    }
}

/*
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
*/

//print the game board based on the stored char in pnArray
void GameBoard::printBoard()
{
    int index=1;
    printLine();
    for(int row=1;row<=m_nRow;++row)
    {
        printNum(index,row);
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
void GameBoard::printNum(int &index,int row)
{
    using namespace std;
    cout<<" ";
    for(int col=1;col<m_nCol;++col)
    {
        if((index<=9)|(pnArray[row][col]==m_chPlayerSign) | (pnArray[row][col]==m_chComputerSign))  //1 digit number or is a sign
        cout<< pnArray[row][col]<<" | ";
        else                    //2 digit number, delete one space
        cout<< pnArray[row][col]<<"| ";
        ++index;
    }
    cout<< pnArray[row][m_nCol]<<"\n";
    ++index;
}
std::string GameBoard::intToString(int integer)
{
    using namespace std;
    ostringstream convert;  // stream used for the conversion
    convert<<integer;
    return  convert.str();  //return the contents of the stream
}

int GameBoard::positionToRow(int position)
{
    if(position%m_nCol==0)
        return position/m_nCol;
    return (position/m_nCol)+1;
}
int GameBoard::positionToCol(int position)
{
    if(position%m_nCol==0)
        return m_nCol;
    return position%m_nCol;
}
std::string& GameBoard::setBoardValue(int position)
{
    std::string value=intToString(position);
    for (int iii = 1; iii <=m_nRow; iii++)
    {
        for(int jjj=1;jjj<=m_nCol;jjj++)
        {
            if(pnArray[iii][jjj]==intToString(position))
                return pnArray[iii][jjj];
        }
    }
}

