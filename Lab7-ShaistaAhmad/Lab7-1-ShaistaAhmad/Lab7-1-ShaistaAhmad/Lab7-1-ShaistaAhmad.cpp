#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream readFile;
	readFile.open("balance.txt");

	if (readFile) {

		string beginMonth, endMonth;
		float total = 0.0;
		float month = 0.0;
		int counter = 0;
		beginMonth = "";
		endMonth = "";

		readFile >> beginMonth;
		readFile >> endMonth;

		while (readFile >> month) {
			counter++;
			total += month;
		}

		readFile.close();

		float avg = 0.0;
		avg = total / counter;

		cout << "The balance between the months of " << beginMonth << " through " << endMonth << " is $" << avg << endl;

	}
	else {
		system("color 4F");
		cout << "Unable to retrieve file." << endl;
	}
	return 0;
}

