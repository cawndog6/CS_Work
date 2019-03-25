
/*
Connor Williams
9/27/17
Queue header file
*/

using namespace std;

struct node 
{
	int x;
	int y;
	node *next;
};

class queue
{
public:
	queue(); //construtor
	void Enqueue(int y, int x, char **c, int colcount, int rowcount);
	void Dequeue(int & que_y, int & que_x);
private:
	node *head;
	node *curpos;
};
