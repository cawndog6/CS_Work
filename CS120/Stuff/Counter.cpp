// Counts numbers
#include <iostream>
#include <cstdlib>
using namespace std;

main()
{
float number = 100000;
do {
cout << "The number is: " << number << endl;
number = number * 10;
}
while ( number > 1 );
return 0;
}
