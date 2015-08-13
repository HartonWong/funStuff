#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <string>
class Score
{
    private:
    bool winChecking(std::string sign,const GameBoard &cGameBoard);
	bool check(const GameBoard &cGameBoard, std::string sign, std::string mode, bool& flagConsective);
	bool arrayCheck(const GameBoard &cGameBoard, const std::string mode, const int iii, const int jjj, const std::string sign);
	//bool secondCheck(const GameBoard &cGameBoard, std::string mode, int &count);


    public:
    enum GameState
    {
        PLAYER_WIN,
        COMPUTER_WIN,
        PLAYING
    };
    //return the state of the game once the caller passed the gameBoard to score
	GameState getGameState(const GameBoard &cGameBoard, const std::string sign);


};


#endif // SCORE_H_INCLUDED
