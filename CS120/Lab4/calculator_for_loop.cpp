/*
Connor Williams
2/6/2017
Lab4
Section 5
For Loop Calculator
*/
#include <iostream>
using namespace std;
int main()
{
	int sum, x;

	for ( int loops = 0 ; loops < 5 ; loops++ )
	{
		cout << "Enter a value: ";
		cin >> x;
		sum = sum + x;
		cout << endl;
	}
	cout << "The sum is: " << sum << endl;
	return 0;
}
