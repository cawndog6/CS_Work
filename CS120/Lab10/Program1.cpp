#include <iostream>
#include <fstream>
using namespace std;
//function prototypes
void ShowHeader(); //shows name, date, lab info
void Get_In_File(char FileContents[], int& z); //asks user for an input file, stores contents of it in array called FileContents[80]
char ComplementBase(char); // finds complement 
void ComplementStrand(char ComplementContents[], char FileContents[], int z);
void DrawDNA(char ComplementContents[], char FileContents[], int z);
void Prefix(char ComplementContents[], char FileContents[]); 
int main()
{
	int choice = 0;
	char FileContents[80];
	char ComplementContents[80];
	int z = 0; // z keeps track of how many characters are in the input file. It is always referred to as z in any given function.
	ShowHeader();
	Get_In_File(FileContents, z);
	ComplementStrand(ComplementContents, FileContents, z);
	cout << "Do you want to print the entire file, or just the first n bases of DNA?" << endl;
	cout << "Enter 1 for entire file or 2 for the first n bases." << endl;
	cin >> choice;
	while ((choice != 1) && (choice != 2))
	{
		cout << "Invalid choice. Enter 1 for entire file or 2 for the first n bases: " << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		DrawDNA(ComplementContents, FileContents, z);
	}
	else
	{
		Prefix(ComplementContents, FileContents);
	}		
	cout << "Your output is in the file named DNA_Output.txt." << endl;
}
//function definitions
void ShowHeader()
{
cout << "Connor Williams\n4/4/2017\nLab10\nSection5" << endl;
}
void Get_In_File(char FileContents[], int& z)
{
	char FileName[16];
	char v;
	ifstream fIn;
	cout << "Which input file should be used? Enter a text file name (up to 16 characters) including the .txt extension: ";
	cin >> FileName;
	fIn.open(FileName);
	while(fIn >> v)
	{
		FileContents[z] = v;
		//cout << FileContents[z];
		z++;
	}
	cout << endl;
}
char ComplementBase(char b)
{
	switch(b)
	{
		case 'A':
			b = 'T';
			break;
		case 'C':
			b = 'G';
			break;
		case 'G':
			b = 'C';
			break;
		case 'T':
			b = 'A';
			break;
		default:
			cout << "ERROR: INCORRECT DNA SEQUENCE ENTERED.";
			return '0';
	}
	return b;

}
void ComplementStrand(char ComplementContents[], char FileContents[], int z)
{
	for (int i = 0; i < z; i++)
	{
		char seq;
		char com;
		seq = FileContents[i];
		com = ComplementBase(seq);
		ComplementContents[i] = com;
		//cout << ComplementContents[i];
	
	}
	cout << endl;
}
void DrawDNA(char ComplementContents[], char FileContents[], int z)
{
	for(int i = 0; i < z; i++)
	{
	cout << "--+-";
	}
	cout << endl;
	for(int i = 0; i < z; i++)
        {
        cout << "  | ";
        }
        cout << endl;
	for(int i = 0; i < z; i++)
        {
        cout << "  " << FileContents[i] << " ";
        }
        cout << endl;
	for(int i = 0; i < z; i++)
        {
        cout << "  . ";
        }
        cout << endl;
	for(int i = 0; i < z; i++)
        {
        cout << "  " << ComplementContents[i] << " ";
        }
        cout << endl;
	for(int i = 0; i < z; i++)
        {
        cout << "  | ";
        }
        cout << endl;
 	for(int i = 0; i < z; i++)
        {
        cout << "--+-";
        }
	cout << endl;
}
void Prefix(char ComplementContents[], char FileContents[])
{
	int n;
	cout << "Enter number of bases to be printed: ";
	cin >> n;
	DrawDNA(ComplementContents, FileContents, n);
}
