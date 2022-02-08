#include "Transaction.h"

/*
Constructor
*/
Transaction::Transaction(char type, Media* item) {
	this->type = type;
	this->item = item;
}

/*
Copy Constructor
Set the every value of data member(type, *item) equally to the every value of data member in the parameter object
*/
Transaction::Transaction(const Transaction& target) {
	type = target.type;
	item = target.item;
}

/*
Destructor
Delete the Media pointer
*/
Transaction::~Transaction() {
}

/*
Accessor
getType()
Access to the data member and retrieve the type of transaction
*/
char Transaction::getType() const {
	return type;
}

/*
Accessor
getItem()
Access to the data member and retrieve the media item of transaction
*/
Media* Transaction::getItem() const {
	return item;
}

/*
display()
Display the Transaction type and media item information
*/
void Transaction::display() const {
	cout << type << " ";
	item->displayTransaction();
}

