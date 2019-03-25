/*
Connor Williams
10/24/2017
CS121
Movie Project
MovieDatabase.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "ActorsLL.h"
using namespace std;

int main()
{
	string nextline;
	string title;
	string date;
	ActorLL *Actors;
	char z; // exit variable
	// First populate the database from input file
	ifstream fIn;
	fIn.open("movies.txt");
	if (!fIn)
	{
		cout << "Unable to read movie file. " << endl;
		return 0;
	}
	getline(fIn, nextline);
	//while (!fIn.eof())
	for (int c = 0; c < 4; c++)
	{
		date = nextline.substr(nextline.length() - 5, 4);
		title = nextline.substr(0, nextline.length()-7);
		cout << title << endl << date << endl;
		Actors = new ActorLL;
		getline(fIn, nextline);
		while (!nextline.empty())
		{
			Actors->AddActor(nextline);
			getline(fIn, nextline);
			
		}
		while(nextline.empty())
			getline(fIn, nextline);
		//AddMovie(title, date, Actors);
	}
	cout << "close?" << endl;
	cin >> z;
}

