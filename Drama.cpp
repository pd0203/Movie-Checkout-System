#include "Drama.h"

// --------------------------------Drama------------------------------
// Drama: creates a Drama item. no additional attribs.
// preconditions: none.
// postconditions: a Drama item is created.
// -------------------------------------------------------------------
Drama::Drama() {
	CATEGORY = "DRAMA";
	this->setGenre('D');
}


// --------------------------------Drama------------------------------
// Drama: creates a copy of the Drama.
// preconditions: none.
// postconditions: a copy of the Drama is created.
// -------------------------------------------------------------------
Drama::Drama(const Drama& target) {
	this->directorName = target.getDirector();
	this->title = target.getTitle();
	this->year = target.getYear();
}


// -------------------------------~Drama------------------------------
// Drama: frees all (static) alloc'd memory by engaging the right
//		  sequence of destructors -- from child to parent.
// preconditions: none.
// postconditions: all (static) memory de-alloc'd.
// -------------------------------------------------------------------
Drama:: ~Drama() {
}


// -------------------------------displayItem----------------------------
// display: outputs Drama details to console.
// preconditions: none.
// postconditions: Drama details output to console.
// -------------------------------------------------------------------
void Drama::displayItem() const {
	cout << this->CATEGORY << ", " << this->itemCount << ", " << this->directorName << ", " << this->title << ", " << this->year << endl;
}


// ------------------------displayTransaction-------------------------
// display: outputs Drama details for the command 'H'.
// preconditions: none.
// postconditions: details output to console. 
//                 Drama remains unchanged.
// -------------------------------------------------------------------
void Drama::displayTransaction() const {
	cout << this->CATEGORY << ", " << this->directorName << ", " << this->title << ", " << this->year << endl;
}


// -----------------------------operator==----------------------------
// operator==: determines if both items are identical, based on 
//	     	   attributes common to all Movie genres.
// preconditions: none.
// postconditions: true if identical, otherwise false.
// -------------------------------------------------------------------
bool Drama:: operator==(const Media& target) {
	const Drama& TargetDrama = static_cast<const Drama&>(target);
	return(directorName == TargetDrama.getDirector() && title == TargetDrama.getTitle());
}


// -----------------------------operator<----------------------------
// operator<: compares this Comedy object to check if it precedes the
//			  other.
// preconditions: none.
// postconditions: true if preceding, otherwise false.
// -------------------------------------------------------------------
bool Drama:: operator<(const Media& target) {

	const Drama& TargetDrama = static_cast<const Drama&>(target);

	if (directorName == TargetDrama.getDirector()) {
		if (title < TargetDrama.getTitle()) {
			return true;
		}
		return false;
	}
	else if (directorName < TargetDrama.getDirector()) {
		return true;
	}
	return false;
}


// -----------------------------operator>----------------------------
// operator<: compares this Comedy object to check if it follows the
//			  other.
// preconditions: none.
// postconditions: true if following, otherwise false.
// -------------------------------------------------------------------
bool Drama:: operator>(const Media& target) {

	const Drama& TargetDrama = static_cast<const Drama&>(target);

	if (directorName == TargetDrama.getDirector()) {
		if (title > TargetDrama.getTitle()) {
			return true;
		}
		return false;
	}
	else if (directorName > TargetDrama.getDirector()) {
		return true;
	}
	return false;
}