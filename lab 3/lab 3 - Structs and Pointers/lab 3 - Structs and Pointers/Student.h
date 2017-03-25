#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "myDate.h"

struct Student
{
	char name[20];
	int ID;
	char grade;
	myDate birthday;
	string homeTown;
};
#endif