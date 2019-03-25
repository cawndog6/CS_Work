/* Class Stack Header */

class Stack
{
	public:
		Stack();
		void Push( int n );
		int Pop();
		int IsEmpty();
		void Print();
	private:
		LinkedList topPtr;
		struct node
		{
			int n;
			struct node *next;
		};
};
