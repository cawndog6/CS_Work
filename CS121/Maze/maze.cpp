/*
Connor Williams
9/28/2017
CS 121
Program Assignment #3
Maze Solving
*/

#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;

//function prototypes
bool isAdjacent(char **input, int cur_x, int cur_y, int rowcount, int colcount);
int main()
{
	char q;// simple holder to avoid program exit (use more permanent solution)
	const int Max_file = 30; //max input file name
	char FileName[Max_file]; // holds input file name
	ifstream fIn;
	char **input; //input array. Holds maze data
	int rowcount = 0; // row size for dynamic array (from input text file)
	int colcount = 0; // column size for dynam array (from input file)
	int start_x = 0; // starting "S" x coordinate
	int start_y = 0; // starting "S" y coordinate
	int cur_x = 0; // current x coordinate
	int cur_y = 0; // current y coordinate
	int que_y = 0;
	int que_x = 0;

	queue *que = new queue();
	cout << "Enter maze file, including .txt: " << endl;
	cin >> FileName;
	fIn.open(FileName);
	fIn >> colcount >> rowcount;
	input = new char*[rowcount];
	for (int i = 0; i < rowcount; i++)
		input[i] = new char[colcount];
	for (int i = 0; i < rowcount; i++)
	{
		for (int j = 0; j < colcount; j++)
		{
			fIn >> input[i][j];
			if (input[i][j] == 'S')
			{
				start_y = i;
				start_x = j;
			}
		}
	}
	cur_x = start_x;
	cur_y = start_y;

	int r = 4;
	while (r == 4)
	{
		input[cur_y][cur_x] = 'V';
		if (isAdjacent(input, cur_x, cur_y, rowcount, colcount))
		{
			break;
		}
		//input[cur_y][cur_x] = 'V';

		que->Enqueue(cur_y + 1, cur_x, input, colcount, rowcount);
		que->Enqueue(cur_y, cur_x + 1, input, colcount, rowcount);
		que->Enqueue(cur_y - 1, cur_x, input, colcount, rowcount);
		que->Enqueue(cur_y, cur_x - 1, input, colcount, rowcount);
		/*
		que->Enqueue(cur_y + 1, cur_x, input[cur_y + 1][cur_x], colcount, rowcount);
		que->Enqueue(cur_y, cur_x + 1, input[cur_y][cur_x + 1], colcount, rowcount);
		que->Enqueue(cur_y - 1, cur_x, input[cur_y - 1][cur_x], colcount, rowcount);
		que->Enqueue(cur_y, cur_x - 1, input[cur_y][cur_x - 1], colcount, rowcount);
		*/

		que->Dequeue(que_y, que_x);
		cur_y = que_y;
		cur_x = que_x;
	}

	for (int i = 0; i < rowcount; i++)
	{
		for (int j = 0; j < colcount; j++)
		{
			cout << input[i][j];
		}
		cout << endl;
	}
	//cout << "start y: " << start_y << " start x: " << start_x << endl;

	cout << "any key to quit" << endl;
	cin >> q;
}

// Function Definitions

bool isAdjacent(char **input, int cur_x, int cur_y, int rowcount, int colcount)
{
	if (cur_y + 1 < rowcount)
	{
		if (input[cur_y + 1][cur_x] == 'G')
			return true;
	} 
	if (cur_y - 1 >= 0)
	{
		if (input[cur_y - 1][cur_x] == 'G')
			return true;
	}
	if (cur_x + 1 < colcount)
	{
		if (input[cur_y][cur_x + 1] == 'G')
			return true;
	}

	if (cur_x - 1 >= 0)
	{
		if (input[cur_y][cur_x - 1] == 'G')
			return true;
	}
	return false;
}
