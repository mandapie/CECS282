/*
Amanda Pan
CECS 282
Program 3 - Structs and Pointers
3/8/2016
*/
#include <iostream> //for cin,cout
#include <string>
#include <cstring> //for character array
#include <cstdlib> //for rand();
#include <sstream> //toString
#include <algorithm> //for sorting
#include <iomanip> //for setw
using namespace std; //dont have to use std::
#include "myDate.h"

struct Student
{
	char name[20];
	int ID;
	char grade;
	myDate birthday;
	string homeTown;
};

Student obj[10];

void generation()
{
	strcpy_s(obj[0].name,"Tom Thumb");
	strcpy_s(obj[1].name,"Fred Flinstone");
	strcpy_s(obj[2].name,"Sponge Bob");
	strcpy_s(obj[3].name,"Tidus Lee");
	strcpy_s(obj[4].name,"Yuna Lesca");
	strcpy_s(obj[5].name,"Riku Albhed");
	strcpy_s(obj[6].name,"Auron Stone");
	strcpy_s(obj[7].name,"Jack Young");
	strcpy_s(obj[8].name,"Shyvana Richner");
	strcpy_s(obj[9].name,"Amanda Pan");
	
	obj[0].homeTown = "Small Ville";
	obj[1].homeTown = "Bedrock";
	obj[2].homeTown = "Bikini Bottom";
	obj[3].homeTown = "Spira";
	obj[4].homeTown = "California";
	obj[5].homeTown = "Sandakan";
	obj[6].homeTown = "Macalania";
	obj[7].homeTown = "Paris";
	obj[8].homeTown = "Wonderland";
	obj[9].homeTown = "Enchanted Forest";

	int num1, num2;
	char randomGrade;
	srand((unsigned)time(0));
	for(int i=0; i < 10; i++)
	{
		num1 = rand()%9999;
		if(num1 < 1000)
			num1 += 1000;
		for(int j=0; j < 10; j++)
		{
			while( num1 == obj[j].ID)
			{
				num1 = rand()%9999;
				if(num1 < 1000)
					num1 += 1000;
				j = 0;
			}
		}
		obj[i].ID = num1; //generate random ID

		num2 = rand()%100;
		if (num2 >= 90 && num2 < 100)
			randomGrade = 'A';
		else if (num2 >= 80 && num2 < 90)
			randomGrade = 'B';
		else if (num2 >= 70 && num2 < 80)
			randomGrade = 'C';
		else if (num2 >= 60 && num2 < 70)
			randomGrade = 'D';
		else
			randomGrade = 'F';
		obj[i].grade = randomGrade; //generate random grade

		obj[i].birthday.setRanDate(); //generate random birthdate
	}
}

bool sortID(const Student *first,const Student *last)
{
	return first->ID < last->ID;
}
bool sortAge(Student *first, Student *last)
{
	return first->birthday.getBirthday() < last->birthday.getBirthday();
}
bool sortName(Student *first, Student *last)
{
	return (strcmp(first->name,last->name) < 0);
}
bool sortGrade(Student *first, Student *last)
{
	return first->grade < last->grade;
}
bool sortHomeTown(Student *first, Student *last)
{
	return first->homeTown < last->homeTown;
}

