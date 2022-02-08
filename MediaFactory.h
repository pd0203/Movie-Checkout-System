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

#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H

#include <sstream> 
#include <vector>
#include "Media.h" 
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h" 

class MediaFactory {

public:
	// ---------------------------createMedia-------------------------------
	// createMedia: outputs created media object based on the description of 
	//              single media item in text file
	// preconditions:  file is properly formatted and movieGenre is one of 
	//                 'C' or 'F' or 'D'
	// postconditions: Media object fulfilling the requirements is created
	//                 and returned 
	// -------------------------------------------------------------------
	Media* createMedia(istream& file, char& movieGenre);

private:
	// ---------------------------createComedy-------------------------------
	// createComedy: outputs Media pointer, which points to created new 
	//               comedy object as a parameter
	// preconditions:  file is properly formatted 
	// postconditions: comedy object fulfilling the requirements is created
	//                 and returned
	// -------------------------------------------------------------------
	void createComedy(istream& file, Media*& movieNode);


	// ---------------------------createClassic-------------------------------
	// createClassic: outputs Media pointer, which points to created new 
	//                classic object as a parameter
	// preconditions:  file is properly formatted
	// postconditions: classic object fulfilling the requirements is created
	//                 and returned
	// -------------------------------------------------------------------
	void createClassic(istream& file, Media*& movieNode);


	// ---------------------------createDrama-------------------------------
	// createDrama: outputs Media pointer, which points to created new 
	//              drama object as a parameter
	// preconditions:  file is properly formatted
	// postconditions: drama object fulfilling the requirements is created
	//                 and returned
	// -------------------------------------------------------------------
	void createDrama(istream& file, Media*& movieNode);
};
#endif 

