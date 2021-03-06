#include "pch.h"
#include <iostream>
using namespace std;

void getScore(int &);
int findLowest(int, int, int, int, int);
void calcAverage(int, int, int, int, int);


int main()
{
	int test1, test2, test3, test4, test5;

	getScore(test1);
	getScore(test2);
	getScore(test3);
	getScore(test4);
	getScore(test5);

	calcAverage(test1, test2, test3, test4, test5);
	cout << "\n\n";
	
}

//getScore function: asks user for a test score and initializes values onto caller variables
//Parameters: reference variable
//Outputs: asks user for input
//Return: none
void getScore(int &userNum) {
	while (userNum < 0 || userNum > 100) {
		cout << "Enter a valid test score between 0-100: ";
		cin >> userNum;
	}
}

//findLowest function: finds the lowest value between 5 integers
//Parameters: a,b,c,d,e integer variables
//Outputs: none
//Return: the lowest variable
int findLowest(int a, int b, int c, int d, int e) {

	int lowest = a;

	if (b < lowest)
		lowest = b;
	if (c < lowest)
		lowest = c;
	if (d < lowest)
		lowest = d;
	if (e < lowest)
		lowest = e;

	return lowest;

}

//calcAverage function: finds the average of four of the highest scores
//Parameters: a,b,c,d,e integer variables
//Outputs: the average in a display message
//Return: none
void calcAverage(int a, int b, int c, int d, int e) {

	float average = ((a + b + c + d + e) - findLowest(a, b, c, d, e));
	average = average / 4.0;

	cout << "The average of all the test scores, with the lowest being dropped, is: ";
	cout << average;

}

