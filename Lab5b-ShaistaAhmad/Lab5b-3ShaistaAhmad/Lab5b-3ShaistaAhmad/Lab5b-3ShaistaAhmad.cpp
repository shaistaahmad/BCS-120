// Lab5b-3ShaistaAhmad.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int plusCount = 1, spaceCount, rowCount, entry;
	string space = " ";
	string plus = "+";
	
	cout << "Enter the base length of your triangle.\nBe sure to enter an odd number:  ";
	cin >> entry;

	if (entry % 2 != 0) {

		spaceCount = entry / 2;
		rowCount = spaceCount++;

		//this loops the amount of rows in the triangle
		for (int i = 0; i < rowCount + 1; i++) {

			//this loops the amount of spaces
			for (int j = spaceCount; j > 0; j--) {
				cout << space;
			}
			//this loops the amount of pluses in a row
			for (int k = 0; k < plusCount; k++) {
				cout << plus;
			}

			cout << "\n";
			spaceCount--;
			plusCount += 2;
		}
	}
	else
		cout << "\nThat entry was invalid. Please enter an ODD number.\n\n";

	return 0;
}

