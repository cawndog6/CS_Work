/*
Connor Williams
2/6/2017
Lab4
Section 5
No Loops Calculator
*/
#include <iostream> //include library
using namespace std;

int main() // Main program function
{
double a,b,c,d,e,sum; // Creates variables
cout << "Enter 5 values in the form a b c d e: ";
cin >> a >> b >> c >> d >> e; // Inputs values into variables
sum = a + b + c + d + e; // Calculates sum of values
cout << endl << "The sum is: " << sum << endl; // Prints sum on screen
return 0;
}
