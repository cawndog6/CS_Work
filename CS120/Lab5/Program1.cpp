#include <iostream>
using namespace std;

int x = 0;
int y = 0;
int z = 0;
int getvalue();
int calculateproduct( int, int );
int printproduct( int );

main()
{
	x = getvalue();
	y = getvalue();
	z = calculateproduct(x, y);
	printproduct(z);

	return 0;
}
int getvalue()
{
	int v = 0;
	while ( v <= 0 )
	{
		cout << "Please enter a value greater than 0: ";
		cin >> v;
	}
	return v;
}
int calculateproduct( int arg1, int arg2 )
{
	int product;
	product = arg1*arg2;
	return product;
}
int printproduct( int shit )
{
	cout << "The product is " << shit << endl;
	return 0;
}
