//Shaista Ahmad - Lab5b-2
//Write a loop that takes users numbers and outputs the largest and smallest numbers that were input by the user
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
   
	int max = 0, min, entry = 0;
	cout << "Anytime you want to terminate the program, enter -99" << endl;

	cout << "Enter your first number: ";
	cin >> entry;
	if (entry != -99) {
		max = entry;
		min = entry;
	}
	else {
		cout << "The program has terminated.";
		return 0;
	}

	do {
		cout << "Enter another number: ";
		cin >> entry;

		if (entry > max && entry != -99) {
			max = entry;
		}
		
		if (entry < min && entry != -99) {
			min = entry;
		}

	} while (entry != -99);

	cout << "\nThe largest number entered was " << max;
	cout << "\nThe smallest number entered was " << min;
	cout << "\n\n\n";

}

