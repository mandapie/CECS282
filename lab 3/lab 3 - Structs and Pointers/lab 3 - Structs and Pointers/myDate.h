#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class myDate
{
private:
	int year, month, day;
	int GtoJ(int YEAR, int MONTH, int DAY);
	void JtoG(int GD, int &YEAR, int &MONTH, int &DAY);
public:
	myDate();
	myDate(int M, int D, int Y);
	void display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayOfWeek();
	void setRanDate();
	string dateS();
	int getBirthday();
};
#endif