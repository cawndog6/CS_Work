/*
Connor Williams
2/6/2017
Lab4
Section 5
While Loop Calculator
*/
#include <iostream> // Include iostream library
using namespace std;

int main() // Main function
{
	int x = 0, sum = 0, loops = 0; // Defines variables
	cout << "This program calculates up to 100 values. Enter a 0 to get the sum of the values entered if entering less than 100." << endl; // Statement describing program's function
	while ( loops < 100 ) // Loop that gets values from keyboard and calculates sum
	{
		cout << "Enter a value: "; // Gets value from keyboard
		cin >> x;
		cout << endl;
		sum = sum + x; // Calculates sum
		if ( x == 0 ) // Checks to see if a 0 has been entered to terminate loop
		{
			loops = 100;
		}
		loops = loops + 1; // Adds 1 to Loops variable
	}
	cout << "The sum is " << sum << endl; // Prints sum
	return 0;
}
