// Lab5b-1ShaistaAhmad.cpp 
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int speed, hours, totalMiles = 0;

	cout << "What is the speed of the vehicle in mph? ";
	cin >> speed;
	cout << "How many hours has it traveled? ";
	cin >> hours;

	cout << "\nHours\t\tMiles Traveled" << endl;
	cout << "_______________________________" << endl;

	for (int i = 1; i < hours + 1; i++) {
		totalMiles = speed * i;
		cout << "  " << i << "\t\t\t" << totalMiles << endl;
	}
}


