/*
Queue Implementation File
*/
#include "queue.h"
#include <iostream>
using namespace std;

queue::queue()
{
	head = NULL;
	curpos = NULL;
}
void queue::Enqueue(int y, int x, char **c, int colcount, int rowcount)
{
	if (y < 0 || x < 0 || y >= rowcount || x >= colcount)
	{
		return;
	}
	if (c[y][x] == 'V' || c[y][x] == '#')
	{
		return;
	}

	node *temp = new node;
	
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		curpos = head;
		while (curpos->next != NULL)
		{
			curpos = curpos->next;
		}
		//for (curpos = head; curpos->next != NULL; curpos = curpos->next);
		curpos->next = temp;
	}
	
}

void queue:: Dequeue(int & que_y, int & que_x)
{
	node *temp = head;
	que_x = head->x;
	que_y = head->y;
	head = head->next;
	delete temp;
}