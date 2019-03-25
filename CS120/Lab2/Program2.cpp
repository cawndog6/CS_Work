

/* Connor Williams
   Lab2 Computer Science 1
   1/23/17
*/
#include <iostream>

using namespace std;

int main()
{
        double x, y;
        double sum = 0, average;

        cout << "Please enter a number: " << flush;
        cin >> x;
        cout << "Please enter another number: " << flush;
        cin >> y;
        sum = x + y; // Calculate the sum
        cout << "The sum of " << x << " plus " << y;
        cout << " is " << sum << ".";
        average = sum / 2; // Calculate the average
        cout << " The average of your numbers is ";
        cout << average << "." << endl;

        return 0;

}
