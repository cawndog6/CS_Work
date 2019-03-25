/*
Connor Williams
4/25/2017
Lab 13
Section 5

This Program inserts items at the beinning of a list and removes items off from the beginning of the list. 
*/

#include <iostream>
using namespace std;

struct node
{
	char c;
	struct node *next;
};

void push(char c);
char pop();
bool empty();

node *head = NULL;

int main()
{
	char p;
	push('t');
	push('e');
	push('s');
	push('t');
	push('a');
	push('n');
	push('g');
	pop();
	pop();
        pop();
        push('i');
	push('n');
	push('g');
	while(!empty())// removes items from list and prints to screen the items removed
	{
		p = pop();
		cout << p;
	}
	cout << endl;

}

void push(char c) // Adds a new node with data to the beginning of list
{
	node *newnode = new node;
	newnode->c = c;
	newnode->next = NULL;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}
char pop() // Removes a node from beginning of list and returns the data removed
{
	char popped;
	node *tmp;
	tmp = head;
	head = head->next;
	popped = tmp->c;
	delete tmp;
	
	return popped;
}
bool empty() // Checks to see if the list is empty
{
	char p;
	if(head->next == NULL)
	{
		p = pop();
                cout << p; 
		return true;
	}
	return false;
}
