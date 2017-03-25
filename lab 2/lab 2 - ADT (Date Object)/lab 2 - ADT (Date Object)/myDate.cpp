/*
Amanda Pan
CECS 282
Program 2 - ADT (date object)
2/23/2016
*/
#include "myDate.h"

myDate::myDate()
{
	year = 1959;
	month = 5;
	day = 11;
}

myDate::myDate(int M, int D, int Y)
{
	int m = M;
	int d = D;
	int y = Y;

	int datevalid = GtoJ(y,m,d);
	JtoG(datevalid,y,m,d);
	if(y == Y && m == M && d == D)
	{
		year = Y;
		month = M;
		day = D;
	}
	else
	{
		year = 1959;
		month = 5;
		day = 11;
	}
}

void myDate::display()
{
	string MONTHstring;
	switch(month)
	{
	case 1:
		MONTHstring = "January";
		break;
	case 2:
		MONTHstring = "Febuary";
		break;
	case 3:
		MONTHstring = "March";
		break;
	case 4:
		MONTHstring = "April";
		break;
	case 5:
		MONTHstring = "May";
		break;
	case 6:
		MONTHstring = "June";
		break;
	case 7:
		MONTHstring = "July";
		break;
	case 8:
		MONTHstring = "August";
		break;
	case 9:
		MONTHstring = "September";
		break;
	case 10:
		MONTHstring = "October";
		break;
	case 11:
		MONTHstring = "November";
		break;
	case 12:
		MONTHstring = "December";
		break;
	}
	cout << MONTHstring << " " << day << " " << year;
}

int myDate::getMonth()
{
	return month;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return year;
}

void myDate::incrDate(int N)
{
	int start = GtoJ(year,month,day);
	start += N;
	JtoG(start,year,month,day);
}

void myDate::decrDate(int N)
{
	int start = GtoJ(year,month,day);
	start -= N;
	JtoG(start,year,month,day);
}

int myDate::daysBetween(myDate D)
{
	int startDate = GtoJ(D.year, D.month,D.day);
	int endDate = GtoJ(year,month,day);
	return startDate - endDate;
}

int myDate::dayOfYear()
{
	int startDate = GtoJ(year,1,1);
	int endDate = GtoJ(year,month,day);
	return endDate - startDate + 1;
}

string myDate::dayOfWeek()
{
	int DATE = GtoJ(year,month,day);
	int days = DATE%7;
	
	if(days == 0)
		return  "Monday";
	else if(days ==  1)
		return  "Tuesday";
	else if(days ==  2)
		return  "Wednesday";
	else if(days ==  3)
		return "Thursday";
	else if(days ==  4)
		return "Friday";
	else if(days == 5)
		return  "Saturday";
	else
		return "Sunday";
}

int myDate::GtoJ(int YEAR, int MONTH, int DAY)
{
	int JD, I, J, K;
	I = YEAR;
	J = MONTH;
	K = DAY;
	
	JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
	return JD;
}

void myDate::JtoG(int JD, int &YEAR, int &MONTH, int &DAY)
{
	int L, N, I, K, J;

	L= JD+68569;
    N= 4*L/146097;
	L= L-(146097*N+3)/4;
	I= 4000*(L+1)/1461001;
    L= L-1461*I/4+31;
    J= 80*L/2447;
    K= L-2447*J/80;
    L= J/11;
    J= J+2-12*L;
    I= 100*(N-49)+I+L;

	YEAR = I;
	MONTH = J;
	DAY = K;
}
