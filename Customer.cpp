#include "Customer.h"

// ------------------------------Customer-----------------------------
// Customer: creates a unique Customer.
// preconditions: 0 <= id < 10,000, strings non-empty
// postconditions: specified Customer created.
// -------------------------------------------------------------------
Customer::Customer(int ID, string fName, string lName) {
	this->ID = ID;                      
	this->fName = fName;                 
	this->lName = lName;                
	history.reserve(20);   
}


// ------------------------------Customer-----------------------------
// Customer: creates a copy of the Customer.
// preconditions: none.
// postconditions: a copy of the other Customer is created.
// -------------------------------------------------------------------
Customer::Customer(const Customer& target) {
	this->ID = target.ID;
	this->fName = target.fName;
	this->lName = target.lName;

	for (int i = 0; i < target.history.size(); i++) {
		history[i] = target.history[i];
	}
}


// ------------------------------Customer-----------------------------
// ~Customer: destructs the Customer and frees any assoc. memory.
// preconditions: none.
// postconditions: any assoc. memory is freed, object inaccessible.
// -------------------------------------------------------------------
Customer::~Customer() {
}

/*
Accessor
getID()
Access to the data member and retrieve the ID of the customer
*/
int Customer::getID() const {
	return ID;
}

/*
Accessor
getFirst()
Access to the data member and retrieve the first name of the customer
*/
string Customer::getFirstName() const {
	return fName;
}

/*
Accessor
getLast()
Access to the data member and retrieve the last name of the customer
*/
string Customer::getLastName() const {
	return lName;
}


/*
display()
Display the information of customer's identification
*/
void Customer::display() const {
	cout << "[Customer info]: " << ID << " " << fName << " " << lName << endl;
}


/*
displayHistory()
Display all of the customer's transaction history with the customer's identification
*/
void Customer::transactionHistory() const {
	this->display();
	cout << "[History of Transaction - " << this->fName << " " << this->lName << "]" << endl; 
	for (int i = 0; i < history.size(); i++) {
		history[i].display();
	}
	cout << endl;
}


/*
addTransaction()
Add the Transaction parameter to the history vector
*/
void Customer::addTransaction(Transaction target) {
	history.push_back(target);
}


/*
operator==
This operator== checks whether two customers are exactly same or not by using
each customer’s id number, because every customer gets different id number.
*/
bool Customer:: operator==(const Customer& target) const {
	return (ID == target.ID && fName == target.fName && lName == target.lName);
}


/*
operator!=
This operator!= is exactly opposite version of operator==
*/
bool Customer:: operator!=(const Customer& target) const {
	return (ID != target.ID && fName != target.fName && lName != target.lName);
}