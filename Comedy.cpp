#include "Comedy.h"


// --------------------------------Comedy------------------------------
// Comedy: creates a Comedy item. No additional attributes.
// preconditions: none.
// postconditions: a Comedy item is created.
// -------------------------------------------------------------------
Comedy::Comedy() {
	this->CATEGORY = "Comedy";
	this->setGenre('F');
}


// --------------------------------Comedy------------------------------
// Comedy: copies the Comedy item.
// preconditions: none.
// postconditions: a copy of the Comedy item is created.
// -------------------------------------------------------------------
Comedy::Comedy(const Comedy& target) {
	this->directorName = target.getDirector();
	this->title = target.getTitle();
	this->year = target.getYear();
}


// -------------------------------~Comedy------------------------------
// Comedy: frees all (static) alloc'd memory by engaging the right
//		   sequence of destructors -- from child to parent.
// preconditions: none.
// postconditions: all (static) memory de-alloc'd.
// -------------------------------------------------------------------
Comedy:: ~Comedy() {
}


// -------------------------------displayItem-----------------------------
// display: outputs Comedy details. 
// preconditions: none.
// postconditions: Comedy details output to console.
//				   Comedy remains unchanged.
// -------------------------------------------------------------------
void Comedy::displayItem() const {
	cout << this->CATEGORY << ", " << this->itemCount << ", " << this->directorName << ", " << title << ", " << year << endl;
}


// ---------------------------displayTransaction-------------------------
// displayTransaction: outputs Comedy details for the command 'H'
// preconditions: none.
// postconditions: Comedy details output to console.
//				   Comedy remains unchanged.
// -------------------------------------------------------------------
void Comedy::displayTransaction() const {
	cout << this->CATEGORY << ", " << this->directorName << ", " << title << ", " << year << endl;
}


// -----------------------------operator==----------------------------
// operator==: determines if both items are identical, based on 
//	     	   attributes common to all Movie genres.
// preconditions: none.
// postconditions: true if identical, otherwise false.
// -------------------------------------------------------------------
bool Comedy:: operator==(const Media& target) {
	const Comedy& TargetComedy = static_cast<const Comedy&>(target);
	return (title == TargetComedy.getTitle() && year == TargetComedy.getYear());
}


// -----------------------------operator<----------------------------
// operator<: compares this Comedy object to check if it precedes the
//			  other.
// preconditions: none.
// postconditions: true if preceding, otherwise false.
// -------------------------------------------------------------------
bool Comedy:: operator<(const Media& target) {
	const Comedy& TargetComedy = static_cast<const Comedy&>(target);

	if (title == TargetComedy.getTitle()) {
		if (year < TargetComedy.getYear()) {
			return true;
		}
		return false;
	}
	else if (title < TargetComedy.getTitle()) {
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
bool Comedy:: operator>(const Media& target) {
	const Comedy& TargetComedy = static_cast<const Comedy&>(target);
    
	if (title == TargetComedy.getTitle()) {
		if (year > TargetComedy.getYear()) {
			return true;
		}
		return false;
	}
	else if (title > TargetComedy.getTitle()) {
		return true;
	}
	return false;
}