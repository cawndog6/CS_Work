/*
Connor Williams
11/11/2017
CS 121
Hash Table Header File
Hash.h
*/
//#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <fstream>
#include "Hash.h"
using namespace std;

NListPtr hashTable[HASH_TABLE_SIZE];

void NullHashTable() // Makes every item in hash table point to NULL.
					 //Similar to head = NULL in a linked list.
{
	for (int a = 0; a < HASH_TABLE_SIZE; a++)
	{
		hashTable[a] = NULL;
	}
}
/*  Hash
*  Generate hash value for string s
*/
unsigned int Hash(string s)
{
	unsigned int hashVal = 0;
	const int namesize = 45;
	char name[namesize];
	ToCharArray(name, s, namesize);
	for (int i = 0;  name[i] != '\0'; i++)
		hashVal = name[i] + 31 * hashVal;
	return  hashVal % HASH_TABLE_SIZE;
}


/*  Lookup
*  Look for s in hashTable
*/

NListPtr Lookup(string s)
{
	NListPtr np;

	for (np = hashTable[Hash(s)]; np != NULL; np = np->next)
	{
		if (s.compare(np->word) == 0)
			return np;    //  found
	}

	return NULL;          //  not found
}

/*  Insert
*  Put (string s) in hash table
*/

void Insert(string s)
{
	unsigned int hashval;
	NListPtr np;
	if ((np = Lookup(s)) == NULL)  // not found
	{
		nList *newnode = new nList;
		newnode->word = s;
		newnode->next = NULL;
		hashval = Hash(s);
	
		if (hashTable[hashval] == NULL)
		{
			hashTable[hashval] = newnode;
		}
		else
		{
			NListPtr curpos = hashTable[hashval];
			while (curpos->next != NULL)
			{
				curpos = curpos->next;
			}
			curpos->next = newnode;

		}
		return;
	}
	else
	{
		return;
	}


}
/*  PrintHashTable
*  Print the hash table contents
*/

void PrintHashTable()
{
	NListPtr np;

	cout << "Hash table contents:" << endl;
	cout << "--------------------\n" << endl;

	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		np = hashTable[i];
		while (np != NULL)
		{
			cout << i << ":    ";
			cout << np->word << endl;
			np = np->next;
		}
	}
}
/*
Converts string to a character array for hash 
function
*/
void ToCharArray(char name[], string s, int namesize)
{
	int strlength = s.length();
	for (int i = 0; i < strlength; i++)
	{
		name[i] = s[i];
	}
	for (int n = strlength; n < namesize; n++)
	{
		name[n] = '\0'; // Makes every item in the array 
						//that doesnt contain a character from s NULL
	}
}
/*
 Finds the # of entries in a given bucket
 also modifies total to find total entries in the 
 hash table
*/
int WordsInBuckets(int i, int &total) 
{
	if (i >= HASH_TABLE_SIZE)
	{
		return -1;
	}
	int words = 0;
	NListPtr np = hashTable[i];
	if (np == NULL)
	{
		return 0;
	}
	else

	{
		while (np != NULL)
		{
			total = total + 1;
			words = words + 1;
			np = np->next;
		}
		return words;
	}

}
string SearchForWord(string s, int &searches) // Searches for word in table
{
	NListPtr np;
	searches = 0;
	for (np = hashTable[Hash(s)]; np != NULL; np = np->next)
	{
		searches++;
		if (s.compare(np->word) == 0)
			return "Word found!";    //  found
	}
	return "Word not found!"; // not found
}
int EmptyBuckets() // returns total # of empty buckets in hash table
{
	int Empty = 0; // Counter for empty buckets
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		NListPtr np = hashTable[i];
		if (np == NULL)
			Empty++;
	}
	return Empty;
}