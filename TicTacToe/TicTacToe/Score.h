#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
class GameBoard
{
    private:
    enum GameState
    {
        PLAYER_WIN;
        COMPUTER_WIN;
        WIN;
        TIE;
        PLAYING;
    }
    GameState winChecking(char sign);

    public:

    GameState getGameState(GameBoard &cGameBoard);

};


#endif // SCORE_H_INCLUDED
