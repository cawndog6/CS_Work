/* 
Connor Williams
10/24/2017
CS121 
Movie Project
BSTIMP.cpp
Binary Search Tree Implementation File
*/
#include<iostream>
#include<string>
#include "BST.h"
#include "ActorsLL.h"
using namespace std;

MovieBST::MovieBST() // Contructor
{
	BSTRoot = NULL;
}
void MovieBST::AddMovie(string title, string date, ActorLL actors )
{
	BSTNode *newnode = new BSTNode;
	newnode->M_Name = title;
	newnode->M_Date = date;

}