/*
Connor Williams
9/18/2017
CS121 Programming Assignment #2
Infix notation to postfix notation calculator
*/

#include <iostream>
#include "stack.h"
using namespace std;

//Function Prototypes
int strlen (char i[]); //finds length of input string 
void nulstr(char i[] , int); // Nullifies every character in input array
bool tprecedence(char sop, char c); //Checks operator precedence
int getweight(char op); // Gets weight of operator
int main()
{
	stack *s = new stack(); //holds operators
	int MAXI = 150 ; //Max input value
	char input[MAXI]; //Holds input expression
	char output[MAXI]; //holds output expression
	int LenI = 0; //Length of input expression
	int LenO = 0; //Length of output expression
	char c; // holds popped stack info
	
	int q = 0; // quit variable
	while (q != 1)
	{
		nulstr(input, MAXI);
		nulstr(output, MAXI);
		cout << "Enter infix expression and press enter. Type quit to quit: " << endl;
		cin.getline( input, MAXI);
		LenI = strlen(input);
		if ( input[0]=='q' && input[1]=='u' && input[2]=='i' && input[3]=='t' )
		{
			q = 1;
			continue; //leave loop and quit program
		}

		s->push('(');
		input[LenI] = ')';
		// algorithm
		
		int next = 0;
		while (!s->isEmpty())
		{
			char ch = input[next];
			next = next + 1;
	
			
			
		
			if (ch == '(')
			{
				
				s->push(ch);
			}
			else if(ch >= '0' && ch <= '9')
			{
			
				LenO = strlen(output);
				output[LenO] = ch;
			}
			else if( ch == ')')
			{
				
				c = s->pop();
				
				while ( c != '(')
				{
					
					LenO = strlen(output);
	                                output[LenO] = c;
					c = s->pop();
					
				}
				
			}
			else
			{
				char sop = s->peek();  	
				while(tprecedence( sop, ch ))
				{
					cout << "Broken Here!" << endl;
					c = s->pop();
					LenO = strlen(output);
                                	output[LenO] = c;
					sop = s->peek();

				}
				s->push(ch);
			}
		
		
		
		}
		cout << "works Here" << endl;
		//End algorithm
		cout << "Postfix Expression: " << endl;
		
		cout << output << endl;	
	}
}		
	
// Function Definitions
int strlen(char i[])
{
	int x = 0;
	while( i[x] != '\0' )
	{
		++x;
	}
	return x;
}
void nulstr(char i[], int MAXI)
{
	for( int x = 0; x < MAXI; x++)
	{
		i[x] = '\0';
	}
}
bool tprecedence(char sop, char c)
{
	int weightsop = getweight (sop);
	int weightc = getweight(c);
	if ( weightsop >= weightc )
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getweight( char op )
{
	int weight = -1;
	
	switch(op)
	{
		case '+':
			weight = 1;
		case '-':
			weight = 1;
		case '*':
			weight = 2;
		case '/':
			weight = 2;
		case '%':
			weight = 2; 
		return weight;
	}
}

/*
bool tprecedence(stack *s, char c)
{
	char t = s->peek();
        if ( t == '+' || t == '-' && c == '%' || c == '*' || c == '/' )
        {       
		return false;
        }
        else
        {
                return true;
	}
}
*/
