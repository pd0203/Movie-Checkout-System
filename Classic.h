// ----------------------------------classic.h--------------------------------
// Hyosang Park CSS 343
// ---------------------------------------------------------------------------
// Describes the ADT Classic such that a particular Movie genre can not only
// maintain a record of director, title and year (as all Movie genres do), but
// to also record the first + last name of the actor and the release month.
//
// Classic is a child class derived from Movie.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a Classic item
//      - copy an existing Classic item
//		- destruct a Classic item
//		- retrieve attributes
//		- display details
//		- comparison operators (==, <)
#ifndef CLASSIC_H
#define CLASSIC_H 

#include "Media.h"

class Classic : public Media {
public:
	// -------------------------------Classic-----------------------------
	// Classic: creates a specified Classic item.
	// preconditions: strings nonempty.
	//				  1 <= month <= 12
	// postconditions: specified Classic is created.
	// -------------------------------------------------------------------
	Classic(string actN, int mo);

	
	// -------------------------------Classic-----------------------------
	// Classic: creates a copy of the Classic.
	// preconditions: none.
	// postconditions: a copy of the Classic is created.
	// -------------------------------------------------------------------
	Classic(const Classic& target);


	// ------------------------------~Classic-----------------------------
	// ~Classic: frees all (static) alloc'd memory by engaging the right
	//		     sequence of destructors -- from child to parent.
	// preconditions: none.
	// postconditions: all (static) memory de-alloc'd.
	// -------------------------------------------------------------------
	virtual ~Classic();


	// ----------------------------getActorName--------------------------
	// getActorFName: obtains the lead actor's name.
	// preconditions: none.
	// postconditions: lead actor's name returned.
	// -------------------------------------------------------------------
	string getActorName() const;


	// ------------------------------getMonth-----------------------------
	// getMonth: obtains the release year.
	// preconditions: none.
	// postconditions: release year is returned.
	// -------------------------------------------------------------------
	int getMonth() const;


	// ---------------------------displayItem-----------------------------
	// displayItem: outputs Classic details for the command 'I'.
	// preconditions: none.
	// postconditions: details output to console. 
	//                 Classic remains unchanged.
	// -------------------------------------------------------------------
	virtual void displayItem() const;


	// ------------------------displayTransaction-------------------------
	// display: outputs Classic details for the command 'H'.
	// preconditions: none.
	// postconditions: details output to console. 
	//                 Classic remains unchanged.
	// -------------------------------------------------------------------
	virtual void displayTransaction() const;


	// -----------------------------operator==----------------------------
	// operator==: determines if both items are identical, based on 
	//			   attributes common to all Movie genres (unless a
	//			   comparison is made with another Classic, which includes
	//			   the additional attribs).
	// preconditions: none.
	// postconditions: true if identical, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator==(const Media& target);


	// -----------------------------operator<----------------------------
	// operator<: compares this Classic object to check if it precedes 
	//			  the other.
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
	string CATEGORY;	// genre
	string actorName;   // name of main actor
	int month;		    // month of release
};

#endif 