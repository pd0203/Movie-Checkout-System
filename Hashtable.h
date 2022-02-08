// --------------------------------HashTable.h----------------------------------
// Hyosang Park CSS 343 A
// ---------------------------------------------------------------------------
// Describes the ADT HashTable such that Chanining Hash Table using separate
// chaining with linked lists algorithm to resolve the problems of collision.
// So, this is Hash Table, but each element of Hash Table has a chain, which 
// is implemented with a linked list. 
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create an empty HashTable
//      - copy a HashTable
//      - destruct a HashTable 
//      - insert a new T(customer) object 
//      - delete a T(customer) object
//      - retrieve a T(customer) object

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename T>
class HashTable {
public:
	// -----------------------------HashTable------------------------------
	// HashTable: creates an empty hash table.
	// preconditions: none.
	// postconditions: an empty HashTable is created.
	// --------------------------------------------------------------------
	HashTable() {
		for (int i = 0; i < maxSize; i++) {
			HTable[i] = nullptr;
		}
	}


	// -----------------------------~HashTable------------------------------
	// ~HashTable: destructs the HashTable and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// ---------------------------------------------------------------------
	~HashTable() {
		// Access to every index of HashTable and also all of chains in
		// the chain linked list
		for (int i = 0; i < maxSize; i++) {
			chain* p = HTable[i];
			chain* current = nullptr;
			while (p) {
				current = p;
				p = p->next;
				// Deallocate the data and chain
				delete current->data;
				current->data = nullptr;
				delete current;
				current = nullptr; 
			}
		}
	} 


	// -----------------------------addData------------------------------
	// addData: adds a new data into the appropriate position within
	//         the HashTable.
	// preconditions: none.
	// postconditions: newly introduced Data inserted in appropriate
	//                 position.
	// ------------------------------------------------------------------
	bool addData(int key, T* target) {
		// Create a new Data object 
		chain *newChain = new chain;
		newChain->data = target;
		newChain->key = key;
		newChain->next = nullptr;
		int hashKey = getHashKey(key);

		if (HTable[hashKey] == nullptr) {
			HTable[hashKey] = newChain;
			return true;
		}
		else {
			newChain->next = HTable[hashKey]; 
			HTable[hashKey] = newChain; 
			return true;
		}
	}


	// -----------------------------deleteData-----------------------------
	// deleteData: deletes the data in appropriate position of 
	//             HashTable
	// preconditions: key >= 0 && key < 10000
	// postconditions: data found in the HashTable is deleted
	// --------------------------------------------------------------------
	bool deleteData(int key) {
		int hashKey = getHashKey(key);

		if (HTable[hashKey] == nullptr) {
			return false;
		}

		else {
			chain *target;
			if (HTable[hashKey]->key = key) {
				target = HTable[hashKey];
				HTable[hashKey] = HTable[hashKey]->next;

				delete target;
				target = nullptr;
				return true;
			}
			else {
				chain *current = HTable[hashKey];
				chain *nextChain = HTable[hashKey]->next;
				while (nextChain != nullptr) {
					if (nextChain->key = key) {
						current->next = nextChain->next;
						target = nextChain;

						delete target;
						target = nullptr;
						return true;
					}
					current = nextChain;
					nextChain = nextChain->next;
				}
				return false;
			}
		}
	}


	// -----------------------------getData------------------------------
	// getData: obtains the ptr that points to data with matching
	//          the key value.
	// preconditions: key >= 0 && key < 10000
	// postconditions: return data pointer, points to located data, 
	//                 if match with key, nullptr otherwise.
	// -------------------------------------------------------------------
	T* getData(int key) const {
		if (key > 0 && key < 10000) {
			int hashKey = getHashKey(key);
			chain* current = HTable[hashKey];
			while (current != nullptr) {
				if (current->key == key) {
					return current->data;
				}
				current = current->next;
			}
		}
		return nullptr;
	}

private:
	const int maxSize = 50;       // Maximum size of HashTable allowed 
	struct chain {
		T* data;                  
		int key;
		chain *next;
	};
	chain* HTable[50];


	// --------------------------getHashKey------------------------------
	// getHashKey: obtains the hash key that matches with the key value.
	// preconditions: key >= 0 && key < 10000
	// postconditions: return hash key corresponding to the key value
	// -------------------------------------------------------------------
	int getHashKey(int key) const {
		return (key % maxSize);
	}
};

#endif 