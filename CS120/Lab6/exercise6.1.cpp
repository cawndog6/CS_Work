#include <fstream>
using namespace std;

void ShowHeader(ofstream & fOut);
int main()
{
ofstream fOut;
fOut.open("header.txt");
ShowHeader(fOut);
fOut.close();
}

void ShowHeader(ofstream &fOut)
{
	fOut << "Connor Williams \nSection5 \nLab6";
}
