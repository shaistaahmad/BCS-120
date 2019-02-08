#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

void celsius(int Fahrenheit);

int main()
{
	cout << "Fahrenheit\tCelsius\n";

	for (int i = 0; i < 21; i++) {
		celsius(i);
		cout << "\n";
	}

}
void celsius(int fahrenheit) {
	float c = ( fahrenheit - 32);
	c = c * (5.0 / 9);
	cout << fahrenheit << " degrees\t" << fixed << setprecision(2) << c << " degrees";
}
