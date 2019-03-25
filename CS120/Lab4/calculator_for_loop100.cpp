
/*
Connor Williams
2/6/2017
Lab4
Section 5
For Loop100 Calculator
*/
#include <iostream> // Include iostream library
using namespace std;
int main() //main function
{
	int sum, x; // Defines two variables

        for ( int loops = 0 ; loops < 100, x != 0 ; loops++ ) // Loop to get values and calculate sum
        {
                cout << "Enter a value: "; // Gets value from keyboard
                cin >> x;
                sum = sum + x; // Calculates sum
                cout << endl;
        }
        cout << "The sum is: " << sum << endl; // Prints sum
	return 0;
}

