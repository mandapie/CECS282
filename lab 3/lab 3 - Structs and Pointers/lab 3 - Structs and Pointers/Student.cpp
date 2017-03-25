#include "Student.h"

Student::Student()
{
	char name[20] = {NULL};
	int ID = 0;
	char grade = 'F';
	myDate birthday = myDate();
	string homeTown = " ";
}

Student::Student(char n, int i, char g, myDate b, string h)
{
	char name[20] = {n};
	int ID = i;
	char grade = g;
	myDate birthday = b;
	string homeTown = h;
}