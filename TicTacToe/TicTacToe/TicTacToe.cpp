//#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */
#include <ctime>		/* for time()*/
#include "GameBoard.h"
#include "Score.h"


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
		} while (newGameBoard.setPlayerPos(playerPos)==false);

		count++;
		if (gameWin(playerSign) == true)
			break;

		cout << " It's my movement now " << "\n";
		int computerPos;
		do{
			computerPos = (rand() % 8) + 1; //to do random number from 1 to 9
		} while (newGameBoard.setComputerPos(computerPos)==false);
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

