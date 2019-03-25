/*
Connor Williams
Section 5
Lab 6
2/23/17
*/
#include <iostream>
#include <fstream>
using namespace std;

// Function prototypes----
void ShowHeader(ofstream & fOut);
void CheckLetter(char tx, ofstream &fOut);
void CheckNumber(char tx, ofstream &fOut);
void CheckVowel(char tx, ofstream &fOut);
void CheckCase(char tx, ofstream &fOut);
void CheckEvenOdd(char tx, ofstream &fOut);
void CheckLogOP(char tx, ofstream &fOut);
void CheckPunc(char tx, ofstream &fOut);
int main()
{
        char tx;
        ofstream fOut;
        ifstream fIn;
        fOut.open("output.txt"); // opens the output file
        fIn.open("input.txt"); // opens the input file
        ShowHeader(fOut); 
        while (fIn >> tx)
        {
                CheckLetter(tx, fOut);
                CheckNumber(tx, fOut);
                CheckLogOP(tx, fOut);
                CheckPunc(tx, fOut);


        }
        fOut.close();
        fIn.close();
//	cin.ignore();
//	cout << "Press enter to quit.";
//	cin.ignore();
        return 0;

}

void ShowHeader(ofstream &fOut)
{
        fOut << "Connor Williams\nSection5\nLab6\n2/23/2017" << endl;
}

void CheckLetter(char tx, ofstream &fOut) //Checks if tx is a letter. If it is, calls two more functions to determine upper/lower case and vowel/consonent
{
        if ( (tx >= 'A' && tx <= 'Z') || (tx >= 'a' &&  tx <= 'z') )
        {
                fOut << tx << " is  a letter" << endl;
                CheckCase(tx, fOut); // checks if letter is upper or lower case
                CheckVowel(tx, fOut); // checks if letter is vowel or consonant
        }
}
void CheckCase(char tx, ofstream &fOut) // If letter, checks upper vs lower case
{
        if (tx >= 'A' && tx <= 'Z')
                fOut << tx << " is upper case" << endl;
        else
                fOut << tx << " is lower case" << endl;
}
void CheckVowel(char tx, ofstream &fOut)
{
        switch (tx) // switch statement. Checks if vowel
        {
        case 'A':       case 'a':
        case 'E':       case 'e':
        case 'I':       case 'i':
        case 'O':       case 'o':
        case 'U':       case 'u':
                fOut << tx << " is a vowel" << endl;
                break;
        default:
                fOut << tx << " is a consonent" << endl;
        }
}

void CheckNumber(char tx, ofstream &fOut) // checks if tx is a number. If it is, it calls the CheckEvenOdd function
{
        if (tx >= '0' && tx <= '9')
        {
                fOut << tx << " is a number" << endl;
                CheckEvenOdd(tx, fOut);
        }
}

void CheckEvenOdd(char tx, ofstream &fOut) // checks if # is even or odd
{
        int ans = 0;
        ans = tx % 2;
        if (ans == 0)
                fOut << tx << " is even" << endl;
        else
                fOut << tx << " is odd" << endl;
}

void CheckLogOP(char tx, ofstream &fOut) // Checks if tx is a logical operator
{
        switch(tx)
        {
        case '!':       case '&':
        case '=':       case '<':
        case '>':       case '|':
                fOut << tx << " is a logical operator" << endl;
                break;
        }
}
void CheckPunc(char tx, ofstream &fOut) // Checks if tx is a punctuation character
{
        switch(tx)
        {
        case '!':
        case '"':
        case ';':       case '?':
        case '.':       case ',':
                fOut << tx << " is a punctuation character" << endl;
        }
}
