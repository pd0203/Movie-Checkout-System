// --------------------------------customer.h---------------------------------
// Hyosang Park CSS 343 A
// ---------------------------------------------------------------------------
// Describes the ADT Customer such that a record of id #, first/last name, and
// transaction history regarding media borrows/returns and history output
// requests can be recorded.
//
// This customer class deals with every customer-related information. 
// For example, id and name information of each customer are used to identify 
// each customer and history vector is used to store each customer’s
// transaction history. Therefore, we can know what items each customer 
// borrowed or returned.

// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a Customer
//      - copy a Customer
//      - destruct a Customer
//      - retrieve id/first/last
//      - display Customer info/history
//      - add a new Transaction to the Customer transaction historu
//      - evaluat whether two Customers are equivalent
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "transaction.h"

class Customer {
public:
	// ------------------------------Customer-----------------------------
	// Customer: creates a unique Customer.
	// preconditions: 0 <= id < 10,000, strings non-empty
	// postconditions: specified Customer created.
	// -------------------------------------------------------------------
	Customer(int ID, string fName, string lName);


	// ------------------------------Customer-----------------------------
	// Customer: creates a copy of the Customer.
	// preconditions: none.
	// postconditions: a copy of the other Customer is created.
	// -------------------------------------------------------------------
	Customer(const Customer& target);


	// ------------------------------Customer-----------------------------
	// ~Customer: destructs the Customer and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// -------------------------------------------------------------------
	~Customer();


	// -------------------------------getID-------------------------------
	// getID: obtains unique ID.
	// preconditions: none.
	// postconditions: unique ID returned.
	// -------------------------------------------------------------------
	int getID() const;


	// ------------------------------getFirst-------------------------------
	// getFirst: obtains the first name.
	// preconditions: none.
	// postconditions: first name returned.
	// -------------------------------------------------------------------
	string getFirstName() const;


	// ------------------------------getLast------------------------------
	// getFirst: obtains the last name.
	// preconditions: none.
	// postconditions: last name returned.
	// -------------------------------------------------------------------
	string getLastName() const;


	// ------------------------------display------------------------------
	// display: outputs unique ID + f/lname
	// preconditions: none.
	// postconditions: identity output to console.
	// -------------------------------------------------------------------
	void display() const;


	// --------------------------displayHistory---------------------------
	// displayHistory: outputs all Transaction history.
	// preconditions: none.
	// postconditions: all available Transaction history is output.
	// -------------------------------------------------------------------
	void transactionHistory() const;


	// --------------------------addTransaction---------------------------
	// addTransaction: add a Transaction to history as most recent.
	// preconditions: none.
	// postconditions: history vector includes Transaction as latest.
	// -------------------------------------------------------------------
	void addTransaction(Transaction target);


	// ----------------------------operator==-----------------------------
	// operator==: checks whether two customers are exactly same by using
	//             each customer’s id number, because every customer gets 
	//             a unique id number.
	// preconditions: none.
	// postconditions: true if identical, false otherwise.
	// -------------------------------------------------------------------
	bool operator==(const Customer& target) const;


	// ----------------------------operator!=-----------------------------
	// operator!=: checks whether two customers are not the same by using
	//             each customer’s id number, because every customer gets 
	//             a unique id number.
	// preconditions: none.
	// postconditions: true if different, false otherwise.
	// -------------------------------------------------------------------
	bool operator!=(const Customer& target) const;

private:
	int ID;							// customer unique id #
	string fName;					// first name
	string lName;					// last name
	vector<Transaction> history;	// transaction history
};

#endif 