#include "MediaSearch.h"

// ---------------------------findMedia-------------------------------
// findMedia: outputs media object searching from corresponding BSTree
// preconditions:  file is properly formatted and Binary Search Trees 
//                 are not empty
// postconditions: Media object searched in proper BSTree as meeting the
//                 condition is returned 
// -------------------------------------------------------------------
Media* MediaSearch::findMedia(istream& file, BSTree& comedy, BSTree& drama, BSTree& classic) {
	char mediaType, movieType;
	file >> mediaType;
	if (mediaType != 'D') {
		cerr << "Invalid type of Media item => " << mediaType << endl;
		file.ignore(256, '\n');
		return nullptr;
	}
	file >> movieType;
	switch (movieType) {
	case 'F':
		return findComedy(file, comedy);
		break;

	case 'C':
		return findClassic(file, classic);
		break;

	case 'D':
		return findDrama(file, drama);
		break;

	default:
		cerr << "Invalid type of Movie type: " << movieType << endl;
		string temp;
		getline(file, temp);
		return nullptr;
	}
}


// ---------------------------findComedy-------------------------------
// findComedy: outputs comedy object searching comedy BSTree
// preconditions:  file is properly formatted and comedy Binary Search 
//                 Tree is not empty
// postconditions: Comedy object searched in comedy BSTree as meeting the
//                 condition is returned 
// -------------------------------------------------------------------
Media* MediaSearch::findComedy(istream& stream, BSTree& comedy) {
	string movieName, sentence, token;
	int year;
	getline(stream, sentence);
	stringstream ss(sentence);
	vector<string> comedyData;
	int commaCount = 0;
	while (getline(ss, token, ',') && commaCount != 2) {
		if (token != "") {
			comedyData.push_back(token);
			commaCount++;
		}
	}
	movieName = comedyData[0];
	year = stoi(comedyData[1]);
	movieName.erase(0, 1);
	
	Media* comedyNode = new Comedy();
	comedyNode->setTitle(movieName);
	comedyNode->setYear(year);

	Media* item = nullptr;
	comedy.retrieve(comedyNode, item);
	delete comedyNode; 
	comedyNode = nullptr; 
	return item;
}


// ---------------------------findClassic-------------------------------
// findClassic: outputs classic object searching classic BSTree
// preconditions:  file is properly formatted and classic Binary Search 
//                 Tree is not empty
// postconditions: classic object searched in classic BSTree as meeting the
//                 condition is returned 
// -------------------------------------------------------------------
Media* MediaSearch::findClassic(istream& stream, BSTree& classic) {
	int month, year;
	string actorName, actorFName, actorLName;

	stream >> month;
	stream >> year;
	stream >> actorFName;
	stream >> actorLName;
	actorName = actorFName + " " + actorLName;

	Classic* classicNode = new Classic(actorName, month);
	classicNode->setYear(year);
	
	Media* item = nullptr;
	classic.retrieve(classicNode, item);
	delete classicNode;
	classicNode = nullptr;
	return item;
}


// ---------------------------findDrama-------------------------------
// findDrama: outputs drama object searching drama BSTree
// preconditions:  file is properly formatted and drama Binary Search 
//                 Tree is not empty
// postconditions: drama object searched in drama BSTree as meeting the
//                 condition is returned 
// -------------------------------------------------------------------
Media* MediaSearch::findDrama(istream& stream, BSTree& drama) {
	string directorName, movieName, sentence, token;
	getline(stream, sentence);
	stringstream ss(sentence);
	vector<string> dramaData;
	int commaCount = 0;
	while (getline(ss, token, ',') && commaCount != 2) {
		if (token != "") {
			dramaData.push_back(token);
			commaCount++;
		}
	}

	directorName = dramaData[0];
	movieName = dramaData[1];
	directorName.erase(0, 1);
	movieName.erase(0, 1);

	Media* dramaNode = new Drama();
	dramaNode->setDirector(directorName);
	dramaNode->setTitle(movieName);

	Media* item = nullptr;
	drama.retrieve(dramaNode, item);
	delete dramaNode;           
	dramaNode = nullptr;
	return item;
}
