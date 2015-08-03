#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED
#include <string>
class GameBoard
{
    private:
    std::string m_chPlayerSign;
    std::string m_chComputerSign;
    int m_nRow;
    int m_nCol;
    int m_nSize;
    std::string *pnArray;

    // default constructor is not allowed;
    GameBoard();
    void printLine();
    void printNum(int &index);
    std::string intToString(int integer);


    public:
    GameBoard(int nRow,int nCol,std::string chPlayerSign,std::string chComputerSign);
    ~GameBoard();

    //return true if player position is set correctly, and false if something went wrong
    bool setPlayerPos(int playerPos);
    //return true if computer position is set correctly, and false if something went wrong
    bool setComputerPos(int computerPos);
    //return the std::string in particular position
    std::string getGridChar(int pos);
    std::string getPlayerSign();
    std::string getComputerSign();
    void printBoard();

    friend class Score;

};

#endif // GAMEBOARD_H_INCLUDED
