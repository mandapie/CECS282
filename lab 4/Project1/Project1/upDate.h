#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class upDate
{
private:
	int *dptr;
	static int count;
	int year, month, day;
	int GtoJ(int YEAR, int MONTH, int DAY);
	void JtoG(int GD, int &YEAR, int &MONTH, int &DAY);
public:
	upDate();
	upDate(int M, int D, int Y);
	void display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(upDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayOfWeek();
	void setRanDate();
	string dateS();
	int getBirthday();
	
	~upDate();
	upDate(upDate&);
	void setDate(int mon, int dy, int yr);
	string getMonthName();
	upDate operator+(int n);
	friend upDate operator+(int n, upDate date);
	upDate operator-(int n);
	int operator-(upDate date);
	friend ostream& operator<<(ostream& out, const upDate display);
	void operator=(upDate date);
	upDate operator++();
	upDate operator++(int n);
	upDate operator--();
	upDate operator--(int n);
	bool operator<(upDate date);
	bool operator>(upDate date);
	bool operator==(upDate date);
	static int GetDateCount();
	int julian();
};
#endif