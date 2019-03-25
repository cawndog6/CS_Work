/*
Connor Williams
3/23/17
Section 5
Lab8
*/

// Program that allows user to enter 10 integers, calculates the average & sum and prints the value of the
// average & sum.

#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int avg = 0;
	int array[10];
		for ( int x = 0; x < 9; x++ )
		{
			cout << "Hello. Please enter an integer 10 times:";
			cin >> array[x];
			sum = sum + array[x];
		}
	avg = sum / 10;
	cout << "Ty. Your average is " << avg << " and sum is " << sum << endl;
	cout << "Have a nice day :)" << endl;
	cout << array[11] << endl;
	cout << array[10000] << endl;
	return 0;
}

