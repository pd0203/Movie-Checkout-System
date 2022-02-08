 // -----------------------------------media.h---------------------------------
// Hyosang Park CSS343 
// ---------------------------------------------------------------------------
// Describes the abstract ADT Media such that any kind of item can be held
// in the store. All Media items have stock counts and formats (DVD, etc).
// Derived classes of Media simply add any additional attributes that pertain
// to them. They are all equipped with operations to maintain the stocks,
// display the details, and make comparisons between one another.
//
// This class is an interface for any type of Media in a store. It serves as 
// a guide for being able to keep track of the inventory of a Media and what 
// format that media is. There are methods to checkout, return, and compare 
// Media.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create a Media item
//		- copy an exist Media item
//		- destruct a Media item
//		- retrieve the format
//		- retrieve stock counts
//		- increment/decrement stock counts
//		- display details
//		- comparison operators (==, <)
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; 
class Media {
public:
	// --------------------------------Media------------------------------
	// Media: creates a Media object with specified stock and format.
	// preconditions: format non-empty string, e.g. "DVD"
	//				  stock >= 0
	// postconditions: specified Media item created.
	// -------------------------------------------------------------------
	Media();


	// --------------------------------Media------------------------------
	// Media: creates a copy of the Media item.
	// preconditions: none.
	// postconditions: a copy of the Media is created.
	// -------------------------------------------------------------------
	Media(const Media& target);


	// -------------------------------~Media------------------------------
	// ~Media: destructs the Media and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// -------------------------------------------------------------------
	virtual ~Media();


	// ------------------------------getFormat----------------------------
	// getFormat: obtains format, e.g. "DVD", "VHS", etc.
	// preconditions: none.
	// postconditions: format is returned.
	// -------------------------------------------------------------------
	string getFormat() const;


	// ------------------------------getGenre----------------------------
	// getFormat: obtains Genre, e.g. "C","F" or "D"
	// preconditions: none.
	// postconditions: The genre of media item is returned.
	// -------------------------------------------------------------------
	char getGenre() const;


	// -----------------------------getDirector---------------------------
	// getDirector: obtains the director.
	// preconditions: none.
	// postconditions: director is returned.
	// -------------------------------------------------------------------
	string getDirector() const;


	// ------------------------------getTitle-----------------------------
	// getTitle: obtains the title.
	// preconditions: none.
	// postconditions: title is returned.
	// -------------------------------------------------------------------
	string getTitle() const;


	// ------------------------------getYear-----------------------------
	// getYear: obtains the year.
	// preconditions: none.
	// postconditions: year is returned.
	// -------------------------------------------------------------------
	int getYear() const;


	// ------------------------------getCount-----------------------------
	// getCount: obtains stock count available for check out.
	// preconditions: none.
	// postconditions: stock is returned.
	// -------------------------------------------------------------------
	int getCount() const;


	// ------------------------------setFormat----------------------------
	// getFormat: Change the format, e.g. "DVD", "VHS", etc.
	// preconditions: format isn't empty string.
	// postconditions: THe format is set up for thsi media item.
	// -------------------------------------------------------------------
	void setFormat(string format);


	// ------------------------------setGenre----------------------------
	// setGenre: Change the genre e.g. "C", "F", "D"
	// preconditions: Only "C","F" or "D" are allowed 
	// postconditions: The genre is set up for this media item 
	// -------------------------------------------------------------------
	void setGenre(char genre);


	// -----------------------------setDirector---------------------------
	// setDirector: Change the name of director
	// preconditions: Name isn't empty string 
	// postconditions: The name of director is set up for this media item 
	// -------------------------------------------------------------------
	void setDirector(string Name);


	// ------------------------------setTitle-----------------------------
	// setTitle: Change the name of title.
	// preconditions: title isn't empty string 
	// postconditions: The name of title is set up for this media item 
	// -------------------------------------------------------------------
	void setTitle(string title);


	// -------------------------setYear-----------------------------------
	// setYear: Change the year movie created  
	// preconditions: year >= 1900 && year <= 2500
	// postconditions: The year is set up for this media item
	// -------------------------------------------------------------------
	void setYear(int year);


	// -------------------------setBaseCount------------------------------
	// setBaseCount: Change the base stock count for each media item
	// preconditions: count >= 0 && count <= 10000
	// postconditions: Base stock count is set up for this media item 
	// -------------------------------------------------------------------
	void setBaseCount(int count);


	// ----------------------------increaseCount--------------------------
	// increaseCount: increments stock count, typically after a return.
	// preconditions: none.
	// postconditions: stock = stock + 1.
	// -------------------------------------------------------------------
	void increaseCount();


	// ----------------------------decreaseCount--------------------------
	// decreaseCount: decrements stock count, typically after a borrow.
	// preconditions: none.
	// postconditions: stock = stock - 1.
	// -------------------------------------------------------------------
	void decreaseCount();


	// -------------------------------displayItem-----------------------------
	// display: outputs Media details, pertaining to particular style.
	// preconditions: none.
	// postconditions: Media details output to console.
	// -------------------------------------------------------------------
	virtual void displayItem() const = 0;


	// -------------------------------displayItem-----------------------------
	// display: outputs Media details, pertaining to particular style.
	// preconditions: none.
	// postconditions: Media details output to console.
	// -------------------------------------------------------------------
	virtual void displayTransaction() const = 0;

	// ------------------------------operator==---------------------------
	// operator==: determines if both Media items are identical.
	// preconditions: none.
	// postconditions: true if identical, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator==(const Media& target) = 0;


	// ------------------------------operator<---------------------------
	// operator<: determines if this Media precedes the other Media.
	// preconditions: none.
	// postconditions: true if preceding, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator<(const Media& target) = 0;

	// ------------------------------operator>---------------------------
	// operator>: determines if this Media follows the other Media.
	// preconditions: none.
	// postconditions: true if following, otherwise false.
	// -------------------------------------------------------------------
	virtual bool operator>(const Media& target) = 0;


protected:
	char genreName;
	string directorName;
	string title;		// film title
	int year;			// year of release
	int month;          // month of release
	int itemCount;		// amount available for checkout
	string format;	// DVD, VHS, Book, Magazine, etc. 
};

#endif 