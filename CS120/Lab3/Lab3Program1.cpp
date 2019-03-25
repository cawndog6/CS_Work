/*
Connor Williams
1/30/17
Lab3
Section 5
*/
// A simple program that determines which of two integers entered by the user is larger.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
int x,y = 0;
	cout << "Welcome!\nPlease enter a number: ";
	cin >> x;
	cout << "Please enter another number: ";
	cin >> y;

	if ( x > y )
		{
		cout << x << " is greater than " << y;
		}
	if ( y > x )
		{
		cout << y << " is greater than " << x;
		}
	if ( x == y )
		{
		cout << x << " is equal to " << y << endl;
		}
	cin.ignore();
	cout << "\nPress enter to quit.\n";
	cin.ignore();
	return 0;
}
