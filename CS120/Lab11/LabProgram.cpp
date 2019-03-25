#include <iostream>
using namespace std;
void func1(char *q);

int main() {
	char array[] = "abcdef";
	char *p;
	cout << "initial array: " << array << endl;
	p = array;
	*p = 'x';
	p = &array[1];
	p++;
	*p = 'x';
	p = &array[3];
	p[2] = 'x';
	p--;
	func1(p);
	func1(array);
	func1(&array[3]);
	cout << "final array: " << array << endl;
}
void func1(char *q) {
	q++;
	*q = 'x';
}
