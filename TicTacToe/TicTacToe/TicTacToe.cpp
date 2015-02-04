//#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */
#include <ctime>		/* for time()*/
#include "GameBoard.h

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
	e) reduce the use of global variables such as gridPos and namespace
*/

using namespace std;
void screenStay();
bool gameWin(char playerSign);


int main()
{
	//variabel initization
	srand(time(0));
	int playerPos;
	int computerPos;
	char startFirst;
	char playerSign;
	char computerSign;


	cout << "So this is the game of Tic Tac Toe, let see how it works" << "\n";
	cout << "What kind of sign you would like to use?" << "\n";
	cin >> playerSign;
	cout << "What kind of sign you would like ME to use?" << "\n";
	cin >> computerSign;
    GameBoard newGameBoard(10,playerSign,computerSign);

{
	//let the player to choose if player go first or computer
	do {
		cout << " Do you want to start first or not? y=yes and n=no \n";
		cin >> startFirst;
	} while (startFirst != 'n' & startFirst != 'y' );

	//if computer go first, randomly set a pos for computer
	if (startFirst == 'n')
	{
		computerPos = (rand() % 8) + 1;
		newGameBoard.setComputerPos(computerPos);
	}

	int count = 0;
	while (gameWin(playerSign) == false | gameWin(computerSign) == false |count<=9)
	{
		do{
			cout << " Where do you want to place?" << "\n";
			cin >> playerPos;
			if (gridPos[playerPos] == playerSign)
				cout << "You cannot replace where you have placed \n";
			if (gridPos[playerPos] == computerSign)
				cout << "You cannot replace where I have placed \n";
		} while ((!(playerPos >= 1 & playerPos <= 9)) | gridPos[playerPos] == playerSign | gridPos[playerPos] == computerSign);

		newGameBoard.setPlayerPos(playerPos);
		count++;
		if (gameWin(playerSign) == true)
			break;

		cout << " It's my movement now " << "\n";
		int computerPos;
		do{
			computerPos = (rand() % 8) + 1; //to do random number from 1 to 9
		} while (gridPos[computerPos] == playerSign | gridPos[computerPos] == computerSign);

		gameBoard(computerPos, false);
		count++;
		if (gameWin(computerSign) == true)
			break;
		if (count > 9)
			break;
	}
	if (gameWin(playerSign) == true)
		cout << " You Win!! :)" << "\n";
	if (gameWin(computerSign) == true)
		cout << " I Win!! :)" << "\n";
	if (count>9)
		cout << " It is a DRAW :P" << "\n";

	screenStay();
	return 0;
}

//game wining checking system
bool gameWin(char playerSign)
{
	bool playerWin = false;
	if (gridPos[1] == playerSign & gridPos[2] == playerSign & gridPos[3] == playerSign)
		return playerWin = true;
	if (gridPos[1] == playerSign &gridPos[4] == playerSign &gridPos[7] == playerSign)
		return playerWin = true;
	if (gridPos[4] == playerSign &gridPos[5] == playerSign &gridPos[6] == playerSign)
		return playerWin = true;
	if (gridPos[1] == playerSign &gridPos[5] == playerSign &gridPos[9] == playerSign)
		return playerWin = true;
	if (gridPos[2] == playerSign &gridPos[5] == playerSign &gridPos[8] == playerSign)
		return playerWin = true;
	if (gridPos[3] == playerSign &gridPos[5] == playerSign &gridPos[7] == playerSign)
		return playerWin = true;
	if (gridPos[7] == playerSign &gridPos[8] == playerSign &gridPos[9] == playerSign)
		return playerWin = true;
	if (gridPos[3] == playerSign &gridPos[6] == playerSign &gridPos[9] == playerSign)
		return playerWin = true;
}

void screenStay()
{
	using namespace std;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}

