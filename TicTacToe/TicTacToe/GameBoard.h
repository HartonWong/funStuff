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
    GameBoard(int nSize,char chPlayerSign,char chComputerSign);
    ~GameBoard();

    //return true if player position is set correctly, and false if something went wrong
    bool setPlayerPos(int playerPos);
    //return true if computer position is set correctly, and false if something went wrong
    bool setComputerPos(int computerPos);
    //return the char in particular position
    char getGridChar(int pos);
    char getPlayerSign();
    char getComputerSign();
    void printBoard();

    friend class Score;

};

#endif // GAMEBOARD_H_INCLUDED
