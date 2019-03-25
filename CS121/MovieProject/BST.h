/*
Connor Williams
10/24/2017
CS121 Movie Project
BST.h
Binary Search Tree Header File
*/
#pragma once
#include <iostream>
#include <string>
#include "ActorsLL.h"

using namespace std;


class MovieBST // Movie database containing title, date, and actors of movies
{
	public:
		MovieBST(); // Constructor
		void AddMovie(string title, string date, ActorLL ActorList); // Add a new movie to the database
		/*void AllMovies(); // Displays the titles of all movies in the database
		void ActorsOfMovie(); // Displays the actors of a certain movie
		void MoviesOfActors(); // Displays the movies that an actor has acted in
		void MoviesOfYear(); // Displays the movies released of a certain year */
	private:
		struct BSTNode // Binary Search Tree of movies in the database
		{
			string M_Name; // Movie's title
			string M_Date; // Movie's production year
			ActorLL *ActorList; //
			BSTNode *left;
			BSTNode *right;
		};
		BSTNode *BSTRoot;
};
