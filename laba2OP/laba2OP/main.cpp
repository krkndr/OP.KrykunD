#define _CRT_SECURE_NO_WARNINGS
#define _XOPEN_SOURCE
#include "filebinary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <time.h>


using namespace std;

int main()
{
	string input = "input.dat";
	string output = "output.dat";
	writeBinary();
	cout << "\nThe contents of the source file (input.dat):" << endl;
	readBinary(input);
	data(input, output);
	cout << "The contents of the new file (output.dat):\nList of machines that went on sale no later than two months after the date of manufacture:" << endl;
	readBinary(output);
	int year = inputYear();
	findCar(input, year);
	char c;
	cout << "Do you want to add a file (input.dat)? y/n >>"; 
	cin >> c;
	if (c == 'y' || c == 'Y') {
		addBinary(input);
		cout << "The contents of the changed file (input.dat):" << endl;
		readBinary(input);
		char ch;
		cout << "Do you want to change the file according to the task? Y/N >>";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			data(input, output);
			cout << "The contents of the new file (output.dat):\nList of machines that went on sale no later than two months after the date of manufacture:" << endl;
			readBinary(output);
			int year = inputYear();
			findCar(input, year);
		}
		
	}
	return 0;
}