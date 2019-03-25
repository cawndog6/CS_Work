#include <iostream>
using namespace std;

int main()
{
	int i;
	int *p;
	int n;
	cout << "How big do you want the array?" << endl;
	cin >> i;
	p = new int[i];
	for (n = 0; n < i; n++)
	{
		cout << "Enter an int: " << endl;
		cin >> p[n];
	}
	cout << "You have entered: " << endl;
	for (n = 0; n < i; n++)
	{
		cout << p[n] << endl;
	}
}