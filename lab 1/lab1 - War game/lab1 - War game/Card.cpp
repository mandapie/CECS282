#include <iostream>
#include <string>
using namespace std;
#include "Card.h"

Card::Card()
{
	suit = NULL;
	rank = NULL;
}
Card::Card(char r, char s)
{
	setCard(r, s);
}
int Card::getValue()
{
	return value;
}
void Card::setCard(char rk, char st)
{
	suit = st;
	rank = rk;
	switch(rank)
	{
		case 'A':
			value = 1;
			break;
		case 'T':
			value = 10;
			break;
		case 'J':
			value = 10;
			break;
		case 'Q':
			value = 10;
			break;
		case 'K':
			value = 10;
			break;
		default:
			value = rank - '0';
	}
}
void Card::displayCard()
{
	char symbol;
	switch(suit)
	{
	case 'S':
		symbol = (char)6;
		break;
	case 'H':
		symbol = (char)3;
		break;
	case 'C':
		symbol = (char)5;
		break;
	case 'D':
		symbol = (char)4;
		break;
	}
	string row = "[-------]";
	string blank = "[       ]";
	string blank2 = "[   ";
	string blank2aft = "   ]";
	string blank3 = "[  ";
	string blank3aft = "  ]";
	string blank4aft = "      ]";
	string blank4 = "[      ";
	switch(rank)
	{
	case 'A':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank << "\n" << blank << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank << "\n" << blank << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '2':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank << "\n" << blank << "\n" << blank << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '3':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '4':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank << "\n" << blank << "\n" << blank << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '5':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '6':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '7':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '8':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case '9':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank2 << suit << blank2aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case 'T':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case 'J':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << suit << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case 'Q':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << suit << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << suit << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	case 'K':
		cout << row << "\n"
			<< "[" << rank << blank4aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank3 << suit << suit << suit << blank3aft << "\n"
			<< blank3 << suit << suit << suit << blank3aft << "\n"
			<< blank3 << suit << suit << suit << blank3aft << "\n"
			<< blank3 << suit << " " << suit << blank3aft << "\n"
			<< blank4 << rank <<"]\n" << row << "\n";
		break;
	}

	//cout << suit << " " << rank << "\n"; -> for testing
}