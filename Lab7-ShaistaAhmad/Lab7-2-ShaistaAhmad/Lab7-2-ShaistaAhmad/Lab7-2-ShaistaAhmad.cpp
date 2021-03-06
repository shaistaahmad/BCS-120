#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 10;
	int theArray[SIZE];


	// INPUT: save the scores into theArray.
	//...

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter a test score between 0 and 100: ";
		cin >> theArray[i];

		while (theArray[i] < 0 || theArray[i] > 100) {
			cout << "That entry was invalid. Try again: ";
			cin >> theArray[i];
		}
	}

	// PROCESS: count the perfect scores (i.e., 100s) in the array
	//...
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (theArray[i] == 100) {
			counter++;
		}
	}


	// OUTPUT:  display the count of prefect scores on the screen
	//...

	cout << counter << " people in the class scored a perfect score of a 100!" << endl;

	return 0;
}

