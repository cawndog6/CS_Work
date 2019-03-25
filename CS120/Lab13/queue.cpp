/* 
Connor Williams
4/25/2017
Lab 13
Section 5

This Program inserts items at the end of a list and removes items from the beginning.
*/

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
node *head = NULL;
node *curpos = NULL;
void insert(int);
int remove();
bool empty();

int main()
{
	int n;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(7);
	remove();
	remove();
	insert(5);
	insert(6);
	while (!empty()) // Remove nodes off list and print out on screen.
	{
		n = remove();
		cout << n;
		
	
	}
	cout << endl;
}

void insert (int n) // function to insert a new node with data at the end of the list
{
	node *newnode = new node;
	newnode->data = n;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		for(curpos = head; curpos->next != NULL; curpos = curpos->next);
		curpos->next = newnode;
	}
}
int remove() // function to remove one node at the beginning of the list. Returns remove data.
{
	int n;
	n = head->data;
	curpos = head;
	head = head->next;
	delete curpos;
	return n; 	
}
bool empty() // checks to see if the list is empty
{
        if(head == NULL)
        {
                
                return true;
        }
        else {
	return false;
	}
}

			
