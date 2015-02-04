#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED

class GameBoard
{
    private:
    char m_chPlayerSign;
    char m_chComputerSign;
    int m_nSize;
    char *pnArray;

    // default constructor is not allowed;
    GameBoard();

    public:
    GameBoard(int nSize,char chPlayerSign='X',char chComputerSign='O');
    ~GameBoard();

    bool setPlayerPos(int playerPos);
    bool setComputerPos(int computerPos);
    char getGridChar(int pos);
    char getPlayerSign();
    char getComputerSign();
    void printBoard();


};

#endif // GAMEBOARD_H_INCLUDED
