#include <iostream>
using namespace std;
int fib(int i, double &times);
int main()
{
	int n;
	char q;
	double times = 0;
	cout << "Enter number to find Fibonacci sequence" << endl;
	cin >> n;
	for (int g = 1; g < n; g++)
		cout << fib(g, times) << '\t';
	cout << endl;
	cout << "Function called: " << times << endl;
	cout << "quit?" << endl;
	cin >> q;
}

int fib(int i, double &times)
{
	times = times + 1;
	if (i <= 0)
		return 0;
	if (i == 1)
		return 1;
	else
		return fib(i - 1, times) + fib(i - 2, times);
}
