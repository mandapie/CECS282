/*
Amanda Pan
CECS 282
Program 1 - WAR card game
2/9/2016
*/
#include <iostream>
#include <cstdlib>
using namespace std;
#include "Card.h"
#include "Deck.h"
#include "Time.h"

int main()
{
	int P1score = 0;
	int P2score = 0;
	bool redo = true;
	Deck beta;
	char decision;
	Card pCard;
	Card dCard;

	cout << "This program is a card game called WAR\n";
	do
	{
		cout << "(G)et a new card of Deck\n(D)isplay all remaining cards in the deck\n(P)lay WAR\n(S)huffle Cards\n(E)xit\n";
		cin >> decision;
		cin.ignore();

		switch(decision)
		{
			case 'G':
			case 'g':
				beta = Deck();
				cout << "We got a new deck\n\n";
				break;
			case 'P':
			case 'p':
				while(redo == true)
				{
					if(beta.cardsLeft() > 0)
					{
						cout << "There are " << beta.cardsLeft() << " cards\n";
						cout << "your card: \n";
						pCard = beta.deal();
						pCard.displayCard();
						cout << "my card: \n";
						dCard = beta.deal();
						dCard.displayCard();
						if(pCard.getValue() > dCard.getValue())
						{
							cout << "you won this round\n";
							P1score++;
						}
						else if(pCard.getValue() == dCard.getValue())
							cout << "It's a tie\n";
						else
						{
							cout << "I won this round\n";
							P2score++;
						}
						cout << "Wanna play again? (Y/N)\n";
						cin >> decision;
						cin.ignore();
						switch(decision)
						{
							case 'Y':
							case 'y':
								break;
							case 'N':
							case'n':
								cout << "You won " << P1score << " round\n";
								cout << "I won " << P2score << " round\n";
								redo = false;
								break;
						}
					}
					else
					{
						cout << "There are no more cards\n";
						cout << "You won " << P1score << " round\n";
						cout << "I won " << P2score << " round\n\n";
						redo = false;
					}
				}
				break;
			case 'S':
			case 's':
				srand((unsigned)time(0));
				beta.shuffle();
				cout << "Cards shuffled\n\n";
				break;
			case 'D':
			case 'd':
				for(int i = (52-beta.cardsLeft()); i < beta.cardsLeft(); i++)
				{
					beta.displayCardAt(i);
					cout << "\n";
				}
				break;
			case 'E':
			case 'e':
				redo = false;
				break;
			default:
				cout << "Only enter 'G', 'D', 'P', 'S' or 'E'.\n\n";
				break;
		};
	}while(redo == true);

	system("PAUSE");
	return 0;
}