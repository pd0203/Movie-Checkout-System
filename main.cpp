/*
// Hyosang Park 
// CSS343, Final Project 
// main.cpp
*/
// ----------------------------------main.cpp----------------------------------
// Hyosang Park CSS343
// ---------------------------------------------------------------------------
// Describe this project such that implementation of inventory tracking system 
// for a movie rental store. This program must handle three text files as an 
// input data and display the whole results of processing commands on terminal
// ---------------------------------------------------------------------------
// Functionality includes:
//      - Initialize a store object
//      - Load three input text files in same file directory
//      - Check out if text files exist in same file directory
//      - Read all of text files
//      - Manage a lot of data in text files with some data structures
//      - Output the result on the terminal 
//      - Detect the memory leak in this program 

#define CRTDBG_MAP_ALLOC     // To check out the memory leak

#include "Store.h"
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

int main() { 
	// Check out if there are memory leak in this program 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Initialize the Store object with the name of movie store. 
	Store movieStore("Best Movie Stores");

	// Make all of text files containing a lot of data readable by program
	ifstream movies("data4movies.txt");
	ifstream customers("data4customers.txt");
	ifstream commands("data4commands.txt");

	// If at least one of text files provided by professor doesn't exist,
	// program will be terminated
	if ((!movies) || (!customers) || (!commands)) {
		cout << "File can't be opened!" << endl;
		return 1;
	}

	// Read all of text files provided by professor and manage these
	// a lot of modified data through some data structures such as
	// Binary Search Tree and Hash Table
	movieStore.buildInventory(movies);
	movieStore.buildCustomers(customers);
	movieStore.buildCommands(commands);

	return 0;
}