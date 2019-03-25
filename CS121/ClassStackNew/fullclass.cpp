#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

class stack
{
	public:
		stack();
		~stack();
		void push( int x );
		int pop();
		bool isEmpty();
		int peek();
	private:
		node *top;
};
	
stack::stack()
{
	top = NULL;
}
stack::~stack() //deconstructor
{
	if ( top == NULL )
	{
		cout << "Nothing to clean up" << endl;
	}
	else
	{
		cout << "Delete should be happening now..." << endl;
	}
}
void stack::push(int x)
{
	node *temp = new node;
	temp->data = x;
	temp->next = top;
 	top = temp;
}
int stack::pop()
{
	node * temp = NULL;
	if ( top == NULL )
	{
		cout << "There is nothing in the stack" << endl;
	}
	else
	{
	temp = top;
	top = top->next;
	delete temp;
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
int stack::peek()
{
	if (isEmpty())
	{
		cout << "The stack is empty." << endl;
		return 0;
	}
	else
	{
		return (top->data);
	}
	
}		
int main() 
{
	stack *s = new stack();
	//delete s;
	s->push(4);
	cout << "peek: " << s->peek() << endl;
	s->push(7);
	cout << "peek: " << s->peek() << endl;
	s->pop();
	cout << "peek: " << s->peek() << endl;
}

