/*
Connor Williams
2/6/2017
Lab4
Section 5
Do-While Loop Calculator
*/
#include <iostream> // Include iostream library
using namespace std;

int main() // Main program function
}
	int x = 0, sum = 0, loops = 0; // Initialized variables

	cout << "This program calculates up to 100 values. Enter a 0 to get the sum of the values entered if entering less than 100." << endl; // Describes program's function
	do // Loop to get values and calculate sum
	{
		cout << "Enter a value: "; // Gets value from keyboard
		cin >> x;
		sum = sum + x; // Calculates sum
		if ( x == 0 ) // Checks to see if zero was entered to halt loop
		{
			loops = 100;
		}
		loops = loops + 1; // Adds 1 to loops variable
	}
	while ( loops < 100 ); // Checks to see if loops variable is less than 100 to repeat loop
	cout << "The sum is " << sum << endl; // Prints sum
	return 0;
}
