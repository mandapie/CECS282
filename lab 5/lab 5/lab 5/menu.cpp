/*
Amanda Pan
CECS 282
Lab 5 - Standard Template Library (STL)
4/12/2016
*/

#include <iostream> //for cout
#include <vector> //for vector
#include <algorithm> //for sort
#include <cstdlib> //for rand()
#include <iomanip> //for setw

using namespace std;

int main()
{
	vector <int> vint(10000);
	vector <int> vsize(100);
	int sum = 0;
	int mode = 0;
	double average;

	for(int i = 0; i < 100; i++)
	{
		vsize[i] = 0;
	}
	
	for(int i = 0; i < 10000; i++)
	{
		vint[i] = rand()%100 + 1;
		vsize[vint[i]-1] = vsize[vint[i]-1] + 1;
	}
	
	cout <<  "First 500 numbers in the unsorted array:\n";
	for(int i = 0; i < 500; i++)
		cout << setw(5) << vint[i];
	cout << endl;

	cout <<  "First 500 numbers in the sorted array:\n";
	sort(vint.begin(),vint.end());
	for(int i = 0; i < 500; i++)
		cout << setw(5) << vint[i];
	cout << endl;

	for(int i = 0; i < 10000; i++)
		sum = sum + vint[i];
	cout << "Sum: " << sum << "\n";

	average = (double)sum/10000;
	cout << "Average: " << average << "\n";

	for (int i = 0; i < 100; i++)
	{
		if (vsize[i] > vsize[mode])
			mode = i;
	}
	cout << "Mode: " << (mode+1) << "\n";

	cout << "Frequency and Histogram of all numbers:\n";
	for (int i = 0; i < 100; i++)
	{
		cout << setw(3) << (i + 1) << ": " << setw(3) << vsize[i];
		for (int j = 0; j < (vsize[i]+1) / 2; j++)
			cout << ".";
		cout << "\n";
	}

	system("pause");
	return 0;
}