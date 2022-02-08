// ----------------------------------Commands.h-------------------------------
// Hyosang Park CSS343
// ---------------------------------------------------------------------------
// Describes the ADT Commands such that handler of commands like borrow, 
// return, display history of a customer and display whole inventory. All of 
// methods in this class are called to Store class and used to handle every 
// single command of customers as reading every single sentence of command in 
// data4commands.txt file and managing these updated data through data 
// structures such as Binary Search Tree or customer Hash Table 
// ---------------------------------------------------------------------------
// Functionality includes:
//      - Create a transaction object of "borrow" command and store it in a customer object
//      - Create a transaction object of "return" command and store it in a customer object
//      - Display all of transaction history for a corresponding customer 
//      - Display the whole inventory for the movie store

#ifndef COMMANDS_H
#define COMMANDS_H
 
#include "BSTree.h"
#include "Customer.h"
#include "Hashtable.h" 
#include "MediaSearch.h" 

class Commands {

public:
	// ------------------------------borrowItem---------------------------
	// borrowItem: applies a borrow transaction for a particular customer
	//			   + Media item.
	// preconditions: customer exists, 0 < id < 10,000
	//			      media item exists.
	//                appropriate number of Media items 0 < item <= 10
	// postconditions: customer transaction history + item stock updated.
	// -------------------------------------------------------------------
	bool borrowItem(istream& file, HashTable<Customer>& customers, BSTree& comedy, BSTree& drama, BSTree& classic);
	
	
	// ------------------------------returnItem---------------------------
	// returnItem: applies a return transaction for a particular customer
	//			   + Media item.
	// preconditions: customer exists, 0 < id < 10,000
	//			      media item exists.
	//                appropriate number of Media items 0 <= item < 10 
	// postconditions: customer transaction history + item stock updated.
	// -------------------------------------------------------------------
	bool returnItem(istream& file, HashTable<Customer>& customers, BSTree& comedy, BSTree& drama, BSTree& classic);
	
	
	// ----------------------------displayHistory-------------------------
	// displayHistory: outputs the transaction history for a particular
	//				   customer.
	// preconditions: customer exists, 0 < id < 10,000
	// postconditions: customer transaction history, if any, is output.
	// -------------------------------------------------------------------
	bool displayHistory(istream& file, HashTable<Customer>& customers);


	// ---------------------------displayInventory------------------------
	// displayInventory: outputs all Media items.
	// preconditions: none.
	// postconditions: all Media items, if any, are output as they
	//				   appeared in input.
	// -------------------------------------------------------------------
	void displayInventory(string storeName, BSTree& comedy, BSTree& drama, BSTree& classic);

private:
	MediaSearch mediaSearch;
};
#endif