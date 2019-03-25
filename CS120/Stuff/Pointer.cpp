#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int* pt;
	pt = &a;
	cout << *pt << endl;
	a = 8;
	cout << *pt << endl;
return 0;
}
