/*
Connor Williams
Section 5
Lab 6
2/23/17
*/
#include <iostream>
#include <fstream>
using namespace std;

void ShowHeader(ofstream & fOut);
void CheckLetter(char tx);
void CheckNumber(char tx);
void CheckVowel(char tx);
void CheckCase(char tx);
void CheckEvenOdd(char tx);
void CheckLogOP(char tx);
void CheckPunc(char tx); 
int main()
{
	char tx;
	ofstream fOut;
	ifstream fIn;
	fOut.open("output.txt");
	fIn.open("input.txt");
	ShowHeader(fOut);
	while (fIn >> tx)
	{
		CheckLetter(tx);
		CheckNumber(tx);
		CheckLogOP(tx);
		CheckPunc(tx);
		

	}
	fOut.close();
	fIn.close();
	return 0;

}

void ShowHeader(ofstream &fOut)
{
	fOut << "Connor Williams\nSection5\nLab6\n2/23/2017" << endl;
}

void CheckLetter(char tx) //Checks if tx is a letter. If it is, calls two more functions to determine upper/lower case and vowel/consonent
{
	if ( (tx >= 'A' && tx <= 'Z') || (tx >= 'a' &&  tx <= 'z') )
	{
		cout << tx << " is  a letter" << endl;
		CheckCase(tx); // checks if letter is upper or lower case
		CheckVowel(tx); // checks if letter is vowel or consonant
	}
}
void CheckCase(char tx) // If letter, checks upper vs lower case
{
	if (tx >= 'A' && tx <= 'Z')
		cout << tx << " is upper case" << endl;
	else
		cout << tx << " is lower case" << endl;
}
void CheckVowel(char tx)
{
 	switch (tx) // switch statement. Checks if vowel
	{
	case 'A':       case 'a':
        case 'E':       case 'e':
        case 'I':       case 'i':
        case 'O':       case 'o':
        case 'U':       case 'u':
        	cout << tx << " is a vowel" << endl;
                break;
        default:
        	cout << tx << " is a consonent" << endl;
	}
}

void CheckNumber(char tx) // checks if tx is a number. If it is, it calls the CheckEvenOdd function
{
	if (tx >= '0' && tx <= '9')
	{
		cout << tx << " is a number" << endl;
		CheckEvenOdd(tx);
	}
}

void CheckEvenOdd(char tx) // checks if # is even or odd
{
	int ans = 0;
	ans = tx % 2;
	if (ans == 0)
		cout << tx << " is even" << endl;
	else
		cout << tx << " is odd" << endl;
}

void CheckLogOP(char tx) // Checks if tx is a logical operator
{
	switch(tx)
	{
	case '!':	case '&':
	case '=':	case '<':
	case '>':	case '|':
		cout << tx << " is a logical operator" << endl;
		break;
	}
}

void CheckPunc(char tx) // Checks if tx is a punctuation character
{
	switch(tx)
	{
	case '!':
	case '"':
	case ';':	case '?':
	case '.':	case ',':
		cout << tx << " is a punctuation character" << endl;
	}
}
