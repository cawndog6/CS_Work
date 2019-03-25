#include <iostream>
using namespace std;

char ToUpper(char);
int main()
{	
	char ch;
	char upper;
	cout << "Enter a character: ";
	cin >> ch;
	upper = ToUpper(ch);
	cout << "Upper case: " << upper << endl;
}
char ToUpper(char ch)
{
	char NewChar = ch;
	
	if ('a' <= ch && ch <= 'z')
	{
		int n = ch - 'a';
		NewChar = 'A' + n;
	}
	return NewChar;
}
