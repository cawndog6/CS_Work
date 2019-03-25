/*
Connor Williams
4/18/17
Lab 12
Section 5
*/

/* This program asks the user for a persons name and id number, stores the data in a variable, and prints the name and id number entered on the screen */

#include <iostream>
using namespace std;
struct person
{
                char name[25];
                int ID;
};

void getnameid(person&);
void printnameid(person);

int main()
{
	person person1;
	getnameid(person1);
	printnameid(person1);
}

void getnameid( person& person1)// gets the name of the person and their ID number and stores them in a structure
{
	cout << "Please enter the persons name (max 25 characters): ";
	cin >> person1.name;
	cout << "Enter an ID number: ";
	cin >> person1.ID;
	cout << endl << endl;

}
void printnameid(person person1) // prints the name and id of entered person to screen
{
	cout << "Name: " << person1.name << endl;
	cout << "ID Number: " << person1.ID << endl;
}
