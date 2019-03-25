#pragma once
/*
Connor Williams
11/11/2017
CS 121
Hash Table Header File
Hash.h
*/

#include <iostream>
using namespace std;


struct nList     /*  table entry:  */
{
	string word;          /*  defined name         */
	struct nList *next;  /*  next entry in chain  */
};
typedef struct nList *NListPtr;

const int HASH_TABLE_SIZE = 101;
unsigned int Hash(string s);
NListPtr Lookup(string s);
void Insert(string s);
void NullHashTable();
void PrintHashTable();
int WordsInBuckets(int, int &total);
void ToCharArray(char[], string, int);
int EmptyBuckets();
string SearchForWord(string s, int &searches);
