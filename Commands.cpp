#include "Commands.h" 

// ------------------------------borrowItem---------------------------
// borrowItem: applies a borrow transaction for a particular customer
//			   + Media item.
// preconditions: customer exists, 0 < id < 10,000
//			      media item exists.
//                appropriate number of Media items 0 < item <= 10
// postconditions: customer transaction history + item stock updated.
// -------------------------------------------------------------------
bool Commands::borrowItem(istream& file, HashTable<Customer>& customers, BSTree& comedy, BSTree& drama, BSTree& classic) {
	int ID;
	file >> ID;
	Customer* guest = customers.getData(ID);
	if (guest != nullptr) {
		Media* item = mediaSearch.findMedia(file, comedy, drama, classic);
		if (item != nullptr) {
			if (item->getCount() > 0) {
				item->decreaseCount();
				Transaction history('B', item);
				guest->addTransaction(history);
				return true;
			}
			cerr << "Media item can't go below 0..." << endl;
			return false;
		}
		return false;
	}
	cerr << "Customer ID: " << ID << " doesn't exist in customer data storage.." << endl;
	return false;
}

// ------------------------------returnItem---------------------------
// returnItem: applies a return transaction for a particular customer
//			   + Media item.
// preconditions: customer exists, 0 < id < 10,000
//			      media item exists.
//                appropriate number of Media items 0 <= item < 10 
// postconditions: customer transaction history + item stock updated.
// -------------------------------------------------------------------
bool Commands::returnItem(istream& file, HashTable<Customer>& customers, BSTree& comedy, BSTree& drama, BSTree& classic) {
	int ID;
	file >> ID;
	Customer* guest = customers.getData(ID);
	if (guest != nullptr) {
		Media* item = mediaSearch.findMedia(file, comedy, drama, classic);
		if (item != nullptr) {
			if (item->getCount() < 10) {
				item->increaseCount();
				Transaction history('B', item);
				guest->addTransaction(history);
				return true;
			}
			cerr << "Media item can't go over 10..." << endl;
			return false;
		}
		return false;
	}
	cerr << "Customer ID: " << ID << " doesn't exist in customer data storage.." << endl;
	return false;
}


// ----------------------------displayHistory-------------------------
// displayHistory: outputs the transaction history for a particular
//				   customer.
// preconditions: customer exists, 0 < id < 10,000
// postconditions: customer transaction history, if any, is output.
// -------------------------------------------------------------------
bool Commands::displayHistory(istream& file, HashTable<Customer>& customers) {
	int ID;
	file >> ID;
	Customer* guest = customers.getData(ID);
	if (guest != nullptr) {
		guest->transactionHistory();
		return true;
	}
	return false;
}


// ---------------------------displayInventory------------------------
// displayInventory: outputs all Media items.
// preconditions: none.
// postconditions: all Media items, if any, are output as they
//				   appeared in input.
// -------------------------------------------------------------------
void Commands::displayInventory(string storeName, BSTree& comedy, BSTree& drama, BSTree& classic) {
	cout << endl << "**********" << storeName << "'s Inventory**********" << endl;
	comedy.displayInOrder();
	drama.displayInOrder();
	classic.displayInOrder();
	cout << endl;
}