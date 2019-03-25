#include <iostream>
using namespace std;

int main()
{
	int j, k;
	double x, y;

	cout << "Enter two numbers: ";
	cin >> x >> y;
	cout << x << y;
	cout << "Enter two more numbers: ";
	cin >> k >> j;
	double a = x + y;
	double b = k * j;
	if(a >= b)
		cout << "product is les than sum" << endl;
	else
		cout << "product is greater than sum";
	return 0;
}
