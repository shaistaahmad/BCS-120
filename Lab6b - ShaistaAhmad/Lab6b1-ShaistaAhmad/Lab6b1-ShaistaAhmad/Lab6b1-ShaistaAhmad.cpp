
#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int getDaysWorked(int num);
void displayPays(int num);

int main()
{
	int days;

	cout << "Enter the number of days you have worked this month: ";
	cin >> days;

	days = getDaysWorked(days);

	displayPays(days);

	cout << "\n\n";
	

}

//getDaysWorked Function
//Parameters: num - a number of days the user has worked
//Output: displays invalid message to user if not between 1-31
//Returns: the number of days to caller function

int getDaysWorked(int num) {
	
	while (num > 31 || num < 1) {
		cout << "Invalid Entry. Enter an input between 1- 31 days: ";
		cin >> num;
	}
	
	return num;
}

//displayPays Function
//Parameters: num - a number of days the user has worked
//Output: a table of how much salary was earned each day, as well as the total earned
//Returns: none
void displayPays(int num) {
	float totalPay = 0, payCounter = 0.005;

	cout << "\nDay\t\tPay\n____________________\n";

	for (int i = 1; i < num + 1; i++) {
		cout << i;
		payCounter = payCounter * 2;
		cout << "\t\t" << payCounter << endl;
		totalPay = totalPay + payCounter;
	}

	cout << "____________________\nTotal $\t\t" << totalPay;

}

