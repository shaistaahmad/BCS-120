#include "pch.h"
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

void saveDataToTextFile(ofstream &outputFile, string data);
void getChoice(int &userNum);
string setStudentData();
void searchStudent(ifstream &inputFile, int studentID);
void examStats(ifstream &inputFile, int examNum);


int main()
{
	ofstream outFile;
	ifstream infile;
	string field0 = "";
	string field1 = "";
	string field2 = "";
	string field3 = "";

	int choice;
	getChoice(choice);

	while (choice != 5) {
		switch (choice)
		{
		case 1: // to add a student--------------------------------------------
			outFile.open("data.txt", ios_base::app);
			cout << "\n---Add a Student's Grades---\n\n";

			if (outFile) {
				string temp = setStudentData();
				saveDataToTextFile(outFile, temp);
			}
			else {
				cout << "File is unable to open." << endl;
				system("color 4F");
			}
			outFile.close();
			getChoice(choice);
			break;
		case 2: // to display the entire class onto the screen --------------------------------
			cout << "\n---Display All Grades---\n\n";
			infile.open("data.txt");
			cout << "Student ID\tExam 1\tExam 2\tExam3" << endl;

			if (infile) {
				while (!infile.eof()) {
					infile >> field0 >> field1 >> field2 >> field3;
					cout << field0 << "\t\t" << field1 << "\t" << field2 << "\t" << field3 << endl;
				}
			}
			else {
				cout << "File is unable to open." << endl;
				system("color 4F");
			}
			infile.close();
			getChoice(choice);
			break;
		case 3: // asks for a student ID and displays their performance ------------------------------
			cout << "\n---Student's Exam Statistics ---\n\n";

			int searchID;
			cout << "Enter the ID number of the student you wish to see the grades for:\nID: ";
			cin >> searchID;

			infile.open("data.txt");

			searchStudent(infile, searchID);
				
			infile.close();
			getChoice(choice);
			break;
		case 4: // Asks for an exam and shows all the class stats --------------------------------------------
			cout << "\n---Exam Statistics---\n\n";

			int midterm;
			cout << "Which exam's overall class performance would you like to view? Exam (1) (2) or (3): ";
			cin >> midterm;
			while (midterm < 1 || midterm > 3) {
				cout << "This entry is invalid. Choose Exam (1) (2) or (3): "; 
				cin >> midterm;
			}
			infile.open("data.txt");
			examStats(infile, midterm);
			infile.close();
			getChoice(choice);
			break;
		}
	}
	if (choice == 5) {
			cout << "\nYou have successfully exited the program. Goodbye.\n\n";
	}


	return 0;
} //end of main


  //--------------------------------------------------------------------All Function Definitions---------------------------------------------------

//saveDataToTextFile function
//Purpose: Takes a string and saves it in a text file
//Parameter: &outputFile is a reference variable for a file, data is the string sent to &outputFile
//Return: none
void saveDataToTextFile(ofstream &outputFile, string data) {
	outputFile << data << endl;
}//end of saveDataToTextFile



//getChoice function
//Purpose: Assigns value to a variable
//Parameter: &userNum is a ref variable to be assigned
//Return: none
void getChoice(int &userNum) {
	cout << "\n\nChoose Menu Options 1 - 5: " << endl;
	cout << "1. Add a Student" << endl;
	cout << "2. Show Class" << endl;
	cout << "3. View a Student's Grade Performance" << endl;
	cout << "4. View an Exam's Statistics" << endl;
	cout << "5. Exit\n\n" << endl;
	cout << "Your choice: ";
	cin >> userNum;
	while (userNum < 1 || userNum > 5) {
		cout << "Invalid entry. Make sure to choose between 1 and 5: ";
		cin >> userNum;
	}
}//end of getChoice


 //setStudent function
