#include <iostream>
using namespace std;
#include "Card.h"
#include "Deck.h"

Deck::Deck()
{
	cardLeft = 52;
	char suit;
	for (int i = 0; i < 4; i++)
	{
		switch(i) //case of suits
		{
		case 0:
			suit = 'S';
			break;
		case 1:
			suit = 'C';
			break;
		case 2:
			suit = 'D';
			break;
		case 3:
			suit = 'H';
			break;
		}	
		deck[i*13] = Card('A', suit); // Ace of all suits
		for(int j = 1; j < 9; j++)
		{
			deck[i*13 + j] = Card((j+1)+'0', suit); //ranks from 2-9 in all suits
		}
		deck[i*13 + 9] = Card('T', suit);
		deck[i*13 + 10] = Card('J', suit);
		deck[i*13 + 11] = Card('Q', suit);
		deck[i*13 + 12] = Card('K', suit);
	}
}
void Deck::displayCardAt(int position)
{
	deck[position].displayCard();
}
Card Deck::deal()
{
	return deck[52 - (cardLeft--)];
}
int Deck::cardsLeft()
{
	return cardLeft;
}
void Deck::shuffle()
{
	for(int i=0; i < 1000000; i++)
	{
		int x = rand()%cardLeft;
		int y = rand()%cardLeft;
		Card c1 = deck[x];
		deck[x] = deck[y];
		deck[y] = c1;
	}
}