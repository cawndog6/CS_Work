#include <fstream>
using namespace std;
void showheader();
int main()
{
ofstream outFile;
outFile.open("header.txt");
outFile << "hello files";
outFile.close();
}
