// ----------------------------------store.h----------------------------------
// Hyosang Park CSS343
// ---------------------------------------------------------------------------
// Describes the ADT Store such that collections of information + records
// can be maintained to represent a movie store that is setup for Media item
// checkouts, much like a library. Any given Store will maintain a record
// of Media items, customers, and the transaction history of said customers.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a no-name Store
//		- create a named Store
//		- copy an existing Store
//		- destruct a Store
//		- build a Customer hash table from file
//		- build a Media binary search trees for comedy, classic and drama from file
//		- Process inventory/history/borrow/return requests for any Customer
//		- Get the name of store 

#ifndef STORE_H
#define STORE_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "customer.h"
#include "Media.h"
#include "BSTree.h"
#include "HashTable.h"
#include "MediaFactory.h" 
#include "Commands.h" 

class Store {
public:
	// --------------------------------Store------------------------------
	// Store: creates a named Store.
	// preconditions: none.
	// postconditions: a named Store is created.
	// -------------------------------------------------------------------
	Store(string storeName);

	// -------------------------------~Store------------------------------
	// ~Store: destructs the Store and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// -------------------------------------------------------------------
	~Store();


	// ----------------------------buildCustomers--------------------------
	// buildCustomers: builds Customer hash table from file.
	// preconditions: file is properly formatted, i.e. each line is
	//				  #### fname lname
	//				  given 4 digit IDs, the maximum allowed is 10,000.
	// postconditions: customer hash table populated with all entries.
	// -------------------------------------------------------------------
	void buildCustomers(istream& file);


	// ----------------------------buildInventory--------------------------
	// buildInventory: builds Media tree from file.
	// preconditions: file is properly formatted, i.e. each line is
	//				  X, ##, dfname dlname, title, . . . 
	//				  genre, stock, director name, title, and more attribs
	//				  comma delimited
	// postconditions: BSTree populated with media items.
	// -------------------------------------------------------------------
	void buildInventory(istream& file);

	// --------------------------executeTransactions----------------------
	// executeTransactions: process transactions from file and update
	//						records as needed.
	// preconditions: file is properly formatted, i.e. each line is one of
	//				  X #### X X # #### fname lname
	//				  X #### X X Title, ####
	//				  X #### X X fname lname, title
	//				  X ####
	//				  X
	// postconditions: records updated according to transactions.
	// -------------------------------------------------------------------
	void buildCommands(istream& file);


	// -------------------------------getName-----------------------------
	// getName: obtains store name, if any.
	// preconditions: none.
	// postconditions: store name returned.
	// -------------------------------------------------------------------
	string getName() const;

private:
	string name;                            // title of business
	const static int MAX_CUSTOMERS = 10000;
	const static int MAX_GENRES = 53; 		// 2x alphabet, closest prime

    HashTable<Customer> customersTable;	    //Customer members[MAX_CUSTOMERS]; 	

	//Media Inventory 
	BSTree comedyInventory;
	BSTree dramaInventory;
	BSTree classicInventory;

	Commands commands;
	MediaFactory mediaFactory;
};
#endif

