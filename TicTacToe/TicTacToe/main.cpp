//#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */
#include <ctime>		/* for time()*/
#include "GameBoard.h"
#include "Score.h"


using namespace std;
void screenStay();
bool gameWin(char playerSign,const GameBoard &board);

int main()
{

	//variable initialization
	srand(time(0));
	int playerPos;
	int computerPos;
	char startFirst;
	char playerSign;
	char computerSign;

    //initialize various class
    GameBoard newGameBoard(9,playerSign,computerSign);  //10 is the size of the board
    Score   gameScore;

	cout << "Tic Tac Toe" << "\n\n";
    cout<<"What kind of sign you would like to use? Let see a list of sign you can use\n";
    int jjj=0;
    for(char iii=20;iii<45;iii++)
    {
        cout<<iii<<"   ";
        jjj++;
        if(jjj==5)
        {
            cout<<"\n";
            jjj=0;
        }
    }
	do{cout << "What kind of sign you would like to use? \n You cannot use 1~9 because that is used to identify board"  << "\n";
	cin >> playerSign;
	}while ((playerSign<=static_cast<char>(9))&(playerSign>=static_cast<char>(1)));

	do{cout << "What kind of sign you would like ME to use?\n You cannot use 1~9 because that is used to identify board" << "\n";
	cin >> computerSign;
    }while ((playerSign<=9)&(playerSign>=1));

	//let the player to choose if player go first or computer
	do {
		cout << " Do you want to start first or not? y=yes and n=no \n";
		cin >> startFirst;
	} while ((startFirst != 'n') & (startFirst != 'y') );
    newGameBoard.printBoard();
	//if computer go first, randomly set a pos for computer
	int nCount = 0;
	if (startFirst == 'n')
	{
		computerPos = (rand() % 8) + 1;
		newGameBoard.setComputerPos(computerPos);
        nCount++;
		cout <<"nCount is now"<< nCount<<"\n";
	}

	while ((gameScore.getGameState(newGameBoard)==Score::PLAYING)|nCount<9)
	{
		do{
			cout << " Where do you want to place?" << "\n";
			cin >> playerPos;
		} while (newGameBoard.setPlayerPos(playerPos)==false);

		if (gameScore.getGameState(newGameBoard)==Score::PLAYER_WIN){
            cout << " YOU Win!! :)" << "\n";
            break;
        }
		cout << " It's my movement now " << "\n";

		do{
			computerPos = (rand() % 8) + 1; //to do random number from 1 to 9
		} while (newGameBoard.setComputerPos(computerPos)==false);

        nCount++;

		if (gameScore.getGameState(newGameBoard)==Score::COMPUTER_WIN)
        {
            cout << " I Win!! :)" << "\n";
           break;
        }
		if (nCount > 9)
        {
           cout << "It is a draw!";
           break;
        }
    }
	//screenStay();
	return 0;
}


/*
void screenStay()
{
	using namespace std;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}*/

