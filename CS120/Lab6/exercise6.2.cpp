#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fIn;
	fIn.open("input.txt");
	ofstream fOut;
	fOut.open("inputcontents.txt");
	char in;
	while (fIn >> in)
	{
		cout << in << endl;
		fOut << in << endl;
	}
	fIn.close();
	fOut.close();
}
