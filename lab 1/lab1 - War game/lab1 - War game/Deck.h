#ifndef DECK_H
#define DECK_H

class Deck
{
	Card deck[52];
	int cardLeft;
public:
	Deck();
	void displayCardAt(int position);
	Card deal();
	int cardsLeft();
	void shuffle();

};
#endif