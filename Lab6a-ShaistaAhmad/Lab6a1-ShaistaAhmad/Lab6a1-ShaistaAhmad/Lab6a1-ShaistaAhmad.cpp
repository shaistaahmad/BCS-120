#include "pch.h"
#include <iostream>
using namespace std;

void average(int n1, int n2, int n3);

int main()
{
	// call average function with numbers 10, 20 and 30
	// ...
	average(10, 20, 30);

	system("pause");
	return 0;
}


// purpose: calculate and display the average of three numbers on the screen
// inputs (parameters):  numbers n1, n2, n3
// outputs: average of n1,n2 and n3
void average(int n1, int n2, int n3) {
	double average;
	average = (n1 + n2 + n3) / 3;
	cout << "The average is: " << average << "\n";
}