#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */
#include <ctime>		/* for time()*/
#include "GameBoard.h"
#include "Score.h"

/*
THINGS TO WORK ON:
1) player can choose start first or not, choose using X or O	DONE
2) resizable board, can choose 3x3, 4x4, 5x5...etc				DONE
3) AI, stupid computer now that won't block user's movement.
4) Refactoring
	a) Rename variables into more descriptive words
	b) Put some of the functions into header file?
	c) Put the forward function call into header file
	d) find ways to reduce the size of code
	e) reduce the use of global variables such as gameBoard.getGridChar and namespace
5) check user input against integer and string
6) Score checking function is not working with number 6
*/

using namespace std;

//forward function declaration
int randomNum(int min,int max);
void playerMovement(GameBoard &board,int &trial);
void computerMovement(GameBoard &board,int &trial,const int &boardSize);
void screenStay();

int main()
{
	//variable initialization
	srand(time(0));
    int numOfRow;
	int numOfCol;
	int links=3;

    string playerSign;
	string computerSign;

	char startFirst;

	int playerPos;
	int computerPos;

    //---------------User interface-------------------
    cout<<"How many ROWS you want the board to be ?\n";
    cin>>numOfRow;
    cout<<"How many COLOUMNS you want the board to be ?\n";
    cin>>numOfCol;
	cout << "How many hit in order to call it a win, traditionally TicTacToe takes 3 hit? \n";
	cin >> links;

    int boardSize=numOfRow*numOfCol;
    /*
    cout<<"How many links to win? \n";
    cin>>links;
    */
	cout << "So this is the game of Tic Tac Toe, let see how it works" << "\n";
	cout << "What kind of sign you would like to use?" << "\n";
	cin >> playerSign;
	cout << "What kind of sign you would like ME to use?" << "\n";
	cin >> computerSign;

    GameBoard gameBoard(numOfRow,numOfCol,playerSign,computerSign,links);
	//-----------------let the player to choose if player go first or computer-----------------


	do {
		cout << " Do you want to start first or not? y=yes and n=no \n";
		cin >> startFirst;
	} while ((startFirst != 'n') & (startFirst != 'y') );

	//if computer go first, randomly set a pos for computer
	int trial = 0;
	if (startFirst == 'n')
	{
		computerMovement(gameBoard,trial,boardSize);
	}

	//-----------------------------------------------------------------------------------------
    Score gameScore;
	while (1)
	{
	    //----------------------player's movement-----------------------------
        playerMovement(gameBoard,trial);

		if (gameScore.getGameState(gameBoard, playerSign) == Score::PLAYER_WIN | trial >= boardSize)
        {
           break;
        }

        //----------------------computer's movement-----------------------------
        computerMovement(gameBoard,trial,boardSize);

		if (gameScore.getGameState(gameBoard,computerSign) == Score::COMPUTER_WIN | trial>=boardSize)
        {
            break;
        }
	}

	if (trial>=boardSize)
		cout << " It is a DRAW :P" << "\n";
	screenStay();

	return 0;
}

void playerMovement(GameBoard &board,int &trial)
{
    int playerPos;
    do{
        cout << " Where do you want to place?" << "\n";
        cin >> playerPos;
    } while (board.setPlayerPos(playerPos)==false);     //while player's position is invalid
    trial++;
}

void computerMovement(GameBoard &board,int &trial,const int &boardSize)
{
    int computerPos;
    cout << " It's my movement now " << "\n";
    do{
        computerPos = randomNum(1,boardSize); //to do random number from 1 to boardsize
    } while (board.setComputerPos(computerPos)==false);
    trial++;
}

//generate random int number between max and min.
int randomNum(int min,int max)
{
	return (rand() % (max-min+1) + min);
}


void screenStay()
{
using namespace std;
cin.clear();
cin.ignore(255, '\n');
cin.get();
}