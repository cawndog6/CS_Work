#include <iostream>
using namespace std;
int fib(int i);
int main()
{
	int n;
	char q;
	cout << "Enter number to find Fibonacci sequence" << endl;
	cin >> n;
	for (int g = 1; g < n; g++)
		cout << fib(g) << '\t';
	cout << endl;
	cout << "quit?" << endl;
	cin >> q;
}

int fib(int i)
{
	if (i <= 0)
		return 0;
	if (i == 1)
		return 1;
	else
		return fib(i - 1) + fib(i - 2);
}