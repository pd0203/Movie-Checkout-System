// ------------------------------------drama.h--------------------------------
// Hyosang Park CSS343 
// ---------------------------------------------------------------------------
// Describes the ADT Drama such that a particular Drama genre can not only
// maintain a record of director, title and year (as all Movie genres do), but
// to also record any other details that may be included later (now, none).
// The const string is the main differentiator between the other derivatives
// of Movie.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a Drama item
//      - copy an existing Drama item
//		- destruct a Drama item
//		- retrieve attributes
//		- display details
//		- comparison operators (==, <)
#ifndef DRAMA_H
#define DRAMA_H

#include "Media.h"

class Drama : public Media {
public:
	// --------------------------------Drama------------------------------
	// Drama: creates a Drama item. no additional attribs.
	// preconditions: none.
	// postconditions: a Drama item is created.
	// -------------------------------------------------------------------
	Drama();


	// --------------------------------Drama------------------------------
	// Drama: creates a copy of the Drama.
	// preconditions: none.
	// postconditions: a copy of the Drama is created.
	// -------------------------------------------------------------------
	Drama(const Drama& target);


	// -------------------------------~Drama------------------------------
	// Drama: frees all (static) alloc'd memory by engaging the right
	//		  sequence of destructors -- from child to parent.
	// preconditions: none.
	// postconditions: all (static) memory de-alloc'd.
	// -------------------------------------------------------------------
	virtual ~Drama();


	// -------------------------------displayItem-----------------------------
	// display: outputs Drama details to console.
	// preconditions: none.
	// postconditions: Drama details output to console.
	// -------------------------------------------------------------------
	virtual void displayItem() const;


	// ------------------------displayTransaction-------------------------
	// display: outputs Drama details for the command 'H'.
	// preconditions: none.
	// postconditions: details output to console. 
	//                 Drama remains unchanged.
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