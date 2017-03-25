/*
Amanda Pan
CECS 282
Program 2 - ADT (date object)
2/23/2016
*/
#include "upDate.h"

int upDate::count = 0;

upDate::upDate()
{
	year = 1959;
	month = 5;
	day = 11;

	dptr = new int[3];
	dptr[0] = month;
	dptr[1] = day;
	dptr[2] = year;
	count++;
}

upDate::upDate(int M, int D, int Y)
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

	dptr = new int[3];
	dptr[0] = month;
	dptr[1] = day;
	dptr[2] = year;
	count++;
}

void upDate::display()
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

int upDate::getMonth()
{
	return month;
}

int upDate::getDay()
{
	return day;
}

int upDate::getYear()
{
	return year;
}

void upDate::incrDate(int N)
{
	int start = GtoJ(dptr[2],dptr[0],dptr[1]);
	start += N;
	JtoG(start,dptr[2],dptr[0],dptr[1]);
}

void upDate::decrDate(int N)
{
	int start = GtoJ(dptr[2],dptr[0],dptr[1]);
	start -= N;
	JtoG(start,dptr[2],dptr[0],dptr[1]);
}

int upDate::daysBetween(upDate D)
{
	int startDate = GtoJ(D.year, D.month,D.day);
	int endDate = GtoJ(year,month,day);
	return startDate - endDate;
}

int upDate::dayOfYear()
{
	int startDate = GtoJ(year,1,1);
	int endDate = GtoJ(year,month,day);
	return endDate - startDate + 1;
}

string upDate::dayOfWeek()
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

int upDate::GtoJ(int YEAR, int MONTH, int DAY)
{
	int JD, I, J, K;
	I = YEAR;
	J = MONTH;
	K = DAY;
	
	JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
	return JD;
}

void upDate::JtoG(int JD, int &YEAR, int &MONTH, int &DAY)
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

void upDate::setRanDate()
{
	int fstDate = GtoJ(1992,1,1);
	int lstDate = GtoJ(1996,12,31);
	int range = lstDate - fstDate;
	int randomDate = rand()%range + fstDate;
	JtoG(randomDate,year,month,day);
}

string upDate::dateS()
{
	string MONTHstring;
	stringstream display;
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
	display << MONTHstring << " " << day << " " << year;
	string DISPLAYforReal = display.str();
	return DISPLAYforReal;
}

int upDate::getBirthday()
{
	int store =  GtoJ(year, month, day);
	return store;
}

string upDate::getMonthName()
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
	return MONTHstring;
}

void upDate::setDate(int mon, int dy, int yr)
{
	dptr[0] = mon;
	dptr[1] = dy;
	dptr[2] = yr;
}

upDate::~upDate()
{
	count--;
	delete [] dptr;
}

upDate upDate::operator+(int n)
{
	
	upDate temp = *this;
	temp.incrDate(n);
	return temp;
}

upDate operator+(int n, upDate date)
{
	upDate temp = date;
	temp.incrDate(n);
	return temp;
}

upDate upDate::operator-(int n)
{
	upDate temp=*this;
	temp.decrDate(n);
	return temp;
}

int upDate::operator-(upDate date)
{
	int DATE = GtoJ(dptr[2],dptr[0], dptr[1]);
	DATE -= date.julian();
	return DATE;
}

ostream& operator<<(ostream& out, const upDate display)
{
	out << display.dptr[0];
	out << '/';
	out << display.dptr[1];
	out << '/';
	out << display.dptr[2];
	return out;
}

upDate upDate::operator++()
{
	upDate temp(*this);
	temp.incrDate(1);
	int Date=julian()+1;
	JtoG(Date,dptr[2],dptr[0],dptr[1]);
	return temp;
}

upDate upDate::operator++(int n)
{
	upDate temp(*this);
	temp.incrDate(1);
	int Date=julian()+1;
	JtoG(Date,dptr[2],dptr[0],dptr[1]);
	return temp;
}

upDate upDate::operator--()
{
	upDate temp(*this);
	temp.decrDate(1);
	int Date=julian()-1;
	JtoG(Date,dptr[2],dptr[0],dptr[1]);
	return temp;
}

upDate upDate::operator--(int n)
{
	upDate temp(*this);
	temp.decrDate(1);
	int Date=julian()-1;
	JtoG(Date,dptr[2],dptr[0],dptr[1]);
	return temp;
}

bool upDate::operator<(upDate date)
{
	if(julian() < date.julian())
	{
		return true;
	}
	else
		return false;
}

bool upDate::operator>(upDate date)
{
	if(julian() > date.julian())
	{
		return true;
	}
	else
		return false;
}

bool upDate::operator==(upDate date)
{
	if(julian() == date.julian())
	{
		return true;
	}
	else
		return false;
}

upDate::upDate(upDate& date)
{
	dptr = new int[3];
	dptr[0] = date.dptr[0];;
	dptr[1] = date.dptr[1];
	dptr[2] = date.dptr[2];
	count++;
}

int upDate::julian()
{
	return GtoJ(dptr[2],dptr[0],dptr[1]);
}

int upDate::GetDateCount()
{
	return count;
}

void upDate::operator=(upDate date)
{
	this->dptr[0] = date.dptr[0];
	this->dptr[1] = date.dptr[1];
	this->dptr[2] = date.dptr[2];
}