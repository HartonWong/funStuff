#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <string>
class Score
{
    private:
    bool winChecking(std::string sign,const GameBoard &cGameBoard);
    bool checkHorizontal(const GameBoard &cGameBoard,std::string sign);
    public:
    enum GameState
    {
        PLAYER_WIN,
        COMPUTER_WIN,
        PLAYING
    };
    //return the state of the game once the caller passed the gameBoard to score
    GameState getGameState(const GameBoard &cGameBoard);


};


#endif // SCORE_H_INCLUDED
