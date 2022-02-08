// --------------------------------transaction.h------------------------------
// Hyosang Park CSS343 
// ---------------------------------------------------------------------------
// Describes the ADT Transaction such that any given transaction is processed
// for any given customer can be encapsulated to be stored in a collection for
// records (history). Only the transaction type and associated Media item are
// recorded, the customer is tracked by virtue of the Transaction being in
// that customer's history.
//
// Holds what type of transaction [i.e. Borrow or Return] each customer did 
// and what kind of media item is related with that transaction.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a new Transaction
//      - copy an exist Transaction
//      - destruct a Transaction
//      - retrieve the transaction type
//      - retrieve a ptr to the assoc. Media item
//      - display Transaction details
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "media.h"
#include <iostream>
#include <iomanip>

class Transaction {
public:
	// ---------------------------Transaction-----------------------------
	// Transaction: creates a Transaction record.
	// preconditions: string is non-empty.
	// postconditions: Transaction created with specified trans type and
	//				   ptr to assoc. Media item.
	// -------------------------------------------------------------------
	Transaction(char type, Media* item);


	// ---------------------------Transaction-----------------------------
	// Transaction: creates a copy of the Transaction.
	// preconditions: none.
	// postconditions: a copy of the Transaction is created.
	// -------------------------------------------------------------------
	Transaction(const Transaction& target);


	// ---------------------------Transaction-----------------------------
	// ~Transaction: destructs the Transaction and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// -------------------------------------------------------------------
	~Transaction();


	// -----------------------------getType-------------------------------
	// getType: obtains the trans type.
	// preconditions: none.
	// postconditions: trans type returned.
	// -------------------------------------------------------------------
	char getType() const;


	// -----------------------------getItem-------------------------------
	// getItem: obtains ptr to linked Media item.
	// preconditions: none.
	// postconditions: ptr to Media item returned, NULL if N/A.
	// -------------------------------------------------------------------
	Media* getItem() const;


	// -----------------------------display-------------------------------
	// display: output the Transaction details to console.
	// preconditions: none.
	// postconditions: Transaction details, including trans type and Media
	//				   information are output to console.
	// -------------------------------------------------------------------
	void display() const;

private:
	char type;	// transaction type (borrow, return or history)
	Media* item;	// ptr to assoc. Media item
};

#endif 