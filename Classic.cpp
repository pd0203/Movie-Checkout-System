#include "Classic.h"


// -------------------------------Classic-----------------------------
// Classic: creates a specified Classic item.
// preconditions: strings nonempty.
//				  1 <= month <= 12
// postconditions: specified Classic is created.
// -------------------------------------------------------------------
Classic::Classic(string actN, int mo) {
	CATEGORY = "Classic";	// genre
	this->setGenre('C');
	this->actorName = actN;
	this->month = mo; 
}


// -------------------------------Classic-----------------------------
// Classic: creates a copy of the Classic.
// preconditions: none.
// postconditions: a copy of the Classic is created.
// -------------------------------------------------------------------
Classic::Classic(const Classic& target) {
	this->CATEGORY = target.CATEGORY;
	this->actorName = target.getActorName();
	this->title = target.getTitle();
	this->directorName = target.getDirector();
	this->month = target.getMonth();
	this->year = target.getYear();
}


// ------------------------------~Classic-----------------------------
// ~Classic: frees all (static) alloc'd memory by engaging the right
//		     sequence of destructors -- from child to parent.
// preconditions: none.
// postconditions: all (static) memory de-alloc'd.
// -------------------------------------------------------------------
Classic:: ~Classic() {

}


// ----------------------------getActorName--------------------------
// getActorFName: obtains the lead actor's name.
// preconditions: none.
// postconditions: lead actor's name returned.
// -------------------------------------------------------------------
string Classic::getActorName() const {
	return this->actorName;
}


// ------------------------------getMonth-----------------------------
// getMonth: obtains the release year.
// preconditions: none.
// postconditions: release year is returned.
// -------------------------------------------------------------------
int Classic::getMonth() const {
	return this->month;
}


// ------------------------------displayItem-----------------------------
// display: outputs Classic details.
// preconditions: none.
// postconditions: details output to console. 
//                 Classic remains unchanged.
// -------------------------------------------------------------------
void Classic::displayItem() const {
	cout << this->CATEGORY << ", " << this->itemCount << ", " << this->directorName << ", " << this->title << ", " << actorName << " " << month << " " << this->year << endl;
}


// ------------------------displayTransaction-------------------------
// display: outputs Classic details for the command 'H'.
// preconditions: none.
// postconditions: details output to console. 
//                 Classic remains unchanged.
// -------------------------------------------------------------------
void Classic::displayTransaction() const {
	cout << this->CATEGORY << ", " << this->directorName << ", " << this->title << ", " << actorName << " " << month << " " << this->year << endl;
}


// -----------------------------operator==----------------------------
// operator==: determines if both items are identical, based on 
//			   attributes common to all Movie genres (unless a
//			   comparison is made with another Classic, which includes
//			   the additional attribs).
// preconditions: none.
// postconditions: true if identical, otherwise false.
// -------------------------------------------------------------------
bool Classic:: operator==(const Media& target) {
	const Classic& TargetClassic = static_cast<const Classic&>(target);
	return (month == TargetClassic.getMonth() && year == TargetClassic.getYear()
		    && actorName == TargetClassic.getActorName());
}


// -----------------------------operator<----------------------------
// operator<: compares this Classic object to check if it precedes 
//			  the other.
// preconditions: none.
// postconditions: true if preceding, otherwise false.
// -------------------------------------------------------------------
bool Classic:: operator<(const Media& target) {
	const Classic& TargetClassic = static_cast<const Classic&>(target);
	
	if (month == TargetClassic.getMonth()) {
		if (year == TargetClassic.getYear()) {
			if (actorName < TargetClassic.getActorName()) {
				return true;
			}
			return false; 
		}
		else if (year < TargetClassic.getYear()) {
			return true;
		}
		return false; 
	}
	else if (month < TargetClassic.getMonth()) {
		return true;
	}
	return false;
}

// -----------------------------operator>----------------------------
// operator<: compares this Classic object to check if it follows 
//			  the other.
// preconditions: none.
// postconditions: true if following, otherwise false.
// -------------------------------------------------------------------
bool Classic:: operator>(const Media& target) {
	const Classic& TargetClassic = static_cast<const Classic&>(target);

	if (month == TargetClassic.getMonth()) {
		if (year == TargetClassic.getYear()) {
			if (actorName > TargetClassic.getActorName()) {
				return true;
			}
			return false;
		}
		else if (year > TargetClassic.getYear()) {
			return true;
		}
		return false;
	}
	else if (month > TargetClassic.getMonth()) {
		return true;
	}
	return false;
}