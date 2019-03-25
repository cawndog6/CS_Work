/*
Connor Williams
11/14/2017
Bruce Bolden
Hash Table Programming Assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Hash.h"
using namespace std;



int main()
{
	char q; // Holds program open to avoid closure at end of execution
	NullHashTable();
	string word;
	ifstream fIn;
	int total = 0; // Total words in hash table
	int Empty = 0; // Total empty buckets in table
	int min; // minimum bucket size 
	int max; // maximum bucket size

	fIn.open("dict4.txt");
	if (!fIn)
	{
		cout << "Unable to open input file. " << endl;
		return 0;
	}
	while (!fIn.eof())
	{
		getline(fIn, word);
		Insert(word);

	}
	fIn.close();
	fIn.open("dict8.txt");
	if (!fIn)
	{
		cout << "Unable to open input file. " << endl;
		return 0;
	}
	while (!fIn.eof())
	{
		getline(fIn, word);
		Insert(word);

	}
	int bucketwords = 0;
	cout << "# of words in bucket 3: ";
	bucketwords = WordsInBuckets(3, total);
	if (bucketwords == -1)
		cout << "The bucket does not exist." << endl;
	else
		cout << bucketwords << endl;
	cout << "# of words in bucket 58: ";
	bucketwords = WordsInBuckets(58, total);
	if (bucketwords == -1)
		cout << "The bucket does not exist." << endl;
	else
		cout << bucketwords << endl;
	cout << "# of words in bucket 13,500: ";
	bucketwords = WordsInBuckets(13500, total);
	if (bucketwords == -1)
		cout << "The bucket does not exist." << endl;
	else
		cout << bucketwords << endl;
	cout << "# of words in bucket 35,000: ";
	bucketwords = WordsInBuckets(35000, total);
	if (bucketwords == -1)
		cout << "The bucket does not exist." << endl << endl;
	else
		cout << bucketwords << endl;

	min = WordsInBuckets(0, total);
	max = min;
	total = 0;
	Empty = EmptyBuckets();
	for (int d = 0; d < HASH_TABLE_SIZE; d++)
	{
		int words;
		words = WordsInBuckets(d, total);
		if (min > words)
			min = words;
		if (max < words)
			max = words;
		
	}
	cout << "Total entries in hash table: " << total << endl;
	cout << "Total empty buckets in hash table: " << Empty << endl;
	cout << "Minimum size of bucket: " << min << endl;
	cout << "Maximum size of bucket: " << max << endl << endl;

	string searchword;
	int searches = 0;

	searchword = "guiltsick";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "Limax";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "hjkeah";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "resorbent";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "unskilful";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "poqiweur";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "donkeyish";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "griller";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "Piscataqua";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	searchword = "stemmer";
	cout << "Search for word: " << searchword << endl;
	cout << SearchForWord(searchword, searches);
	cout << " Total searches completed: " << searches << endl << endl;

	cout << "Close? " << endl;
	cin >> q;
	return 0;
}

