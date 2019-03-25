/*
Connor Williams
2/7/2017
Lab4
Section 5
ASCII Table
*/

#include <iostream> // Include iostream library
using namespace std;
int main()
{
	cout << "	0	1	2	3	4	5	6	7	8	9" << endl; // Creates top row
	for ( int y = 40; y <= 110; y = y + 10 ) // Loop that creates Left column
	{
		cout << y << "\t";
		for ( int x = 0; x <= 9; x = x +1 )
		{
			cout << (char)(x + y) << "\t"; // Prints ASCII character
		}
		cout << endl;
	}
	return 0;
}