//Purpose: takes user input of a student's ID and grades and saves it into a string
//Parameter: none
//Return: a string of characters representing a student's ID and his/her grades
string setStudentData() {
	int id;
	int grades[3];
	cout << "Enter a student ID: ";
	cin >> id;
	while (id < 0 || id > 999) {
		cout << "The ID you have entered is invalid for this fields between 0 - 999. Try again: ";
		cin >> id;
	}
	string str = std::to_string(id);
	str += "\t";
	
	for (int i = 0; i < 3; i++) {
		cout << "Enter a grade: ";
		cin >> grades[i];
		while (grades[i] < 0 || grades[i] > 100) {
			cout << "The grade you have entered is invalid. Try again: ";
			cin >> grades[i];
		}
		str += std::to_string(grades[i]) + "\t";	
	}
	return str;
}//end of setStudent

//searchStudent function
//Purpose: takes user input of a student's ID outputs that student's exam grade data
//Parameters: studentID - an int variable that represents the student's ID number; 
//           &inputFile - the reference variable for the file that will be opened for this task
//Return: none
void searchStudent(ifstream &inputFile, int studentID) {
	double avg;
	int mainID, exam1, exam2, exam3;

	if (inputFile) {
	while (inputFile >> mainID >> exam1 >> exam2 >> exam3) {
		

		if (studentID == mainID) {
			cout << "Student ID\t\tExam 1\tExam 2\tExam 3" << endl;
			cout << mainID << "\t\t\t" << exam1 << "\t" << exam2 << "\t" << exam3 << endl;
			avg = (exam1 + exam2 + exam3) / 4.0;
			cout << "The average of this student's exam scores is: " << avg << "%.\n\n" << endl;
			inputFile.eof();
		}
	}
 }
	else {
		cout << "File is unable to open." << endl;
		system("color 4F");
	}

} //end of searchStudent

//examStats function
//Purpose: takes user input for an exam and displays all grades performances in statistical format
//Parameters: int examNum - an integer variable that represents either the first, second, or third exam
//            &inputFile - a reference variable for the file that will be opened for this task
//Return: none
void examStats(ifstream &inputFile, int examNum) {
	double avg = 0.0;
	int min, max;
	int classCount = 0;
	int mainID, exam1, exam2, exam3;
	int exam1Sum = 0, exam2Sum = 0, exam3Sum = 0;
	
	if (inputFile) {
		
		while (inputFile >> mainID >> exam1 >> exam2 >> exam3) {

			
			switch (examNum) {
			case 1:
					if (classCount == 0) {
						min = exam1;
						max = exam1;
					}
					if (min > exam1) {
						min = exam1;
					}
					if (max < exam1) {
						max = exam1;
					}
					exam1Sum += exam1;
					classCount++;
					avg = static_cast<double>(exam1Sum) / (double)(1.0 * classCount);
				break;
			case 2: 
				
					if (classCount == 0) {
						min = exam2;
						max = exam2;
					}
					if (min > exam2) {
						min = exam2;
					}
					if (max < exam2) {
						max = exam2;
					}
					exam2Sum += exam2;
					classCount++;
					avg = static_cast<double>(exam2Sum) / (double)(1.0 * classCount);
				break;
			case 3: 
				
					if (classCount == 0) {
						min = exam3;
						max = exam3;
					}
					if (min > exam3) {
						min = exam3;
					}
					if (max < exam3) {
						max = exam3;
					}
					exam3Sum += exam3;
					classCount++;
					avg = static_cast<double>(exam3Sum) / (double)(1.0 * classCount);
				break;
			}


			}

		cout << "\nNumber of students who took this exam: " << classCount << " students." << endl;
		cout << "Average Class Test Score: " << avg << "%" << endl;
		cout << "Min Test Score: " << min << "% " << endl;
		cout << "Max Test Score: " << max << "% " << endl;

		}
	else {
		cout << "File is unable to open." << endl;
		system("color 4F");
	}



}//end of examsStats function



