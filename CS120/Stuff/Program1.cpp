#include <iostream>
using namespace std;
int main()
{
int x, y; // declare input variables
int sum = 0, average; // declare two more variables
cout << "Please enter a number: " << flush;
cin >> x;
cout << "Please enter another number: ’’ << flush;
cin >> y;
sum = x + y; // Calculate the sum
cout << "The sum of " << x << " plus " << y;
cout << " is " << sum << ".";
average = sum/2; // Calculate the average
cout << "The average of your numbers is ";
cout << average << "." << endl;
return 0;
}
