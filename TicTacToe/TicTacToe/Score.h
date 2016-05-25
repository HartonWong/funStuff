#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <string>
class Score
{
    private:
    bool winChecking(std::string sign,const GameBoard &cGameBoard);

	bool checkHori(const GameBoard &cGameBoard, std::string sign);
	bool checkVert(const GameBoard &cGameBoard, std::string sign);
	bool checkBackSlash(const GameBoard &cGameBoard, std::string sign);
	bool checkForwardSlash(const GameBoard &cGameBoard, std::string sign);
	bool isConsecutive(const bool &conditionMet, bool &flagConsecutive, int &hitCount, const int &links, const int &defaultHitCount);

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
