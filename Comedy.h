// ------------------------------------Comedy.h--------------------------------
// Hyosang Park CSS343
// ---------------------------------------------------------------------------
// Describes the ADT Comedy such that a particular Comedy genre can not only
// maintain a record of director, title and year (as all Movie genres do), but
// to also record any other details that may be included later (now, none).
// The const string is the main differentiator between the other derivatives
// of Movie.

// Comedy is a child class derived from Movie.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a Comedy item
//      - copy an existing Comedy item
//		- destruct a Comedy item
//		- retrieve attributes
//		- display details
//		- comparison operators (==, <)
#ifndef COMEDY_H
#define COMEDY_H 

#include "Media.h"

class Comedy : public Media {
public:
	// --------------------------------Comedy------------------------------
	// Comedy: creates a Comedy item. No additional attributes.
	// preconditions: none.
	// postconditions: a Comedy item is created.
	// -------------------------------------------------------------------
	Comedy();


	// --------------------------------Comedy------------------------------
	// Comedy: copies the Comedy item.
	// preconditions: none.
	// postconditions: a copy of the Comedy item is created.
	// -------------------------------------------------------------------
	Comedy(const Comedy& target);


	// -------------------------------~Comedy------------------------------
	// Comedy: frees all (static) alloc'd memory by engaging the right
	//		   sequence of destructors -- from child to parent.
	// preconditions: none.
	// postconditions: all (static) memory de-alloc'd.
	// -------------------------------------------------------------------
	virtual ~Comedy();


	// -------------------------------displayItem-----------------------------
	// displayItem: outputs Comedy details for the command 'I' 
	// preconditions: none.
	// postconditions: Comedy details output to console.
	//				   Comedy remains unchanged.
	// -------------------------------------------------------------------
	virtual void displayItem() const;


	// ---------------------------displayTransaction-------------------------
	// displayTransaction: outputs Comedy details for the command 'H'
	// preconditions: none.
	// postconditions: Comedy details output to console.
	//				   Comedy remains unchanged.
	// -------------------------------------------------------------------
	virtual void displayTransaction() const;


	// -----------------------------operator==----------------------------
	// operator==: determines if both items are identical, based on 
	//	     	   attributes common to all Movie genres.
	// preconditions: none.
	// postconditions: true if identical, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator==(const Media& target);


	// -----------------------------operator<----------------------------
	// operator<: compares this Comedy object to check if it precedes the
	//			  other.
	// preconditions: none.
	// postconditions: true if preceding, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator<(const Media& target);

	// ------------------------------operator>---------------------------
	// operator>: determines if this media follows the other Media.
	// preconditions: none.
	// postconditions: true if following, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator>(const Media& target);

private:
	string CATEGORY;
};
#endif 