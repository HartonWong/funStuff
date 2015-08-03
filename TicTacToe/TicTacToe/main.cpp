//#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */
#include <ctime>		/* for time()*/
#include "GameBoard.h"
#include "Score.h"

/*
THINGS TO WORK ON:
1) player can choose start first or not, choose using X or O	DONE
2) resizable board, can choose 3x3, 4x4, 5x5...etc
3) AI, stupid computer now that won't block user's movement.
4) Refactoring
	a) Rename variables into more descriptive words
	b) Put some of the functions into header file?
	c) Put the forward function call into header file
	d) find ways to reduce the size of code
	e) reduce the use of global variables such as newGameBoard.getGridChar and namespace
	f) check user input against integer and string
*/

using namespace std;
void screenStay();      //for visual studio
bool gameWin(char sign,const GameBoard &board);
int randomNum(int min,int max);

int main()
{
	//variable initialization
	srand(time(0));
	int playerPos;
	int computerPos;
	char startFirst;
	char playerSign;
	char computerSign;
	int boardSize=9;


	cout << "So this is the game of Tic Tac Toe, let see how it works" << "\n";
	cout << "What kind of sign you would like to use?" << "\n";
	cin >> playerSign;
	cout << "What kind of sign you would like ME to use?" << "\n";
	cin >> computerSign;

	//GameBoard(int nSize,char chPlayerSign,char chComputerSign);
    GameBoard newGameBoard(boardSize+1,playerSign,computerSign);

	//let the player to choose if player go first or computer
	do {
		cout << " Do you want to start first or not? y=yes and n=no \n";
		cin >> startFirst;
	} while ((startFirst != 'n') & (startFirst != 'y') );

	//if computer go first, randomly set a pos for computer
	int trial = 0;
	if (startFirst == 'n')
	{
		computerPos = randomNum(1,boardSize);
		newGameBoard.setComputerPos(computerPos);   //place the computer sign with the computer position
        trial++;
		cout <<"Trial is now"<< trial<<"\n";
	}

	//while ((gameWin(playerSign,newGameBoard) == false) | (gameWin(computerSign,newGameBoard) == false) |(count<=9))

	while (trial<boardSize)
	{
		do{
			cout << " Where do you want to place?" << "\n";
			cin >> playerPos;
		} while (newGameBoard.setPlayerPos(playerPos)==false);

		trial++;

		cout <<"Trial is now"<< trial<<"\n";
        cout <<"gameWin now is of PlayerSign"<< gameWin(playerSign,newGameBoard)<<"\n";
        Score gameScore1;
        //if (gameScore1.getGameState(newGameBoard)==2){
                cout<<"the game state is now "<<gameScore1.getGameState(newGameBoard)<<"\n";
        //}
		if (gameWin(playerSign,newGameBoard) == true ||trial>=boardSize)
        {
           break;
        }

		cout << " It's my movement now " << "\n";
		do{
			computerPos = randomNum(1,boardSize); //to do random number from 1 to 9
		} while (newGameBoard.setComputerPos(computerPos)==false);
		trial++;

		cout <<"Trial is now"<< trial<<"\n";
        cout <<"gameWin now is of ComputerSign"<< gameWin(computerSign,newGameBoard)<<"\n";
        cout<<"the game state is now "<<gameScore1.getGameState(newGameBoard)<<"\n";
		if (gameWin(computerSign,newGameBoard) == true ||trial>=boardSize)
        {
            break;
        }
	}

	if (gameWin(playerSign,newGameBoard) == true)
		cout << " You Win!! :)" << "\n";
	if (gameWin(computerSign,newGameBoard) == true)
		cout << " I Win!! :)" << "\n";
	if (trial>=9)
		cout << " It is a DRAW :P" << "\n";

	//screenStay();
	return 0;
}

//game wining checking system
bool gameWin(char sign,const GameBoard &board)
{
    Score   gameScore;
    return gameScore.winChecking(sign,board);
}

//generate random int number between max and min.
int randomNum(int min,int max)
{
    return (rand() % (max-1)) + min;
}

/*
void screenStay()
{
	using namespace std;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}*/

