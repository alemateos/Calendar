//Author:  Alejandro Mateos

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

string MONTH[13] = { "  ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
void printmonth(ofstream & outFile, int year);	//generates the calendar month by month.
bool leapYear(int year);	//finds out if it is a leap year or not 
int startDay(const int day, const int month, const int year);	//finds out the starting day of each month

int main()
{

	int year;
	

	do {

		cout << "Please enter a year: (1582-9999): " << endl;
		cin >> year;

	} while (year < 1582 || year > 9999);

	ofstream outFile;

	outFile.open("cal.dat");

	printmonth(outFile, year);
	
	outFile.close();

	return 0;
}

// *****************************************************************
// * Function Name: printmonth 
// * Description: generates the calendar month by month.
// * Parameters: outFile, year.
// * Date: 02/22/2017 
// * Author: Alejandro Mateos
// *****************************************************************

void printmonth(ofstream & outFile, int year)
{
	int daysInMonth[5] = { 0,28,29,30,31 };

	outFile << setw(16) << year << endl;

	for (int i = 1; i <= 12; i++)
	{
		int month = i;
		int count = startDay(1, i, year);
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

			outFile << setw(14 + (MONTH[i].size() / 2)) << MONTH[i] << endl;	//use it in the loop

			outFile << setw(3) << "Sun " << setw(3) << "Mon " << setw(3) << "Tue " << setw(3) << "Wed ";
			outFile << setw(3) << "Thu " << setw(3) << "Fri " << setw(3) << "Sat " << endl;

			outFile << setw(4 * startDay(1, i, year)) << "";				//takes you to the starting day
			for (int i = 1; i <= daysInMonth[4]; i++) {
				outFile << setw(3) << i << " ";
				if (++count == 7) {							//goes down a line when you get to saturday
					outFile << endl;
					count = 0;
				}

			}
			outFile << "\n" << endl;

		}

		if (month == 4 || month == 6 || month == 9 || month == 11) {

			outFile << setw(14 + (MONTH[i].size() / 2)) << MONTH[i] << endl;	//use it in the loop

			outFile << setw(3) << "Sun " << setw(3) << "Mon " << setw(3) << "Tue " << setw(3) << "Wed ";
			outFile << setw(3) << "Thu " << setw(3) << "Fri " << setw(3) << "Sat " << endl;

			outFile << setw(4 * startDay(1, i, year)) << "";
			for (int i = 1; i <= daysInMonth[3]; i++) {
				outFile << setw(3) << i << " ";
				if (++count == 7) {
					outFile << endl;
					count = 0;
				}

			}
			outFile << "\n" << endl;

		}
		if (month == 2 && leapYear(year) == true) {

			outFile << setw(14 + (MONTH[i].size() / 2)) << MONTH[i] << endl;	//use it in the loop

			outFile << setw(3) << "Sun " << setw(3) << "Mon " << setw(3) << "Tue " << setw(3) << "Wed ";
			outFile << setw(3) << "Thu " << setw(3) << "Fri " << setw(3) << "Sat " << endl;

			outFile << setw(4 * startDay(1, i, year)) << "";
			for (int i = 1; i <= daysInMonth[2]; i++) {
				outFile << setw(3) << i << " ";
				if (++count == 7) {
					outFile << endl;
					count = 0;
				}

			}
			outFile << "\n" << endl;
		}
		if (month == 2 && leapYear(year) == false) {

			outFile << setw(14 + (MONTH[i].size() / 2)) << MONTH[i] << endl;	//use it in the loop

			outFile << setw(3) << "Sun " << setw(3) << "Mon " << setw(3) << "Tue " << setw(3) << "Wed ";
			outFile << setw(3) << "Thu " << setw(3) << "Fri " << setw(3) << "Sat " << endl;

			outFile << setw(4 * startDay(1, i, year)) << "";
			for (int i = 1; i <= daysInMonth[1]; i++) {
				outFile << setw(3) << i << " ";
				if (++count == 7) {
					outFile << endl;
					count = 0;
				}

			}
			outFile << "\n" << endl;
		}

	}

}

// *****************************************************************
// * Function Name: startDay 
// * Description: finds out the starting day of each month.
// * Parameters: day, month, year.
// * Date: 02/22/2017 
// * Author: Alejandro Mateos
// * Referenes: Dr. David Gaitros
// *****************************************************************

int startDay(const int day, const int month, const int year) 
{
	int a, y, m, d;

	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
	
	return d;
}

// *****************************************************************
// * Function Name: leapYear 
// * Description: finds out if it is a leap year or not.
// * Parameters: year.
// * Date: 02/22/2017 
// * Author: Alejandro Mateos
// *****************************************************************

bool leapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;

}
