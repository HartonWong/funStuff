#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
class GameBoard
{
    private:
    enum GameState
    {
        Player_WIN;
        Computer_WIN;
        TIE;
    }

    public:

    GameState getGameState();

};


#endif // SCORE_H_INCLUDED
