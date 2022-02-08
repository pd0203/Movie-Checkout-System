// ----------------------------------MediaSearch.h-------------------------------
// Hyosang Park CSS343
// ---------------------------------------------------------------------------
// Describes the ADT MediaSearch such that it collects the data from the text
// file and finds the specific media object corresponding to that data from the 
// proper binary search tree. If it succeeds to find the appropriate media object, 
// it will be returned. 
// ---------------------------------------------------------------------------
// Functionality includes:
//      -  Find a Media object from the proper BSTree and return it 
//      -  Find a Comedy object from the comedy BSTree and return it
//      -  Find a Classic object from the classic BSTree and return it
//      -  Find a Drama object from the drama BSTree and return it

#ifndef MEDIASEARCH_H
#define MEDIASEARCH_H

#include <sstream> 
#include <vector> 
#include "BSTree.h" 
#include "Media.h" 
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h" 

class MediaSearch {

public:
	// ---------------------------findMedia-------------------------------
	// findMedia: outputs media object searching from corresponding BSTree
	// preconditions:  file is properly formatted and Binary Search Trees 
	//                 are not empty
	// postconditions: Media object searched in proper BSTree as meeting the
	//                 condition is returned 
	// -------------------------------------------------------------------
	Media* findMedia(istream& file, BSTree& comedy, BSTree& drama, BSTree& classic);

private: 	
	// ---------------------------findComedy-------------------------------
	// findComedy: outputs comedy object searching comedy BSTree
	// preconditions:  file is properly formatted and comedy Binary Search 
	//                 Tree is not empty
	// postconditions: Comedy object searched in comedy BSTree as meeting the
	//                 condition is returned 
	// -------------------------------------------------------------------
	Media* findComedy(istream& stream, BSTree& comedy);


	// ---------------------------findClassic-------------------------------
	// findClassic: outputs classic object searching classic BSTree
	// preconditions:  file is properly formatted and classic Binary Search 
	//                 Tree is not empty
	// postconditions: classic object searched in classic BSTree as meeting the
	//                 condition is returned 
	// -------------------------------------------------------------------
	Media* findClassic(istream& stream, BSTree& classic);


	// ---------------------------findDrama-------------------------------
	// findDrama: outputs drama object searching drama BSTree
	// preconditions:  file is properly formatted and drama Binary Search 
	//                 Tree is not empty
	// postconditions: drama object searched in drama BSTree as meeting the
	//                 condition is returned 
	// -------------------------------------------------------------------
	Media* findDrama(istream& stream, BSTree& drama);
};

#endif 