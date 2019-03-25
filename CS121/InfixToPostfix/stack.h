using namespace std;

struct node
                {
                        char data;
                        struct node * next;
                };
class stack
{
	public:
		stack();
		//~stack();
		void push( char x );
		char pop();
		bool isEmpty();
		char peek();
		//void read();
	private:
		node *top;

};
