#include <fstream>
#include <iostream>
using namespace std;


int main()
{
	ifstream inFile;
	inFile.open("input.txt");
	char in;
	while (inFile >> in)
	{
		cout << in << endl;
	}
	inFile.close();
}
