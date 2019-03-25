/*
Connor Williams
10/24/2017
CS121 Movie Project
ActorsLL.h
Actor Linked List Header File
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class ActorLL
{
private:
	struct ActorNode
	{
		string ActorName;
		struct ActorNode *next;
	};
	ActorNode *Ahead;
	ActorNode *temp;

public:
	ActorLL()
	{
		Ahead = NULL;
		temp = NULL;
	}
	void AddActor(string A_Name)
	{
		ActorNode *NewActor = new ActorNode;
		NewActor->ActorName = A_Name;
		NewActor->next = NULL;
		if (Ahead == NULL)
		{
			Ahead = NewActor;
		}
		else
		{
			temp = Ahead;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NewActor;
		}
	}
	void PrintActors()
	{
		temp = Ahead;
		if (Ahead == NULL)
		{
			cout << "There are no actors in the list" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->ActorName << endl;
			temp = temp->next;
		}
	}
};