int main()
{
	Student *nptr[10], *idptr[10], *gptr[10], *aptr[10], *hptr[10];
	
	generation();

	for (int i = 0; i < 10; i++)
	{
		idptr[i] = &obj[i];
		aptr[i] = &obj[i];
		nptr[i] = &obj[i];
		gptr[i] = &obj[i];
		hptr[i] = &obj[i];
	}

	bool menu = true;
	int decision;
	cout << "This program will sort Student data\n\n";
	do
	{
		cout << "1) Display original list\n" << "2) Display list sorted by Student ID\n" << "3) Display list sorted by Student Age\n" << "4) Display list sorted by Name\n" << "5) Display list sorted by Grade\n" << "6) Display list sorted by Home Town\n" << "7) Exit\n\n";
		cin >> decision;
		cout << "\n";
		
		switch (decision)
		{
			case 1:
				cout << "Original List:\n";
				cout << std::left << std::setw(20) << "Student Name" << std::setw(13) << "Student ID" << std::setw(8) << "Grade"  << std::setw(20) << "Birth Date" << std::setw(20) << "Home Town" << "\n\n";
				for(int i=0; i < 10; i++)
					cout << std::left << std::setw(20) << obj[i].name << std::setw(13) << obj[i].ID << std::setw(8) << obj[i].grade << std::setw(20) << obj[i].birthday.dateS() << std::setw(20) << obj[i].homeTown << "\n";
				cout << endl;
				break;
			case 2:
				sort(idptr, idptr + 10, sortID);
				cout << "List sorted by ID:\n";
				cout << std::left << std::setw(20) << "Student Name" << std::setw(13) << "Student ID" << std::setw(8) << "Grade"  << std::setw(20) << "Birth Date" << std::setw(20) << "Home Town" << "\n\n";	
				for(int i=0; i < 10; i++)
					cout << std::left << std::setw(20) << (*idptr[i]).name << std::setw(13) << (*idptr[i]).ID << std::setw(8) << (*idptr[i]).grade << std::setw(20) << (*idptr[i]).birthday.dateS() << std::setw(20) << (*idptr[i]).homeTown << "\n";
				cout << endl;
				break;
			case 3:
				sort(aptr, aptr + 10, sortAge);
				cout << "List sorted by age:\n";
				cout << std::left << std::setw(20) << "Student Name" << std::setw(13) << "Student ID" << std::setw(8) << "Grade"  << std::setw(20) << "Birth Date" << std::setw(20) << "Home Town" << "\n\n";
				for(int i=0; i < 10; i++)
					cout << std::left << std::setw(20) << (*aptr[i]).name << std::setw(13) << (*aptr[i]).ID << std::setw(8) << (*aptr[i]).grade << std::setw(20) << (*aptr[i]).birthday.dateS() << std::setw(20) << (*aptr[i]).homeTown << "\n";
				cout << endl;
				break;
			case 4:
				sort(nptr, nptr + 10, sortName);
				cout << "List sorted by name:\n";
				cout << std::left << std::setw(20) << "Student Name" << std::setw(13) << "Student ID" << std::setw(8) << "Grade"  << std::setw(20) << "Birth Date" << std::setw(20) << "Home Town" << "\n\n";
				for(int i=0; i < 10; i++)
					cout << std::left << std::setw(20) << (*nptr[i]).name << std::setw(13) << (*nptr[i]).ID << std::setw(8) << (*nptr[i]).grade << std::setw(20) << (*nptr[i]).birthday.dateS() << std::setw(20) << (*nptr[i]).homeTown << "\n";
				cout << endl;
				break;
			case 5:
				sort(gptr, gptr + 10, sortGrade);
				cout << "List sorted by grade:\n";
				cout << std::left << std::setw(20) << "Student Name" << std::setw(13) << "Student ID" << std::setw(8) << "Grade"  << std::setw(20) << "Birth Date" << std::setw(20) << "Home Town" << "\n\n";
				for(int i=0; i < 10; i++)
					cout << std::left << std::setw(20) << (*gptr[i]).name << std::setw(13) << (*gptr[i]).ID << std::setw(8) << (*gptr[i]).grade << std::setw(20) << (*gptr[i]).birthday.dateS() << std::setw(20) << (*gptr[i]).homeTown << "\n";
				cout << endl;
				break;
			case 6:
				sort(hptr, hptr + 10, sortHomeTown);
				cout << "List sorted by home town:\n";
				cout << std::left << std::setw(20) << "Student Name" << std::setw(13) << "Student ID" << std::setw(8) << "Grade"  << std::setw(20) << "Birth Date" << std::setw(20) << "Home Town" << "\n\n";
				for(int i=0; i < 10; i++)
					cout << std::left << std::setw(20) << (*hptr[i]).name << std::setw(13) << (*hptr[i]).ID << std::setw(8) << (*hptr[i]).grade << std::setw(20) << (*hptr[i]).birthday.dateS() << std::setw(20) << (*hptr[i]).homeTown << "\n";
				cout << endl;
				break;
			case 7:
				menu = false;
				break;
			default:
				cout << "Only enter numbers from 1 - 7\n\n";
				break;
		}
	}while(menu == true);

	system("PAUSE");
	return 0;
}