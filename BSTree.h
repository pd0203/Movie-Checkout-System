// --------------------------------BSTree.h----------------------------------
// Hyosang Park CSS 343 A
// ---------------------------------------------------------------------------
// Describes the ADT BSTree such that a binary search tree can maintain
// an inventory of Media items for efficient retrieval by a client. There are 
// only single instances of each Media item, stock counts are recorded 
// internally.
// ---------------------------------------------------------------------------
// Functionality includes:
//		- create an empty BSTree
//      - copy a BSTree
//      - destruct a BSTree
//      - insert a new Media item + associated # copies
//      - delete a Media item
//      - retrieve a Media item
//      - display the contents of the BSTree (inorder traversal)
#ifndef BSTREE_H
#define BSTREE_H
#include "Media.h"

class BSTree {
public:
	// ------------------------------BSTree------------------------------
	// BSTree: creates an empty tree.
	// preconditions: none.
	// postconditions: an empty tree is created.
	// -------------------------------------------------------------------
	BSTree() {
		root = nullptr;
	}


	// ------------------------------BSTree------------------------------
	// BSTree: creates an identical deep copy of the other tree.
	// preconditions: none.
	// postconditions: a deep copy of the other tree is created.
	// -------------------------------------------------------------------
	BSTree(const BSTree& target) {
		copyHelper(root, target.root);
	}


	// -----------------------------~BSTree------------------------------
	// ~BSTree: destructs the BSTree and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// -------------------------------------------------------------------
	~BSTree() {
		 makeEmpty();
	}

    // ------------------------------insert------------------------------
	// insert: adds a new Media into the appropriate position within
	//         the tree.
	// preconditions: none.
	// postconditions: newly introduced Media inserted in appropriate
	//                 position.
	// -------------------------------------------------------------------
	bool insert(Media* target) {
		if (target == NULL) {
			return false;
		}
		return insertHelper(target, root);
	}


	// ------------------------------remove------------------------------
	// remove: Deletes the Media in appropriate position of tree 
	// preconditions: Media item, "target," is not NULL
	// postconditions: Media item found in the tree is deleted
	// -------------------------------------------------------------------
	bool remove(Media* target) {
		if (target == NULL) {
			return false;
		}
		return removeHelper(target, root);
	}

	// -----------------------------retrieve------------------------------
	// retrieve: obtains the ptr that points to Media with matching
	//           Media.
	// preconditions: none.
	// postconditions: Media pointer, link, points to located data, 
	//                 if match. Returns true if found, false otherwise.
	// -------------------------------------------------------------------
	bool retrieve(Media* target, Media*& link) const {
		return retrieveHelper(root, target, link);
	}


	// -----------------------------makeEmpty------------------------------
	// makeEmpty: destructs the BSTree and frees any assoc. memory.
	// preconditions: none.
	// postconditions: any assoc. memory is freed, object inaccessible.
	// -------------------------------------------------------------------
	void makeEmpty() {
		makeEmptyHelper(this->root);
	}


	// -------------------------displayInOrder------------------------------
	// displayInOrder: display all of Media items info in order.
	// preconditions: none.
	// postconditions: specific information of any Media items stored in the 
	//                 tree are displayed in order
	// -------------------------------------------------------------------
	void displayInOrder() const {
		displayInOrderHelper(root);
	}

private:
	struct Node {
		Media* item;      // Refering to comparable key in Binary Search Tree
		Node* left;
		Node* right;
	};

	Node* root;           // Root of Binary Search Tree


	/*
	Helper method of copy constructor
	*/
	void copyHelper(Node*& rootPtr, Node* copyRoot) {
		if (copyRoot != nullptr) {
			rootPtr = new Node;
			rootPtr->item = copyRoot->item;
			rootPtr->left = nullptr;
			rootPtr->right = nullptr;
			copyHelper(rootPtr->left, copyRoot->left);
			copyHelper(rootPtr->right, copyRoot->right);
		}
		else {
			rootPtr = nullptr;
		}
	}


	/*
	Helper method of insert()
	*/
	bool insertHelper(Media* target, Node*& rootPtr) {
		if (rootPtr == nullptr) {
			rootPtr = new Node;
			rootPtr->item = target;
			rootPtr->left = nullptr;
			rootPtr->right = nullptr;
		}
		else {
			if (*target < *rootPtr->item) {
				insertHelper(target, rootPtr->left);
			}
			else if (*target > *rootPtr->item) {
				insertHelper(target, rootPtr->right);
			}
			else {
				return false;
			}
		}
		return true;
	}


	/*
	Helper method of remove()
	*/
	bool removeHelper(Media* target, Node*& rootPtr) {
		if (root == nullptr) {
			return false;
		}
		else if (target < rootPtr->item) {
			removeHelper(target, rootPtr->left);
		}
		else if (target > rootPtr->item) {
			removeHelper(target, rootPtr->right);
		}
		else {

			//case 1 : No Child node
			if (rootPtr->left == nullptr && rootPtr->right == nullptr) {
				delete rootPtr;
				rootPtr = nullptr;
			}

			//case 2 : Only one Child node(Only leftside or rightside) 
			else if (rootPtr->right == nullptr && rootPtr->left != nullptr) {
				Node* temp = rootPtr;
				rootPtr = rootPtr->left;
				delete temp;
				temp = nullptr;
			}

			else if (rootPtr->left == nullptr && rootPtr->right != nullptr) {
				Node* temp = rootPtr;
				rootPtr = rootPtr->right;
				delete temp;
				temp = nullptr;
			}

			//case 3 : Two Child node 
			else {
				Node* temp = rootPtr->right;
				while (temp->left != nullptr) {
					temp = temp->left;
				}
				rootPtr->item = temp->item;
				removeHelper(temp->item, rootPtr->right);
			}
		}
	}


	/*
	Helper method of retrieve() 
	*/
	bool BSTree::retrieveHelper(Node* rootPtr, Media* target, Media*& link) const {
		if (rootPtr == nullptr) {
			return false;
		}
		if (*target < *rootPtr->item) {
			retrieveHelper(rootPtr->left, target, link);
		}
		else if (*target > *rootPtr->item) {
			retrieveHelper(rootPtr->right, target, link);
		}
		else {
			link = rootPtr->item;
			return true;
		}
	}


	/*
	Helper method of makeEmpty() 
	*/
	void makeEmptyHelper(Node*& rootPtr) {
		if (rootPtr != nullptr) {
			makeEmptyHelper(rootPtr->left);
			makeEmptyHelper(rootPtr->right);
			delete rootPtr->item;
			rootPtr->item = NULL;
			delete rootPtr;
			rootPtr = nullptr;
		}
	}

	/*
	Helper method of displayInOrder() 
	*/
	void displayInOrderHelper(Node* rootPtr) const {
		if (rootPtr != nullptr) {
			displayInOrderHelper(rootPtr->left);
			rootPtr->item->displayItem();
			displayInOrderHelper(rootPtr->right);
		}
	}
};

#endif 