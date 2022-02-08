#include "Media.h"

// --------------------------------Media------------------------------
// Media: creates a Media object with specified stock and format.
// preconditions: format non-empty string, e.g. "DVD"
//				  stock >= 0
// postconditions: specified Media item created.
// -------------------------------------------------------------------
Media::Media() {
	genreName = ' ';
	directorName = " ";
	title = " ";
	year = 0;
	itemCount = -1;     // amount available for checkout
	string format = "";	// DVD, VHS, Book, Magazine, etc.
}


// --------------------------------Media------------------------------
// Media: creates a copy of the Media item.
// preconditions: none.
// postconditions: a copy of the Media is created.
// -------------------------------------------------------------------
Media::Media(const Media& target) {
	this->directorName = target.getDirector();
	this->title = target.getTitle();
	this->year = target.getYear();
	this->itemCount = target.itemCount;
	this->format = target.format;
}

// -------------------------------~Media------------------------------
// ~Media: destructs the Media and frees any assoc. memory.
// preconditions: none.
// postconditions: any assoc. memory is freed, object inaccessible.
// -------------------------------------------------------------------
Media::~Media() {
}


// ------------------------------getFormat----------------------------
// getFormat: obtains format, e.g. "DVD", "VHS", etc.
// preconditions: none.
// postconditions: format is returned.
// -------------------------------------------------------------------
string Media::getFormat() const {
	return format;
}


char Media::getGenre() const {
	return genreName;
}

// -----------------------------getDirector---------------------------
// getDirector: obtains the director.
// preconditions: none.
// postconditions: director is returned.
// -------------------------------------------------------------------
string Media::getDirector() const {
	return directorName;
}


// ------------------------------getTitle-----------------------------	
// getTitle: obtains the title.
// preconditions: none.
// postconditions: title is returned.
// -------------------------------------------------------------------
string Media::getTitle() const {
	return title;
}


// ------------------------------getYear-----------------------------
// getYear: obtains the year.
// preconditions: none.
// postconditions: year is returned.
// -------------------------------------------------------------------
int Media::getYear() const {
	return year;
}


// ------------------------------getCount-----------------------------
// getCount: obtains stock itemCount available for check out.
// preconditions: none.
// postconditions: stock is returned.
// -------------------------------------------------------------------
int Media::getCount() const {
	return itemCount;
}


// ------------------------------setFormat----------------------------
// getFormat: Change the format, e.g. "DVD", "VHS", etc.
// preconditions: format isn't empty string.
// postconditions: THe format is set up for thsi media item.
// -------------------------------------------------------------------
void Media::setFormat(string format) {
	this->format = format;
}


// ------------------------------setGenre----------------------------
// setGenre: Change the genre e.g. "C", "F", "D"
// preconditions: Only "C","F" or "D" are allowed 
// postconditions: The genre is set up for this media item 
// -------------------------------------------------------------------
void Media::setGenre(char genre) {
	this->genreName = genre;
}


// -----------------------------setDirector---------------------------
// setDirector: Change the name of director
// preconditions: Name isn't empty string 
// postconditions: The name of director is set up for this media item 
// -------------------------------------------------------------------
void Media::setDirector(string Name) {
	directorName = Name;
}


// ------------------------------setTitle-----------------------------
// setTitle: Change the name of title.
// preconditions: title isn't empty string 
// postconditions: The name of title is set up for this media item 
// -------------------------------------------------------------------
void Media::setTitle(string title) {
	this->title = title;
}


// -------------------------setYear-----------------------------------
// setYear: Change the year movie created  
// preconditions: year >= 1900 && year <= 2500
// postconditions: The year is set up for this media item
// -------------------------------------------------------------------
void Media::setYear(int year) {
	this->year = year;
}


// -------------------------setBaseCount------------------------------
// setBaseCount: Set up the base stock count for each media item
// preconditions: count >= 0 && count <= 10000
// postconditions: itemCount = count;
// -------------------------------------------------------------------
void Media::setBaseCount(int itemCount) {
	this->itemCount = itemCount;
}


// ----------------------------increaseCount--------------------------
// increaseCount: increments stock itemCount, typically after a return.
// preconditions: none.
// postconditions: stock = stock + 1.
// -------------------------------------------------------------------
void Media::increaseCount() {
	itemCount += 1;
}


// ----------------------------decreaseCount--------------------------
// decreaseCount: decrements stock itemCount, typically after a borrow.
// preconditions: none.
// postconditions: stock = stock - 1.
// -------------------------------------------------------------------
void Media::decreaseCount() {
	itemCount -= 1;
}
