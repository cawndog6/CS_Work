#include <iostream>
#include "stack.h"
using namespace std;

stack::stack()
{
	top = NULL;
}

void stack::push(char x)
{
	node *temp = new node;
	temp->data = x;
	temp->next = top;
 	top = temp;
}
char stack::pop()
{
	node * temp = NULL;
	if ( top == NULL )
	{
		cout << "There is nothing in the stack" << endl;
	}
	else
	{
	temp = top;
	top = temp->next;
	char ch = temp->data;
	delete temp;
	return ch;
	};
}
bool stack::isEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
char stack::peek()
{
	if (isEmpty())
	{
		cout << "The stack is empty." << endl;
		
	}
	else
	{
		return (top->data);
	}
	
}		
