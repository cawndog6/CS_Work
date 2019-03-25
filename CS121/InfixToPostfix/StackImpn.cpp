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
	if (top == NULL)
	{
		cout << "There is nothing in the stack" << endl;
	}
	else
	{
		node * temp;
		temp = top;
		char ch = top->data;
		top = top->next;
		delete temp;
		return ch;
	};
}
bool stack::isEmpty()
{
	if (stack::top == NULL)
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
		cout << "The stack is empty->" << endl;

	}
	else
	{
		return (top->data);
	}

}
