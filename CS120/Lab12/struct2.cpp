/*
Connor Williams
4/18/2017
Lab 12
Section 5
*/

/* This program allows the user to enter up to 10 student names and id #s and then prints them to the screen. */

#include <iostream>
using namespace std;

struct student
{
	char name[25];
	int ID;
};
void GetStudent(student[], int);
void PrintStudent(student[], int);

int main()
{
	student students[10];
	int choice=0;
	int i=0;
	cout << "You may enter up to 10 students." << endl;
	while (i<10)
	{
		GetStudent (students, i);
		cout << "Do you want to enter more? Press 1 if you're finished or 2 to continue adding students: ";
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "Invalid number entered. Press 1 if you're finished or 2 to continue adding students: ";
			cin >> choice;
		}
		if (choice == 1)
		{	
			i++;
			break;
		}
		i++;
	}
	PrintStudent (students, i);
}

void GetStudent (student students[], int i) // gets name and ID of student from user. Can take up to 10
{
	cout << "Enter the student's name: ";
	cin >> students[i].name;
	cout << "Enter the student's ID number: ";
	cin >> students[i].ID;
}
void PrintStudent (student students[], int i) // prints all name and ID numbers stored in the array
{
	for (int s = 0; s < i; s++)
	{
		cout << "Student #" << s << "'s name: " << students[s].name << endl;
		cout << "Student #" << s << "'s ID number " << students[s].ID << endl;
		cout << endl;
	}
}

