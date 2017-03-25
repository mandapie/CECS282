#ifndef CARD_H
#define CARD_H

class Card
{
	char suit, rank;
	int value;
public:
	Card();
	Card(char r, char s);
	void setCard(char rank, char suit);
	int getValue();
	void displayCard();
};
#endif