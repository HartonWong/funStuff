#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */

using namespace std;
void screenStay();
void gameBoard(int Input, bool playerMove);
void printGameBoard(char crossPos[9]);

static char crossPos[10];

int main()
{

	cout << "So this is the game of Tic Tac Toe, let see how it works" << "\n";

	char start;
	do
	{cout << " let draw the game board first,shall we start? y for yes, n for no" << "\n";
	cin >> start;
	} while (start != 'y');

	gameBoard(0, true);

	int playerPos;

	while (1)
	{
		do{
			cout << " You can start first, where do you want to place?" << "\n";
			cin >> playerPos;
		} while (!(playerPos > 1 & playerPos < 9));

		gameBoard(playerPos,true);
		cout << " It's my movement now " << "\n";
		gameBoard((rand() % 6) + 1, false);
	}

	screenStay();
	return 0;
}

void gameBoard(int Input,bool playerMove)
{
	if (Input == 0)
	{
		char count = 49; //ASCII number 1 start at char 49
		for (int iii = 1; iii <10; iii++)
		{
			crossPos[iii] = count;
			count++;
		}
	}
	else
	{
		if (playerMove)
		{
			crossPos[Input] = 'X';
		}
		else
		{
			crossPos[Input] = 'O';
		}
	}

	printGameBoard(crossPos);

}

void printGameBoard(char crossPos[])
{
	using namespace std;
	cout << " " << crossPos[1]<<" | "<<crossPos[2]<<" | "<<crossPos[3]<<" " << "\n";
	cout << "---+---+---" << "\n";
	cout << " " << crossPos[4] << " | " << crossPos[5] << " | " << crossPos[6] << " " << "\n";
	cout << "---+---+---" << "\n";
	cout << " " << crossPos[7] << " | " << crossPos[8] << " | " << crossPos[9] << " " << "\n";;

}
void screenStay()
{
	using namespace std;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}

