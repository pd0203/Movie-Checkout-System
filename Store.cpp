#include "Store.h"

// --------------------------------Store------------------------------
// Store: creates a named Store.
// preconditions: none.
// postconditions: a named Store is created.
// -------------------------------------------------------------------
Store::Store(string storeName) {
	name = storeName;
}

// -------------------------------~Store------------------------------
// ~Store: destructs the Store and frees any assoc. memory.
// preconditions: none.
// postconditions: any assoc. memory is freed, object inaccessible.
// -------------------------------------------------------------------
Store:: ~Store() {
}


// ----------------------------buildCustomers--------------------------
// buildCustomers: builds Customer hash table from file.
// preconditions: file is properly formatted, i.e. each line is
//				  #### fname lname
//				  given 4 digit IDs, the maximum allowed is 10,000.
// postconditions: customer hash table populated with all entries.
// -------------------------------------------------------------------
void Store::buildCustomers(istream& file) {
	if (file.fail()) {
		cerr << "Customers data file couldn't be found.." << endl;
		return;
	}
	while (!file.eof()) {
		   int ID;
		   string fName, lName;

		   file >> ID;
		   file >> fName;
		   file >> lName; 

		   Customer* guest = new Customer(ID, fName, lName);
		   customersTable.addData(ID, guest);
	}
}



// ----------------------------buildInventory--------------------------
// buildInventory: builds Media tree from file.
// preconditions: file is properly formatted, i.e. each line is
//				  X, ##, dfname dlname, title, . . . 
//				  genre, stock, director name, title, and more attribs
//				  comma delimited
// postconditions: BSTree populated with Media items.
// -------------------------------------------------------------------
void Store::buildInventory(istream& file) {
	if (file.fail()) {
		cerr << "Medias data file couldn't be found.." << endl;
		return;
	}
	while (!file.eof()) {
		char movieGenre = ' ';
		file >> movieGenre;
		Media* mediaItem = mediaFactory.createMedia(file, movieGenre);
		switch (movieGenre) {
		case 'F':
			comedyInventory.insert(mediaItem);
			break;
		case 'C':
			classicInventory.insert(mediaItem);
			break;
		case 'D':
			dramaInventory.insert(mediaItem);
			break;
		default: 
			file.ignore(256, '\n');
			break;
		}
	}
}


// --------------------------executeTransactions----------------------
// executeTransactions: process transactions from file and update
//						records as needed.
// preconditions: file is properly formatted, i.e. each line is one of
//				  X #### X X # #### fname lname
//				  X #### X X Title, ####
//				  X #### X X fname lname, title
//				  X ####
//				  X
// postconditions: records updated according to transactions.
// -------------------------------------------------------------------
void Store::buildCommands(istream& file) {
	if (file.fail()) {
		cerr << "Transactions data file couldn't be found.." << endl;
	}
	while (!file.eof()) {
		char transactionType;
		file >> transactionType; 
		switch (transactionType) {
		case 'I':
			commands.displayInventory(this->name, comedyInventory, dramaInventory, classicInventory);
			break;

		case 'H':
			commands.displayHistory(file, customersTable);
			break;

		case 'B':
			commands.borrowItem(file, customersTable, comedyInventory, dramaInventory, classicInventory);
			break;

		case 'R':
			commands.returnItem(file, customersTable, comedyInventory, dramaInventory, classicInventory);
			break;

		default:
			cerr << "Invalid type of Transaction => " << transactionType << endl;
			file.ignore(256, '\n');
			break;
		}
	}
}


// -------------------------------getName-----------------------------
// getName: obtains store name, if any.
// preconditions: none.
// postconditions: store name returned.
// -------------------------------------------------------------------
string Store::getName() const {
	return name;
}
